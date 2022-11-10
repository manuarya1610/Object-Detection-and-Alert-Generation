#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <QInputDialog>
#include <QFileDialog>
#include <fstream>
#include <QtCore>
#include <QDebug>
#include <QUrl>

using namespace cv;
using namespace std;
using namespace dnn;

Mat frame;
int  c = 1;
int delay = 5;
int frame_width;
int frame_height;
char filename[100]; // For filename
string save_path = "";
String object_detected;
QString local_media ="";

const vector<Scalar> colors = {Scalar(255, 255, 0),
                               Scalar(0, 255, 0),
                               Scalar(0, 255, 255),
                               Scalar(255, 0, 0)
                              };
const float CONFIDENCE_THRESHOLD = 0.4;
const float SCORE_THRESHOLD = 0.2;
const float INPUT_HEIGHT = 640.0;
const float NMS_THRESHOLD = 0.40;
const float INPUT_WIDTH = 640.0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->pushButton_2->setVisible(false);
        this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
        ui->graphicsView->setScene(new QGraphicsScene(this));
        ui->graphicsView->scene()->addItem(&pixmap);
        m_manager = new QNetworkAccessManager(this);
        connect(m_manager, &QNetworkAccessManager::finished, this, &::MainWindow::uploadFinished);
    }

void MainWindow::mousePressEvent(QMouseEvent *event) { //for dragging a frameless window
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) { //for dragging a frameless window
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

vector<string> load_class_list(){
    vector<string> class_list;
    ifstream ifs("D:/OneDrive - DIT University/Personal/Projects/MyEdit(DRDO)/Code/Algorithm/coco.names");
//    ifstream ifs((QCoreApplication::applicationDirPath() + "/Algorithm/coco.names").toStdString().c_str());

    string line;
    while (getline(ifs, line))
        class_list.push_back(line);
    return class_list;
}

void load_net(Net &net, bool is_cuda){
    auto result = readNet("D:/OneDrive - DIT University/Personal/Projects/MyEdit(DRDO)/Code/Algorithm/yolov5s.onnx");

//    auto result = readNet((QCoreApplication::applicationDirPath() + "/Algorithm/yolov5s.onnx").toStdString().c_str());

    if (is_cuda){
//        cout << "Attempting to use CUDA\n";
        result.setPreferableBackend(DNN_BACKEND_CUDA);
        result.setPreferableTarget(DNN_TARGET_CUDA_FP16);
    }
    else{
//        cout << "Running on CPU\n";
        result.setPreferableBackend(DNN_BACKEND_OPENCV);
        result.setPreferableTarget(DNN_TARGET_CPU);
    }
    net = result;
}

struct Detection{
    int class_id;
    float confidence;
    Rect box;
};

Mat format_yolov5(const Mat &source){
    int col = source.cols;
    int row = source.rows;
    int _max = MAX(col, row);
    Mat result = Mat::zeros(_max, _max, CV_8UC3);
    source.copyTo(result(Rect(0, 0, col, row)));
    return result;
}

void detect(Mat &image, Net &net, vector<Detection> &output, const vector<string> &className){
    Mat blob;

    auto input_image = format_yolov5(image);

    blobFromImage(input_image, blob, 1./255., Size(INPUT_WIDTH, INPUT_HEIGHT), Scalar(), true, false);
    net.setInput(blob);
    vector<Mat> outputs;
    net.forward(outputs, net.getUnconnectedOutLayersNames());

    float x_factor = input_image.cols / INPUT_WIDTH;
    float y_factor = input_image.rows / INPUT_HEIGHT;

    float *data = (float *)outputs[0].data;

//    const int dimensions = 85;
    const int rows = 25200;

    vector<int> class_ids;
    vector<float> confidences;
    vector<Rect> boxes;

    for (int i = 0; i < rows; ++i){
        float confidence = data[4];
        if (confidence >= CONFIDENCE_THRESHOLD){
            float * classes_scores = data + 5;
            Mat scores(1, className.size(), CV_32FC1, classes_scores);
            Point class_id;
            double max_class_score;
            minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
            if (max_class_score > SCORE_THRESHOLD){
                confidences.push_back(confidence);

                class_ids.push_back(class_id.x);

                float x = data[0];
                float y = data[1];
                float w = data[2];
                float h = data[3];
                int left = int((x - 0.5 * w) * x_factor);
                int top = int((y - 0.5 * h) * y_factor);
                int width = int(w * x_factor);
                int height = int(h * y_factor);
                boxes.push_back(Rect(left, top, width, height));                
            }
        }
        data += 85;
    }

    vector<int> nms_result;
    NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
    for (int i = 0; i < nms_result.size(); i++){
        int idx = nms_result[i];
        Detection result;
        result.class_id = class_ids[idx];
        result.confidence = confidences[idx];
        result.box = boxes[idx];
        output.push_back(result);
    }
}


void MainWindow::on_start_button_pressed(){
    if(ui->start_button->text() == "Stop"){
        video.release();
        pixmap.hide();
        ui -> start_button -> setVisible(false);
        ui -> pushButton_2 -> setVisible(true);
        ui -> lineEdit -> setText("");
        ui->start_button->setText("Start");
        return;
    }

    if(ui->screenShot_checkBox->isChecked()){
        QMessageBox::critical(this,
                              "Specify Path",
                              "Specify Path to save screenshots and FTP Url!");
        return;
    }

    if(!video.open(ui->lineEdit->text().trimmed().toStdString())){
        QMessageBox::critical(this,
                              "Video Error",
                              "Make sure you entered a correct and supported video file path,"
                              "<br>or a correct RTSP feed URL!");
        return;
    }

    ui->start_button->setText("Stop");

    String filter1 = " ",filter2= " ",filter3 = " ",filter4 = " ",filter5 = " ";

    if(ui -> filter_person -> isChecked())
        filter1 = "person";
    else
        filter1 = " ";

    if(ui -> filter_truck -> isChecked())
        filter2 = "truck";
    else
        filter2 = " ";

    if(ui -> filter_car -> isChecked())
        filter3 = "car";
    else
        filter3 = " ";

    if(ui -> filter_motorbike -> isChecked())
        filter4 = "motorbike";
    else
        filter4 = " ";

    if(ui -> filter_boat -> isChecked())
        filter5 = "boat";
    else
        filter5 = " ";

    QString URL = ui->lineEdit->text();
    string RTSP_URL = URL.toStdString();

    #if WIN32
        _putenv_s("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;udp");
    #else
        setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "rtsp_transport;udp", 1);
    #endif

    pixmap.show();

//    cout << "Stream is loading.........\n\n";

    vector<string> class_list = load_class_list();   

    VideoCapture capture(RTSP_URL, CAP_ANY);

    frame_width = static_cast<int>(capture.get(3));  //getting width
    frame_height = static_cast<int>(capture.get(4));  //getting height

       if (!capture.isOpened())
           cerr << "Error opening video file\n";

       bool is_cuda = 0;

       if(ui->comboBox->currentText() == "GPU")
          is_cuda = 1;

       Net net;
       load_net(net, is_cuda);

       auto start = chrono::high_resolution_clock::now();
       int frame_count = 0;
       float fps = -1;
       int total_frames = 0;


       while (true && ui->start_button->text() == "Stop"){
           capture.read(frame);

           if (frame.empty()){
//               cout << "End of stream\n";
               break;
           }

           vector<Detection> output;
           detect(frame, net, output, class_list);

           frame_count++;
           total_frames++;

           int detections = output.size();
                for (int i = 0; i < detections; ++i){
                    auto detection = output[i];
                    auto box = detection.box;
                    auto classId = detection.class_id;

                    if(filter1 == " " && filter2 == " " && filter3 == " " && filter4 == " " && filter5 == " "){
                        object_detected = class_list[classId];
                        const auto color = colors[classId % colors.size()];
                        rectangle(frame, box, color, 3);
                        rectangle(frame, Point(box.x, box.y - 20), Point(box.x + box.width, box.y), color, FILLED);
                        putText(frame, class_list[classId].c_str(), Point(box.x, box.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0));
                        if(ui->screenShot_checkBox->isChecked()){
                        if(i == 0){
                            ++delay;
                            if( (delay%5) == 0 ){
                                on_screenshot_clicked();
                                if((ui->TCP_checkBox->isChecked()))
                                    Connect();
                                if((ui->FTP_checkBox->isChecked()))
                                    on_uploadButton_clicked();
                            }
                        }
                    }
                }
                    else if ( (filter1 != " " || filter2!= " " || filter3 != " " || filter4 != " " || filter5 != " ")
                              && (class_list[classId] == filter1 || class_list[classId] == filter2 || class_list[classId] == filter3
                                  || class_list[classId] == filter4 || class_list[classId] == filter5))
                    {
                        object_detected = class_list[classId];
                        const auto color = colors[classId % colors.size()];
                        rectangle(frame, box, color, 3);
                        rectangle(frame, Point(box.x, box.y - 20), Point(box.x + box.width, box.y), color, FILLED);
                        putText(frame, class_list[classId].c_str(), Point(box.x, box.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0));
                        if(ui->screenShot_checkBox->isChecked()){
                            if(i == 0){
                                ++delay;
                                if( (delay%5) == 0 ){
                                    on_screenshot_clicked();
                                    if((ui->TCP_checkBox->isChecked())){
                                        Connect();
                                    }
                                    if((ui->FTP_checkBox->isChecked())){
                                        on_uploadButton_clicked();
                                    }
                                }
                            }
                        }
                    }
                    else 
                        break;
                }

           if (frame_count >= 30){
               auto end = chrono::high_resolution_clock::now();
               fps = frame_count * 1000.0 / chrono::duration_cast<chrono::milliseconds>(end - start).count();
               frame_count = 0;
               start = chrono::high_resolution_clock::now();
           }

           if (fps > 0){
               ostringstream fps_label;
               fps_label << fixed << setprecision(2);
               fps_label << "FPS: " << fps;
               string fps_label_str = fps_label.str();
               putText(frame, fps_label_str.c_str(), Point(10, 25), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
           }

           if(!frame.empty()){
               QImage qimg(frame.data,
                           frame.cols,
                           frame.rows,
                           frame.step,
               QImage::Format_RGB888);
               pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
               ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
           }
           qApp->processEvents();
       }
//       cout << "Total frames: " << total_frames << "\n";
}

void MainWindow::on_screenshot_clicked(){
    if(ui->screenShot_checkBox->isChecked()){
        waitKey(10);
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
        string datetime = formattedTime.toStdString();

        if(video.isOpened()){
            save_path = ((ui->fileNameLineEdit->text()).toStdString() +"/Screenshot_" + to_string(c)+ ".jpg");
            sprintf_s(filename, save_path.c_str()); //Saving the screenshot with name
            waitKey(10);
            putText(frame, datetime.c_str(), Point(50,50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
            imwrite(filename, frame);
            m_fileName =  save_path.c_str();
            c++;
        }
    }
    else
    {
        QMessageBox::critical(this,
                              "Button Disabled",
                              "Check the screenshot check box and Specify Path to save screenshots and FTP Url!");
    }
}

void MainWindow::on_selectFileButton_clicked(){
    m_fileName = QFileDialog::getExistingDirectory();
    ui->fileNameLineEdit->setText((m_fileName));
}

void MainWindow::on_uploadButton_clicked(){
    m_file = new QFile(m_fileName);

//     Next, you need information about the file name
//     The upload path to the server should look like this
//     ftp://example.com/path/to/file/filename.txt
//     That is, we specify the protocol -> ftp
//     Server -> example.com
//     The path where the file will be located -> path/to/file/
//     And the name of the file itself, which we take from QFileInfo -> filename.txt

    QFileInfo fileInfo(*m_file);
    QUrl url = (ui->uploadUrlLineEdit->text() + fileInfo.fileName());
    url.setUserName("admin");    // Set login
    url.setPassword("admin"); // Set Password
    url.setPort(21);             // Protocol port, which we will work on

    if (m_file->open(QIODevice::ReadOnly))
    {
        // Start upload
        QNetworkReply *reply = m_manager->put(QNetworkRequest(url), m_file);
        // And connect to the progress upload signal
        connect(reply, &QNetworkReply::uploadProgress, this, &MainWindow::uploadProgress);
    }
}

void MainWindow::uploadFinished(QNetworkReply *reply){
    // If the upload was successful without errors
    if (!reply->error()){
        m_file->close();
        m_file->deleteLater();  // delete object of file
        reply->deleteLater();   // delete object of reply
    }
}

void MainWindow::uploadProgress(qint64 bytesSent, qint64 bytesTotal){
    // Display the progress of the upload
    ui->progressBar->setValue(100 * bytesSent/bytesTotal);
}

void MainWindow::closeEvent(QCloseEvent *event){
    destroyAllWindows();
    video.release();
    event->accept();
    exit(0);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_source_comboBox_activated(int index){
    switch (index){
        case 0:
                ui -> lineEdit -> setText("");
                ui -> lineEdit -> setVisible(true);
                ui -> lineEdit -> setReadOnly(false);
                ui -> start_button -> setVisible(true);
                ui -> pushButton_2 -> setVisible(false);
                ui -> lineEdit -> setPlaceholderText("Enter RTSP URL");
                break;

        case 1:
                ui -> lineEdit -> setText("");
                ui -> lineEdit -> setVisible(true);
                ui -> lineEdit -> setReadOnly(true);
                ui -> pushButton_2 -> setVisible(true);
                ui -> start_button -> setVisible(false);
                ui -> lineEdit -> setPlaceholderText("Select your Video");
                break;

        case 2:
                ui -> lineEdit -> setText("");
                ui -> lineEdit -> setVisible(true);
                ui -> lineEdit -> setReadOnly(true);
                ui -> pushButton_2 -> setVisible(true);
                ui -> start_button -> setVisible(false);
                ui -> lineEdit -> setPlaceholderText("Select your Image");
                break;

        case 3:
                ui -> lineEdit -> setVisible(false);
                ui -> pushButton_2 -> setVisible(false);
                ui -> start_button -> setVisible(true);
                break;
    }
}


void MainWindow::on_pushButton_2_clicked(){
    if(ui -> source_comboBox -> currentText() == "Video")
    {
        QString file_filter = "Media File (*.MP4 *.MOV *.MKV *.WMV *AVI *FLV *AVCHD *WebM)";
        local_media = QFileDialog::getOpenFileName(this,"Open a file","C://",file_filter);
        if(!(local_media == ""))
        {
            ui -> pushButton_2 -> setVisible(false);
            ui -> start_button -> setVisible(true);
        }
        ui -> lineEdit -> setText(local_media);
    }

    if(ui -> source_comboBox -> currentText() == "Image")
    {
        QString file_filter = "Image File (*.JPEG *.GIF *.PNG *.RAW *.JPG )";
        local_media = QFileDialog::getOpenFileName(this,"Open a file","C://",file_filter);
        if(!(local_media == ""))
        {
            ui -> pushButton_2 -> setVisible(false);
            ui -> start_button -> setVisible(true);
        }
        ui -> lineEdit -> setText(local_media);
    }
}

void MainWindow::Connect(){
    socket = new QTcpSocket(this);
    socket -> connectToHost("127.0.0.1",80);
    if(socket->waitForConnected(3000)){
//        cout << "Connected";
        socket -> write("Object Detected");
        socket -> write("\n");
        socket -> write("Classification: ");
        socket -> write(object_detected.c_str());
        socket -> write("\n");
        socket -> close();
    }
    else{
//        cout << "Not Connected";
    }
}

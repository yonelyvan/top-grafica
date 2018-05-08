#include "mainwindow.h"
#include "ui_mainwindow.h"
//extras
#include <iostream>
using namespace std;

//	g++ histograma.cpp -o m `pkg-config --cflags --libs opencv`
//	./m img.jpg
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <highgui.h>
using namespace cv;
using namespace std;

QImage MatToQImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        //qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
} // MatToQImage()



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    /* aqui carga la dirreccion y manda levantar*/
    //QImage image( "/home/n/Desktop/postpro/project/imgs/img.jpg");
    //ui->label_img->setPixmap(QPixmap::fromImage( image ));


    //opencv
    //Mat Mimg = imread("/home/n/Desktop/postpro/project/imgs/img.jpg");
    //QImage img((uchar*)Mimg.data, Mimg.cols, Mimg.rows, QImage::Format_RGB32);
    //ui->label_img->setPixmap(QPixmap::fromImage(img));
    //imshow("img_name", img);
    //waitKey();

    Mat Mimg = imread("/home/n/Desktop/postpro/project/imgs/img.jpg");
    QImage image = MatToQImage(Mimg);
    ui->label_img->setPixmap(QPixmap::fromImage(image));

    //Mat img;
    //img = imread("/home/n/Desktop/postpro/project/imgs/img.jpg");
    //QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); //Converts the CV image into Qt standard format
    //ui->label_img->setPixmap(QPixmap::fromImage(imdisplay));//display the image in label that is created earlier
}

MainWindow::~MainWindow(){
    delete ui;
}


Mat brillo(Mat image, int value){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image.at<Vec3b>(y,x)[c] + value );
            }
        }
    }
    return new_image;

}

Mat contraste(Mat image, int value){
    float val = ((value*2.0)/100.0);//0.0-2.0
    float beta = 50-value;

    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image.at<Vec3b>(y,x)[c] * val)+beta );
            }
        }
    }
    return new_image;

}



void MainWindow::on_horizontalSlider_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread("/home/n/Desktop/postpro/project/imgs/img.jpg");
    Mat Mimg2 = brillo(Mimg ,position);
    QImage image = MatToQImage(Mimg2);
    ui->label_img->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread("/home/n/Desktop/postpro/project/imgs/img.jpg");
    Mat Mimg2 = contraste(Mimg ,position);
    QImage image = MatToQImage(Mimg2);
    ui->label_img->setPixmap(QPixmap::fromImage(image));
}

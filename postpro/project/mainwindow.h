#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QWidget>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    string path_img="/home/u/Desktop/postpro/top-grafica/postpro/project/imgs/img.jpg";//PC
   // string path_img="/home/n/Desktop/grafica/top-grafica/postpro/project/imgs/img.jpg";//le
    //string path_img="/home/u/Desktop/postpro/top-grafica/postpro/project/imgs/img.jpg";//cs
    vvi histograma_RGB;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_actionAbrir_triggered(QString rutaImagen="");
    void actualizar_vista(Mat Mimg);

    void on_hs_equalize_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void restart_interfaz();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_convR_sliderMoved(int position);

    void on_horizontalSlider_convG_sliderMoved(int position);

    void on_horizontalSlider_convB_sliderMoved(int position);
    void escala_grises(int r,int g, int b);

    void on_horizontalSlider_conv_CR_sliderMoved(int position);

    void on_horizontalSlider_conv_CG_sliderMoved(int position);

    void on_horizontalSlider_conv_CB_sliderMoved(int position);
    void transformaciones_color(int R, int G, int B);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

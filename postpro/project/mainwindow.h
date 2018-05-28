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




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    string path_img="/home/u/Desktop/postpro/top-grafica/postpro/project/imgs/img.jpg";

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_actionAbrir_triggered(QString rutaImagen="");
    void actualizar_vista(Mat Mimg);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

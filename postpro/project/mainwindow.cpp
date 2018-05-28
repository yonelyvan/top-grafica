#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funciones.cpp"
//	g++ histograma.cpp -o m `pkg-config --cflags --libs opencv`
//	./m img.jpg


//#include <highgui.h>
using namespace cv;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    Mat Mimg = imread(path_img);
    actualizar_vista(Mimg);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_horizontalSlider_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = brillo(Mimg ,position);
    actualizar_vista(Mimg2);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = contraste(Mimg ,position);
    actualizar_vista(Mimg2);
}

void MainWindow::on_actionAbrir_triggered(QString rutaImagen ){//Abrir ruta y seleccionar tipo de imagen
    rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images (*.png *.xpm *.jpg)"));
    path_img = rutaImagen.toUtf8().constData();

    Mat Mimg = imread(path_img);
    actualizar_vista(Mimg);
}

void MainWindow::actualizar_vista(Mat Mimg){
    QImage image = MatToQImage(Mimg);
    ui->label_img->setPixmap(QPixmap::fromImage(image));

    Mat img = get_histograma(Mimg);
    QImage hist = MatToQImage(img);
    ui->label_histogram->setPixmap(QPixmap::fromImage(hist));//histograma
}



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
    /*precalcular histograma*/
    histograma_RGB = get__vector_histograma(Mimg);
}

MainWindow::~MainWindow(){
    delete ui;
}

//brillo
void MainWindow::on_horizontalSlider_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = brillo(Mimg ,position);
    actualizar_vista(Mimg2);
}

//contraste
void MainWindow::on_horizontalSlider_2_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = contraste(Mimg ,position);
    actualizar_vista(Mimg2);
}
//ecualizar
void MainWindow::on_hs_equalize_sliderMoved(int position){
    cout<<position<<endl;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = equalize(Mimg ,histograma_RGB,position);
    actualizar_vista(Mimg2);
}




//cargar imagen
void MainWindow::on_actionAbrir_triggered(QString rutaImagen ){//Abrir ruta y seleccionar tipo de imagen
    rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images (*.png *.xpm *.jpg)"));
    path_img = rutaImagen.toUtf8().constData();

    Mat Mimg = imread(path_img);
    actualizar_vista(Mimg);
}

//actualizar vista {histograma, imagen}
void MainWindow::actualizar_vista(Mat Mimg){
    QImage image = MatToQImage(Mimg);
    ui->label_img->setPixmap(QPixmap::fromImage(image));

    Mat img = get_histograma(Mimg);
    QImage hist = MatToQImage(img);
    ui->label_histogram->setPixmap(QPixmap::fromImage(hist));//histograma
}






void MainWindow::on_pushButton_clicked(){
    restart_interfaz();
}

void MainWindow::on_pushButton_2_clicked(){
    restart_interfaz();
}

void MainWindow::restart_interfaz(){
    Mat Mimg = imread(path_img);
    actualizar_vista(Mimg);
    ui->horizontalSlider_convR->setValue(50);
    ui->horizontalSlider_convG->setValue(50);
    ui->horizontalSlider_convB->setValue(50);

    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(50);
    ui->hs_equalize->setValue(0);

    ui->horizontalSlider_conv_CR->setValue(50);
    ui->horizontalSlider_conv_CG->setValue(50);
    ui->horizontalSlider_conv_CB->setValue(50);
}


void MainWindow::on_pushButton_3_clicked(){
    Mat Mimg = imread(path_img);
    Mat Mimg2 = convertir(Mimg ,1);
    actualizar_vista(Mimg2);
}


void MainWindow::on_horizontalSlider_convR_sliderMoved(int position){
    int r= position;
    int g= ui->horizontalSlider_convG->value();
    int b= ui->horizontalSlider_convB->value();
    escala_grises(r,g,b);
}

void MainWindow::on_horizontalSlider_convG_sliderMoved(int position){
    int r=ui->horizontalSlider_convR->value();
    int g=position;
    int b=ui->horizontalSlider_convB->value();
    escala_grises(r,g,b);
}

void MainWindow::on_horizontalSlider_convB_sliderMoved(int position){
    int r=ui->horizontalSlider_convR->value();
    int g=ui->horizontalSlider_convG->value();
    int b=position;
    escala_grises(r,g,b);
}

void MainWindow::escala_grises(int r,int g, int b){
    cout<<"R "<<r<<" G "<<g<<" B "<<b<<endl;
    vf values_rgb(3);
    values_rgb[0]=b/100.0;
    values_rgb[1]=g/100.0;
    values_rgb[2]=r/100.0;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = convertir_rgb(Mimg,values_rgb);

    actualizar_vista(Mimg2);
}
//transformar color
//trasformar_color







void MainWindow::on_horizontalSlider_conv_CR_sliderMoved(int position){
    int R=ui->horizontalSlider_conv_CR->value();
    int G=ui->horizontalSlider_conv_CG->value();
    int B=ui->horizontalSlider_conv_CB->value();
    transformaciones_color(R,G,B);
}

void MainWindow::on_horizontalSlider_conv_CG_sliderMoved(int position){
    int R=ui->horizontalSlider_conv_CR->value();
    int G=ui->horizontalSlider_conv_CG->value();
    int B=ui->horizontalSlider_conv_CB->value();
    transformaciones_color(R,G,B);
}

void MainWindow::on_horizontalSlider_conv_CB_sliderMoved(int position){
    int R=ui->horizontalSlider_conv_CR->value();
    int G=ui->horizontalSlider_conv_CG->value();
    int B=ui->horizontalSlider_conv_CB->value();
    transformaciones_color(R,G,B);
}

void MainWindow::transformaciones_color(int R, int G, int B){
    vf values_rgb(3);
    values_rgb[0]=B/100.0;
    values_rgb[1]=G/100.0;
    values_rgb[2]=R/100.0;
    Mat Mimg = imread(path_img);
    Mat Mimg2 = trasformar_color(Mimg,values_rgb);

    actualizar_vista(Mimg2);
}

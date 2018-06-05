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
    M_img = imread(path_img);
    M_img_temp = M_img;
    actualizar_vista(M_img);
    /*precalcular histograma*/
    histograma_RGB = get__vector_histograma(M_img);
}

MainWindow::~MainWindow(){
    delete ui;
}

//brillo
void MainWindow::on_horizontalSlider_sliderMoved(int position){
    if(flag != "brillo"){
        M_img = M_img_temp;
        flag  = "brillo";
    }
    M_img_temp = brillo(M_img ,position);
    actualizar_vista(M_img_temp);
}

//contraste
void MainWindow::on_horizontalSlider_2_sliderMoved(int position){
    if(flag != "contraste"){
        M_img = M_img_temp;
        flag  = "contraste";
    }
    M_img_temp = contraste(M_img ,position);
    actualizar_vista(M_img_temp);
}
//ecualizar
void MainWindow::on_hs_equalize_sliderMoved(int position){
    if(flag != "ecualizar"){
        M_img = M_img_temp;
        flag  = "ecualizar";
        histograma_RGB = get__vector_histograma(M_img);
    }
    M_img_temp = equalize(M_img ,histograma_RGB,position);
    actualizar_vista(M_img_temp);
}




//cargar imagen
void MainWindow::on_actionAbrir_triggered(QString rutaImagen ){//Abrir ruta y seleccionar tipo de imagen
    rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images (*.png *.xpm *.jpg)"));
    path_img = rutaImagen.toUtf8().constData();

    M_img = imread(path_img);
    M_img_temp = M_img;
    actualizar_vista(M_img);
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
    M_img = imread(path_img);
    M_img_temp = M_img;
    actualizar_vista(M_img);
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
    //Mat Mimg = imread(path_img);
    if(flag != "gris1"){
        M_img = M_img_temp;
        flag  = "gris1";
    }
    M_img_temp = convertir(M_img ,1);
    actualizar_vista(M_img_temp);
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
    //Mat Mimg = imread(path_img);
    if(flag != "gris2"){
        M_img = M_img_temp;
        flag  = "gris2";
    }
    M_img_temp = convertir_rgb(M_img,values_rgb);
    actualizar_vista(M_img_temp);
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
    //Mat Mimg = imread(path_img);
    if(flag != "color1"){
        M_img = M_img_temp;
        flag  = "color1";
    }
    M_img_temp = trasformar_color(M_img,values_rgb);
    actualizar_vista(M_img_temp);
}
/////////////////////////////imagenes A B
//cargar imagen A
void MainWindow::on_pushButton_4_clicked(){
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images (*.png *.xpm *.jpg)"));
    ruta_img_A = rutaImagen.toUtf8().constData();
    M_img_A = imread(ruta_img_A);
    QImage image = MatToQImage(M_img_A);
    ui->label_img_A->setPixmap(QPixmap::fromImage(image));
}

//cargar imagen B
void MainWindow::on_pushButton_5_clicked(){
    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
    tr("Images (*.png *.xpm *.jpg)"));
    ruta_img_B = rutaImagen.toUtf8().constData();
    M_img_B = imread(ruta_img_B);
    QImage image = MatToQImage(M_img_B);
    ui->label_img_B->setPixmap(QPixmap::fromImage(image));
}



//tab 2 cargar imagenes por defecto
void MainWindow::on_tabWidget_2_tabBarClicked(int index){
    if(index==1){
        M_img_A = imread(ruta_img_A);
        QImage A = MatToQImage(M_img_A);
        ui->label_img_A->setPixmap(QPixmap::fromImage(A));

        M_img_B = imread(ruta_img_B);
        QImage B = MatToQImage(M_img_B);
        ui->label_img_B->setPixmap(QPixmap::fromImage(B));
    }
}

//suma A B
void MainWindow::on_pushButton_6_clicked(){
    Mat R = suma_AB(M_img_A,M_img_B);
    QImage image = MatToQImage(R);
    ui->label_result_AB->setPixmap(QPixmap::fromImage(image));
}

//resta A B
void MainWindow::on_pushButton_7_clicked(){
    Mat R = resta_AB(M_img_A,M_img_B);
    QImage image = MatToQImage(R);
    ui->label_result_AB->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_pushButton_8_clicked(){
    Mat R = suma_AB2(M_img_A,M_img_B);
    QImage image = MatToQImage(R);
    ui->label_result_AB->setPixmap(QPixmap::fromImage(image));
}
//suma a*A + (1-a)*B
void MainWindow::on_horizontalSlider_3_sliderMoved(int position){
    float a = position/10.0;
    Mat R = suma_AB_a(M_img_A, M_img_B, a);
    QImage image = MatToQImage(R);
    ui->label_result_AB->setPixmap(QPixmap::fromImage(image));

}

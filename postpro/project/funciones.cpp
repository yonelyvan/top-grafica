#include <bits/stdc++.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//hist
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
#define see(X) cout<<#X<<" "<<X<<endl;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<float> vf;
typedef vector<vf> vvf;


//suma y resta //brillo
Mat brillo(Mat &image, int value){
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


//multiplicacion divicion
Mat contraste(Mat &image, int value){
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





vvi get__vector_histograma(Mat &image){
    vvi hist_RGB(3);
    hist_RGB[0].resize(256);
    hist_RGB[1].resize(256);
    hist_RGB[2].resize(256);
    int val_color;
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for (int c = 0; c < 3; ++c) {
               val_color = image.at<Vec3b>(y,x)[c];
               ++hist_RGB[c][val_color];
            }
        }
    }
    return hist_RGB;
}


//ecualizacion
Mat equalize(Mat &image, vvi hist_RGB, int value){
    //maximos por canal del histograma RGB
    vi max_values_RGB(3);
    for (int c = 0; c < 3; ++c) {
        for (int i = 0; i < 256; ++i) {
            max_values_RGB[c] = max(max_values_RGB[c], hist_RGB[c][i]);
        }
    }
    see("mejores")
    see(max_values_RGB[0]);
    see(max_values_RGB[1]);
    see(max_values_RGB[2]);

    //value porcentajes
    vi val_RGB(3);
    for (int c = 0; c < 3; ++c) {
        val_RGB[c] = (max_values_RGB[c]*value)/100;
    }
    //calcular poscion min m, max M
    vi m_rgb(3), flag_m_rgb(3,1);
    vi M_rgb(3), flag_M_rgb(3,1);
    for (int c = 0; c < 3; ++c) {
        for (int i = 0; i < 255; ++i) {
            if( hist_RGB[c][i] > val_RGB[c] && flag_m_rgb[c] ){//mayor que el %
                m_rgb[c]=i;
                flag_m_rgb[c]=0;
            }
            if( hist_RGB[c][255-i] > val_RGB[c] && flag_M_rgb[c] ){//mayor que el %
                M_rgb[c]=255-i;
                flag_M_rgb[c]=0;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        see(m_rgb[i]);
        see(M_rgb[i]);
    }
    //contruir imagen
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image.at<Vec3b>(y,x)[c]-m_rgb[c])*(255/(M_rgb[c]-m_rgb[c]) ) );
            }
        }
    }
    return new_image;
}




//colores
Mat convertir(Mat &image, int value){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            int temp=0;
            for( int c = 0; c < 3; c++ ){
                temp+=image.at<Vec3b>(y,x)[c];
            }
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( temp/3 );
            }
        }
    }
    return new_image;
}




Mat convertir_rgb(Mat &image, vf values_rgb){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            int temp=0;
            for( int c = 0; c < 3; c++ ){
                temp+=image.at<Vec3b>(y,x)[c]*values_rgb[c];
            }
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( temp );
            }
        }
    }
    return new_image;
}

//transformaciones de color

Mat trasformar_color(Mat &image, vf values_rgb){
    Mat new_image = Mat::zeros( image.size(), image.type() );
    for( int y = 0; y < image.rows; y++ ){
        for( int x = 0; x < image.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image.at<Vec3b>(y,x)[c] * values_rgb[c]);
            }
        }
    }
    return new_image;
}


//imagenes A B
Mat suma_AB(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image_A.at<Vec3b>(y,x)[c] + image_B.at<Vec3b>(y,x)[c]);
            }
        }
    }
   return new_image;
}

Mat resta_AB(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( image_A.at<Vec3b>(y,x)[c] - image_B.at<Vec3b>(y,x)[c]);
            }
        }
    }
   return new_image;
}

//suma A+B/2
Mat suma_AB2(Mat &image_A, Mat &image_B){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (image_A.at<Vec3b>(y,x)[c] + image_B.at<Vec3b>(y,x)[c])/2 );
            }
        }
    }
   return new_image;
}

//suma a*A + (1-a)*B
Mat suma_AB_a(Mat &image_A, Mat &image_B, float a){
    Mat new_image = Mat::zeros( image_A.size(), image_A.type() );
    for( int y = 0; y < image_A.rows; y++ ){
        for( int x = 0; x < image_A.cols; x++ ){
            for( int c = 0; c < 3; c++ ){
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( a*(image_A.at<Vec3b>(y,x)[c]) + (1.0-a)*(image_B.at<Vec3b>(y,x)[c]) );
            }
        }
    }
   return new_image;
}

//convoluciones
int ker[3][3]={{0, -1, 0},
                  {-1, 5, -1},
                  {0, -1, 0}};


vvi get_kernel(){
    vvi kernel;
    kernel.resize(3);
    for (int i = 0; i < 3; ++i){
        kernel[i].resize(3);
        for (int j = 0; j < 3; ++j){
            kernel[i][j] = ker[i][j];
        }
    }
    return kernel;
}

vvf read_kernel(string file){
    vvf kernel;
    int f,c;
    ifstream F(file);
    F>> f >> c;
    float val;
    kernel.resize(f);
    for (int i = 0; i < f; ++i){
        kernel[i].resize(c);
        for (int j = 0; j < c; ++j){
            F>> kernel[i][j];
        }
    }
    return kernel;
}


float aplicar_kernel(Mat &image, vvf kernel, int x, int y, int c){
    int d = kernel.size()/2;
    int lim_x = x-d;
    int lim_y = y-d;
    int img_ij;
    float s=0;
    for (int i = 0; i < kernel.size(); ++i) {
        for (int j = 0; j < kernel[i].size(); ++j) {
            img_ij = image.at<Vec3b>(lim_x+i, lim_y+j)[c];
            s += img_ij*kernel[i][j];
        }
    }
    return s;
}

Mat convolucion(Mat &image, string file ){
    //get kernel from file
    vvf kernel = read_kernel(file);
    Mat new_image = Mat::zeros( image.size(), image.type() );
    int d = kernel.size()/2;
    int R = image.rows;
    int C = image.cols;
    //new_image = image;
    for( int y = d; y < C-d; y++ ){
        for( int x = d; x < R-d; x++ ){
            for( int c = 0; c < 3; c++ ){
                float r = aplicar_kernel(image, kernel, x,y,c);
                new_image.at<Vec3b>(x,y)[c] = saturate_cast<uchar>(r);
            }
        }
    }
   return new_image;
}






//##################################################
//##################################################
QImage MatToQImage(const Mat& mat){
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1){
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
    if(mat.type()==CV_8UC3){
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else{
        //qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
} // MatToQImage()


Mat get_histograma(Mat src){
    //Mat src;
    /// Load image
    //src = imread( ruta_imagen );
    //if( !src.data ){ return -1; }
    /// Separate the image in 3 places ( B, G and R )
    vector<Mat> bgr_planes;
    split( src, bgr_planes );
    /// Establish the number of bins
    int histSize = 256;
    /// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };
    bool uniform = true; bool accumulate = false;
    Mat b_hist, g_hist, r_hist;
    /// Compute the histograms:
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
    // Draw the histograms for B, G and R
    int hist_w = 512;//512;
    int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    /// Draw for each channel
    for( int i = 1; i < histSize; i++ ){
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                                             Scalar( 255, 0, 0), 2, 8, 0  );
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                                             Scalar( 0, 255, 0), 2, 8, 0  );
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                                             Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                                             Scalar( 0, 0, 255), 2, 8, 0  );
    }
    return histImage;
    // Display
    //namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
    //imshow("calcHist Demo", histImage );
    //waitKey(0);
}

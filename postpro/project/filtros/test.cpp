#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//return kernel
typedef vector<float> vf;
typedef vector< vf > vvf; 

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

void imprimir_kernel(vvf kernel){
    for (int i = 0; i < kernel.size(); ++i){
        for (int j = 0; j < kernel[i].size(); ++j){
            cout<<kernel[i][j]<<" ";
        }
        cout<<endl;
    }
}




int main(){
    vvf kernel = read_kernel("test2.conv");
    imprimir_kernel(kernel);
    return 0;     
}
#include <iostream>
#include <cmath>
using namespace std;

//Pay attention: The following code does not work well,
//Just used for undestanding the mechanism of FFT.
//Shuaixinag Zhang, Jul 28, 2022---

const int N=8;
#define PI 3.1415926

struct Signal{
    double Real = 0;
    double Image = 0;
};

Signal Sig[N];

void BitReverse(int Input[], int size){
    int r = 0;
    for(int j=0; j<N; ++j){
//	    p = 0;
	    for(int i=0; i<(log(N)/log(2)); ++i){
	        if(j & (1<<i))
		        r += 1 << ((log(N)/log(2))-i-1);
	    }
	    Sig[j].Real = Input[r];
    }
}
/*
void Butterfly_Operation(int Pre, int Next, double theta){
    double Sin_Omega = -sin(theta);
    double Cos_Omega = cos(theta);
    Signal temp[2];

    temp[0].Real = Sig[Pre].Real + Cos_Omega*Sig[Next].Real - Sin_Omega*Sig[Next].Image;
    temp[0].Image = Sig[Pre].Image + Cos_Omega*Sig[Next].Image + Sin_Omega*Sig[Next].Real;

    temp[1].Real = Sig[Pre].Real - Cos_Omega*Sig[Next].Real + Sin_Omega*Sig[Next].Image;
    temp[1].Image = Sig[Pre].Image - Cos_Omega*Sig[Next].Image - Sin_Omega*Sig[Next].Real;

    Sig[Pre].Real = temp[0].Real;
    Sig[Pre].Image = temp[0].Image;
    Sig[Next].Real = temp[1].Real;
    Sig[Next].Image = temp[1].Image;
}

void FFT2(){
    double theta=0;

    for(int i=0; i<log(N); ++i){
        for(int j=0; j<(N>>(i+1)); ++j){
            for(int k=0; k<(1<<i); ++k){
                theta = 2*PI/(1<<(i+1))*k;
                Butterfly_Operation(k + j*(1<<(i+1)), k + j*(1<<(i+1)) + (1<<i), theta);
            }
        }
    }
}
*/


int main(){
    cout<<"Log: "<<(log(N)/log(2))<<endl;
}

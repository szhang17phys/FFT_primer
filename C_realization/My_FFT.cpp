//This code is based on: 
//https://blog.csdn.net/heycwn/article/details/51202506

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

const int N = 1024;
const float PI = 3.1416;

inline void swap(float &a, float &b){
    float t;
    t = a;
    a = b;
    b = t;
}

//Bit-reversal Permutation---
void bitrp(float xreal[], float ximag[], int n){
    int i, j, a, b, p;
    for(i=1, p=0; i<n; i *=2){
        p++;
    }
    for(i=0; i<n; ++i){
        a = i;
        b = 0;
        for(j=0; j<p; ++j){
            b = (b<<1) + (a & 1);
            a >>= 1;
        }
        if(b>i){
            swap(xreal[i], xreal[b]);
            swap(ximag[i], ximag[b]);
        }
    }
}

void FFT(float xreal[], float ximag[], int n){
    float wreal[N/2], wimag[N/2], treal, timag, ureal, uimag, arg;
    int m, k, j, t, index1, index2;

    bitrp(xreal, ximag, n);

    arg = -2*PI/n;
    treal = cos(arg);
    timag = sin(arg);
    wreal[0] = 1.0;
    wimag[0] = 0.0;
    for(j=1; j<n/2; ++j){
        wreal[j] = wreal[j-1]*treal - wimag[j-1]*timag;
        wimag[j] = wreal[j-1]*timag + wimag[j-1]*treal;
    }

    for(m=2; m<=n; m*=2){
        for(k=0; k<n; k+=n){
            for(j=0; j<m/2; ++j){
                index1 = k+j;
                index2 = index1 + m/2;
                t = n*j/m;
                treal = wreal[t]*xreal[index2] - wimag[t]*ximag[index2];
                timag = wreal[t]*ximag[index2] + wimag[t]*xreal[index2];
                ureal = xreal[index1];
                uimag = ximag[index1];
                xreal[index1] = ureal + treal;
                ximag[index1] = uimag + timag;
                xreal[index2] = ureal - treal;
                ximag[index2] = uimag - timag;
            }
        }
    }
}

void FFT_test(){
/*    char inputfile = 'input.txt';
    char outputfile = 'output.txt';
    float xreal[N] = {}, ximag[N] = {};
    int n, i;
    FILE *input, *output;
*/
    int i = 0;
    int n = 0;
    float xreal[N] = {0}, ximag[N] = {0};

    ifstream input;
    ofstream output;
    input.open("./input.txt", ios::in);


/*    while(!input.eof()){
        input >> xreal[i];
        input >> ximag[i];
    
        cout<<"Real: "<<xreal[i]<<";   Image: "<<ximag[i]<<endl;

        i++;
    }
*/

    for(int k=0; k<16; ++k){
        input >> xreal[k];
        input >> ximag[k];
    
        cout<<"Real: "<<xreal[i]<<";   Image: "<<ximag[i]<<endl;

        i++;
    } 
    cout<<"The value of i: "<<i<<endl;

    n = i;

    output.open("output.txt", ios::trunc);
    cout<<"Open and create output.txt successfully!!!"<<endl;

    while(i>1){
        if(i%2){
            output<<n<<" is not a power of 2!\n";
        }
        i /= 2;
    }

    FFT(xreal, ximag, n);
    output<<"FFT:"<<endl;
    output<<"i   real    iamg\n";

    for(i=0; i<n; ++i){
        output<<i<<"    "<<xreal[i]<<"    "<<ximag[i]<<"\n";
    }
    output<<"====================="<<endl;

    input.close();
    output.close();

/*    i = 0;
    while((fscanf(input, "%f%f", xreal+i, ximag+i)) != EOF){
        i++;
    }
    n = i;
    while(i>1){
        if(i%2){
            fprintf(output, "%d is not a power of 2!\n", n);
        }
        i /= 2;
    }

    FFT(xreal, ximag, n);
    fprintf(output, "FFT:    i   real    iamg\n");
    for(i=0; i<n; ++i){
        fprintf(output, "%4d    %8.4f   %8.4f", i, xreal[i], ximag[i]);
    }
    fprintf(output, "================\n");
*/

}



int main(){
    FFT_test();
    return 0;
}
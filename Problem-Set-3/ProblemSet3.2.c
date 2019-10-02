#include <stdio.h>
#include <math.h>

int main(){
    int i;
    int nsamps;
    double samp;
    double srate;
    double pi;
    double twopi;
    double angincr;
    pi = 3.141592654;
    twopi = 2*pi;
    srate = 1000;
    nsamps = 1000;
    angincr = twopi/srate;

    for(i=0;i <= nsamps; i++){
        samp = sin(angincr*i);
        printf("Increment: %d is %.5lf\n",i,samp);
    }
    printf("Done\n");
    return 0;
}
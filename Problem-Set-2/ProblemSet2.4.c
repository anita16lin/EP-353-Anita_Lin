#include <stdio.h>

int main(){
    int bpm;
    int bps;
    int bp4n;
    int bp8n;
    int bp16n;
    bpm = 120;
    bps = 60 * 1000;
    bp4n = bps / bpm;
    bp8n = bp4n / 2;
    bp16n = bp8n / 2;
    printf("----------------------\n");
    printf("BPM: %d\n", bpm);
    printf("----------------------\n");
    printf("Delay Times in ms\n");
    printf("Quarter Note: %d ms\n", bp4n);
    printf("Eigth Note: %d ms\n", bp8n);
    printf("Sixteenth Note: %d ms\n", bp16n);
    printf("----------------------\n");
    return 0;
}
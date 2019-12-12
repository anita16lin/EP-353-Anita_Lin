#include <stdio.h>
#include <stdlib.h>

// to compile and run: $ gcc -o GG GrainGeneratorWrite.c && ./GG && csound -odac -d -O null myScore.csd
// to see how to do this without writing to a file, revisit the helloSine.c example

int main() {
 	FILE *fp;
	fp = fopen("myScore.csd", "w");

	fprintf(fp, "<CsoundSynthesizer>\n");
	fprintf(fp, "<CsInstruments>\n");
	fprintf(fp, "instr hellosine\n");
	fprintf(fp, "k1 linen 1, .2, p3, .3\n");
	fprintf(fp, "a1 oscili 10000, 200, 1\n");
	fprintf(fp, "out a1 * k1\n");
	fprintf(fp, "endin\n");
	fprintf(fp, "</CsInstruments>\n");
	fprintf(fp, "<CsScore>\n");
	fprintf(fp, "f 1  0 8192 10 1\n");
	fprintf(fp, "i \"hellosine\" 0 3\n");
	fprintf(fp, "</CsScore>\n");
	fprintf(fp, "</CsoundSynthesizer>\n");
	fprintf(fp, "\n");

	fclose(fp);

	system("csound myScore.csd -odac");

	return 0;	
}
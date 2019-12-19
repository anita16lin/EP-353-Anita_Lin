#include <stdio.h>
#include <stdlib.h>

// to compile and run: $ gcc -o GG GrainGeneratorRead.c && ./GG && csound -odac -d -O null myScore.csd


int main() {
	FILE *csd;
	csd = fopen("myScore.csd", "w");

	fprintf(csd, "<CsoundSynthesizer>\n");
	fprintf(csd, "<CsInstruments>\n");

	//as our orchestras become more complicated, it's more convenient to load them as a separate resource
	//this takes the place of a whole bunch of fprintf() statements
	FILE *orc;
	orc = fopen("final-houge.orc", "r");
	if (orc == NULL) {
		printf("can't open file\n");
		return 1;
	} else {
		int c;
		//the following works because an assignment expression has the value of the left operand after the assignment
		while((c = getc(orc)) != EOF) {
			putc(c, csd);
		}
		fclose(orc);
	}


	fprintf(csd, "\n</CsInstruments>\n");
	fprintf(csd, "<CsScore>\n");
	fprintf(csd, "f1 0 4096 10 1\n");
	fprintf(csd, "f2 0 4096 19 0.5 1 0 0\n");
	fprintf(csd, "s\n");
	//but we're still entering our instrument lines manually, which is rather tedious
	//note that the parameters here are different from the GrainGeneratorWrite.c example,
	//since we're using a different Csound orchestra
	fprintf(csd, "i102 0. 2 -12.0 200.0 1777.0 2.5 2 0.5\n");

	fprintf(csd, "</CsScore>\n");
	fprintf(csd, "</CsoundSynthesizer>\n");
	fprintf(csd, "\n");

	fclose(csd);

	system("csound myScore.csd -odac");

	return 0;	
}
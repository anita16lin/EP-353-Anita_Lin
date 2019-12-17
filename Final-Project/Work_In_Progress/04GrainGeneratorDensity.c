#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// to compile and run: $ gcc -o GG GrainGeneratorLoop.c && ./GG && csound -odac -d -O null myScore.csd


int main() {
	//seeding our random numbers with current time, so that the output will be different each time it is compiled
	srand(time(NULL));

	FILE *csd;
	csd = fopen("myScore.csd", "w");

	fprintf(csd, "<CsoundSynthesizer>\n");
	fprintf(csd, "<CsInstruments>\n");

	FILE *orc;
	//note slightly more compact syntax than GrainGeneratorRead.c
	if ((orc = fopen("final-houge.orc", "r")) == NULL) {
		printf("can't open file\n");
		return 1;
	} else {
		int c;
		while ((c = getc(orc)) != EOF)
			putc(c, csd);
		fclose(orc);
	}

	fprintf(csd, "\n</CsInstruments>\n");

	//score section

	fprintf(csd, "<CsScore>\n");
	//manually printing the function tables required by the instruments
	//(see Csound documentation for more info)
	fprintf(csd, "f1 0 4096 10 1\n");
	fprintf(csd, "f2 0 4096 19 0.5 1 0 0\n");
	fprintf(csd, "s\n");

	float maxGrainTime = 10.; //give us 10 seconds of sound
	float currentTime = 0.; //first grain at time 0.
	float density = 500; //grains per second on average; change this to hear the results
	float cToM = 3.25; //carrier to modulator ratio
	float startTime, duration, volume, carFreq, modFreq, index, pan;
	while (currentTime < maxGrainTime) {
		//calculate all of the parameters required for each grain
		//some are completely random, and some do some calculation based on x to gradally change over time
		//the common technique for generating a random value within a certain range is as follows:
		// 1) generate a random value between 0.0 and 1.0 like this: (rand() % 1000/999.)
		// 2) then multiply by your range (i.e., max value minus min value)
		// 3) then add your offset (i.e., your min value)
		duration = ((rand() % 1000)/999.) * 0.5 + 0.25; //duration between 0.25 and 0.75 seconds
		volume = ((rand() % 1000)/999.) * 12. - 42.0; //volume between -42.0 and -30.0 dB
		//here the amount of pitch variation gets bigger as the sound continues, starting with 0 and ending with +/- a quarter of an octave
		carFreq = 400 * pow(2,(((rand() % 1000)/999.) * 0.25 - 0.125) * (currentTime / maxGrainTime));
		//you could also think about how to use integer math to make sudden jumps at regular intervals in the loop, like this:
		//carFreq = 110.0 * (x / 100 + 1); 
		modFreq = carFreq / cToM; //basic FM stuff, solving for the modulator frequency by using the Carrier to Modulator ratio specified above
		//index of modulation also changes in proportion to x
		//(affecting the relative amplitude of the FM sidebands, roughly the complexity or brightness of timbre)
		index = (currentTime / maxGrainTime) * 20.0;
		//last step is that we format all of these parameters into an instrument call and print to our csd file
		//note that the start time is calculated by x * 0.01
		//so as x goes from 0 to 999, our start time will go from 0 to 9.9 seconds
		//also, our pan goes progressively from left to right (defined as 0.0 to 1.0)
		//note that 2 never changes; it is our function table (defined in the f2 statement above)
		startTime = currentTime;
		pan = currentTime / maxGrainTime;
		fprintf(csd, "i102 %f %f %f %f %f %f 2 %f\n", startTime, duration, volume, carFreq, modFreq, index, pan);
		//calculate next grain start time
		//(1 / density) changes grains per second into seconds per grain, and seconds is the unit we need
		//if we want that value to be our average density, we can choose a value between 0 and twice our average density
		//by definition, this results in an average that is our desired average
		//the following expression could be reduced, but I've left it this way to hopefully make the logic clear
		float grainInterval = ((rand() % 1000)/999.) * ((1 / density) * 2);
		currentTime += grainInterval;
	}


	fprintf(csd, "</CsScore>\n");
	fprintf(csd, "</CsoundSynthesizer>\n");

	fprintf(csd, "\n");

	fclose(csd);

	system("csound myScore.csd -odac");

	return 0;	
}
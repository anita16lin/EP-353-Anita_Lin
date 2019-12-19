#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//to compile and run: gcc -o GG 1GrainDemo_SineFMAudio.c && ./GG && csound -odac -d -O null myScore.csd

//declaring functions that will be defined below main()
float midiToFrequency(float midi);
float interpolate(float index, float envelope[][2]);
float getValueFromTendencyMask(float index, float minEnvelope[][2], float maxEnvelope[][2]);

int main() {
	//seeding our random numbers with current time, so that the output will be different each time it is compiled
	srand(time(NULL));

	//open file to write to
	FILE *csd;
	csd = fopen("myScore.csd", "w");

	fprintf(csd, "<CsoundSynthesizer>\n");
	fprintf(csd, "<CsInstruments>\n");

	//insert contents of orchestra file
	FILE *orc;
	if ((orc = fopen("final-anita.orc", "r")) == NULL) {
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
    //Function 1 uses the GEN10 subroutine to compute a sine wave
    //Function 2 uses the GEN10 subroutine to compute the first sixteen partials of a sawtooth wave
    //Function 3 uses the GEN20 subroutine to compute a Hanning window for use as a grain envelope
    //Function 4 uses the GEN01 subroutine to read in an AIF audio file
    //Function 5 uses the GEN01 subroutine to read in annother AIF audio file
    //Function 6 uses the GEN07 subroutine to compute a linear AR "GATE" envelope function
    //Function 7 uses the GEN07 subroutine to compute a linear ADSR envelope function
    //Function 8 uses the GEN05 subroutine to compute an exponential ADSR envelope function
	fprintf(csd, "f1 0 4096 10 1\n");
	fprintf(csd, "f2 0 4096 19 0.5 1 0 0\n");
	fprintf(csd, "f3 0 4097 20 2 1\n");
    fprintf(csd, "f4 0 0 1 \"sing.aif\" 0 0 0\n");
    fprintf(csd, "f5 0 0 1 \"hellorcb.aif\" 0 0 0\n");
    fprintf(csd, "f6 0 1024 7 0 10 1 1000 1 14 0\n");
    fprintf(csd, "f7 0 1024 7 0 128 1 128 .6 512 .6 256 0\n");
    fprintf(csd, "f8 0 1024 5 .01 256 1 192 .5 256 .5 64 .01\n");
    //Add your own audio file here: fprintf(csd, "f5 0 0 1 \"youraudiofile.aif\" 0 0 0\n");
    //Be sure to comment out the other f5 table. 
    fprintf(csd, "s\n");

	//you can set up a tendency mask by defining two lines that indicate an upper and lower boundary for some variable
	//these lines can be defined as a list of breakpoints (coordinates)
	//for each desired value, first interpolate the corresponding value for each line, then pick a random value between them
	//note that you must specify size of second dimension when defining a 2 dimensional array
	//this is basically the same concept as the line function in Max

	//Volume Envelope
	float minVolumeEnv[][2] = { {0., -60.},
								{0.5, -48.},
								{1., -60.},
								{-1, -1} };
	float maxVolumeEnv[][2] = { {0., -48.},
								{0.5, -12.},
								{1., -18.},
								{-1, -1} };

	//Pan Envelope
	//adhering to the convention of left = 0.0, right = 1.0
	float minPanEnv[][2] = { {0., 0.5},
								{0.4, 0.},
								{1., 0.5},
								{-1, -1} };
	float maxPanEnv[][2] = { {0., 0.5},
								{0.6, 1.},
								{1., 0.5},
								{-1, -1} };

	//Duration Envelope
	float minDurEnv[][2] = { {0., 0.001},
								{0.5, 0.01},
								{0.7, 0.25},
								{1., 0.001},
								{-1, -1} };
	float maxDurEnv[][2] = { {0., 0.002},
								{0.5, 0.02},
								{0.8, 0.5},
								{1., 0.005},
								{-1, -1} };

	//specifying pitch as MIDI values for convenience 
	//and also to make sure we get exponential as opposed to linear mapping
	//pitch for Instr 101 - Sine
	float minPitchEnv1[][2] = { {0., 86.},
								{0.5, 74.},
								{0.7, 59.},
								{0.87, 62.},
								{0.9, 62.},
								{1., 59.},
								{-1, -1} };
	float maxPitchEnv1[][2] = { {0., 96.},
								{0.5, 96.},
								{0.6, 69.},
								{0.65, 108.},
								{0.86, 72.},
								{0.915, 72.},
								{1., 69.},
								{-1, -1} };
    //pitch for Instr 102 - FM
    float minPitchEnv2[][2] = { {0., 96.},
								{0.5, 84.},
								{0.7, 69.},
								{0.87, 72.},
								{0.9, 72.},
								{1., 69.},
								{-1, -1} };
	float maxPitchEnv2[][2] = { {0., 96.},
								{0.5, 96.},
								{0.6, 69.},
								{0.65, 108.},
								{0.86, 72.},
								{0.915, 72.},
								{1., 69.},
								{-1, -1} };
	//pitch for Instr 103 - Audio File
	float minPitchEnv3[][2] = { {0., 86.},
								{0.5, 74.},
								{0.7, 59.},
								{0.87, 62.},
								{0.9, 62.},
								{1., 59.},
								{-1, -1} };
	float maxPitchEnv3[][2] = { {0., 96.},
								{0.5, 96.},
								{0.6, 69.},
								{0.65, 108.},
								{0.86, 72.},
								{0.915, 72.},
								{1., 69.},
								{-1, -1} };
	//index of modulation, determining amplitude of sidebands ("brightness") for Instr 102 - FM
	float minIOfMEnv[][2] = { {0., 0.},
								{0.4, 1.},
								{0.75, 10.},
								{0.85, 3.},
								{1., 0.},
								{-1, -1} };
	float maxIOfMEnv[][2] = { {0., 1.},
								{0.55, 2.},
								{0.65, 20.},
								{0.8, 3.},
								{0.9, 15.},
								{0.91, 1.5},
								{0.935, 4.},
								{0.95, 1.5},
								{1., 1.},
								{-1, -1} };

	//carrier to modulator ratio, determining spectrum of FM sound for Instr 102 - FM
	float minCToMEnv[][2] = { {0., 0.5},
								{0.4, 0.5},
								{0.7, 10.},
								{0.725, 0.1},
								{0.875, 5.},
								{0.9, 0.2},
								{1., 0.15},
								{-1, -1} };
	float maxCToMEnv[][2] = { {0., 1.5},
								{0.4, 1.6},
								{0.6, 25.},
								{0.75, 0.2},
								{1., 0.5},
								{-1, -1} };
	
	//Density Envelope									
	//in this implementation, density is already an average value, 
	//so we don't need to specify min/max density
	float densityEnv[][2] = { {0., 10.},
								{0.35, 300.},
								{0.9, 100.},
								{1., 2.},
								{-1, -1} };

    //Start and End Times for the Different Sections
	//Start and End Time for Instr 101
    float maxGrainTime1 = 8.; //give us 10 seconds of sound
	float currentTime1 = 3.; //first grain at time 0.
	
    //Start and End Time for Instr 102
	float maxGrainTime2 = 17.; //give us 10 seconds of sound
	float currentTime2 = 12.; //first grain at time 0.
    
    //Start and End Time for Instr 103
	float maxGrainTime3 = 29.; //give us 10 seconds of sound
	float currentTime3 = 24.; //first grain at time 0.

    //Declare variables in Csound
    float startTime, duration, volume, carFreq, modFreq, indexOfModulation, cToM, pan, density;
    
    //For Instr 101 - Sine Grain	
	fprintf(csd, "\n");
    fprintf(csd, ";Section 1 - Instr 101 - Sine Grain\n");

    //Plays 2 Seconds of the original sound
    fprintf(csd,"i101 0.000000 2.00000 -3.0 440.0 1.0 0.500000\n");
	//Plays 5 Seconds of the granulated sound
    while (currentTime1 <= maxGrainTime1) {
		//First step is to recall the values from above for each parameter required by csound
		duration = getValueFromTendencyMask(currentTime1/maxGrainTime1, minDurEnv, maxDurEnv);

		volume = getValueFromTendencyMask(currentTime1/maxGrainTime1, minVolumeEnv, maxVolumeEnv);

		float pitch2 = getValueFromTendencyMask(currentTime1/maxGrainTime1, minPitchEnv1, maxPitchEnv1);
		carFreq = midiToFrequency(pitch2);

		pan = getValueFromTendencyMask(currentTime1/maxGrainTime1, minPanEnv, maxPanEnv);

		//last step is that we format all of these parameters into an instrument call and print to our csd file
		//Since this is a sine wave, we will be using ftable 1
		fprintf(csd, "i101 %f %f %f %f 1 %f\n", currentTime1, duration, volume, carFreq, pan);
		
		//interpolate the current density and use it to determine time until next grain
		density = interpolate(currentTime1 / maxGrainTime1, densityEnv);

		//calculate next grain start time
		//(1 / density) changes grains per second into seconds per grain, and seconds is the unit we need
		//if we want that value to be our average density (and we do), we can choose a value between 0 and twice our average density
		//by definition, this results in an average that is our desired average
		//the following expression could be reduced, but I've left it this way to hopefully make the logic clear
		float grainInterval1 = ((rand() % 1000)/999.) * ((1 / density) * 2);
		currentTime1 += grainInterval1;
	}
    
	//For Instr 102 - FM Grain
    fprintf(csd, "\n");
    fprintf(csd, ";Section 2 - Instr 102 - FM Grain\n");
    //Plays 2 Seconds of the original sound	
	fprintf(csd,"i102 9.0 2.0 -3.0 1532.753662 277.767487 2.401635 2 0.204288\n");
    //Plays 5 Seconds of the granulated sound
	while (currentTime2 <= maxGrainTime2) {
		duration = getValueFromTendencyMask(currentTime2/maxGrainTime2, minDurEnv, maxDurEnv);

		volume = getValueFromTendencyMask(currentTime2/maxGrainTime2, minVolumeEnv, maxVolumeEnv);

		float pitch = getValueFromTendencyMask(currentTime2/maxGrainTime2, minPitchEnv2, maxPitchEnv2);
		carFreq = midiToFrequency(pitch);

		cToM = getValueFromTendencyMask(currentTime2/maxGrainTime2, minCToMEnv, maxCToMEnv);
		modFreq = carFreq / cToM; //basic FM stuff, solving for the modulator frequency by using the Carrier to Modulator ratio specified above
		
		//For FM we are adding an additional variable to modulate the modFreq
		indexOfModulation = getValueFromTendencyMask(currentTime2/maxGrainTime2, minIOfMEnv, maxIOfMEnv);

		pan = getValueFromTendencyMask(currentTime2/maxGrainTime2, minPanEnv, maxPanEnv);

		//last step is that we format all of these parameters into an instrument call and print to our csd file
		//We are using ftable 2, so the 2 never changes
		fprintf(csd, "i102 %f %f %f %f %f %f 2 %f\n", currentTime2, duration, volume, carFreq, modFreq, indexOfModulation, pan);
		
		//interpolate the current density and use it to determine time until next grain
		density = interpolate(currentTime2 / maxGrainTime2, densityEnv);

		//calculate next grain start time
		//(1 / density) changes grains per second into seconds per grain, and seconds is the unit we need
		//if we want that value to be our average density (and we do), we can choose a value between 0 and twice our average density
		//by definition, this results in an average that is our desired average
		//the following expression could be reduced, but I've left it this way to hopefully make the logic clear
		float grainInterval = ((rand() % 1000)/999.) * ((1 / density) * 2);
		currentTime2 += grainInterval;
	}
    
    //For Instr 103 - Audio File	
    //will need to adjust the density time (?) to make the audio file sound more legible, less dense, bigger grains
	fprintf(csd, "\n");
    fprintf(csd, ";Section 3 - Instr 103 - AudioFile\n");
    //Plays 2 Seconds of the original sound	
	fprintf(csd,"i103 18.0 2.0 -3.0 220.0 4 6 225 215 0.806835\n");
    fprintf(csd,"i103 20.0 2.0 -3.0 220.0 4 5 225 215 0.806835\n");
	//Plays 5 Seconds of the granulated sound
	while (currentTime3 <= maxGrainTime3) {
		duration = getValueFromTendencyMask(currentTime3/maxGrainTime3, minDurEnv, maxDurEnv);

		volume = getValueFromTendencyMask(currentTime3/maxGrainTime3, minVolumeEnv, maxVolumeEnv);
		
        float pitch2 = getValueFromTendencyMask(currentTime3/maxGrainTime3, minPitchEnv3, maxPitchEnv3);
		carFreq = midiToFrequency(pitch2);

        float pitchfrq2 = carFreq + 2.; //deviate from frequency by +2
        float pitchfrq3 = carFreq - 2.; //deviate from frequency by -2
        
        int sample = rand() % (5 + 1 - 4) + 4; //ftable 4 and 5 contain 2 audio samples, this randomizes between those samples
        
		//envelope functions 3, 4, 5, 6, 7 are randomized. 
		//This is part of the oscillator that functions as an envelope controlling the amplitude of the audio file inside Csound
        int envfn = rand() % (7 + 1 - 3) + 3; 
		
		//if you're concerned about equal loudness panning (and you should be),
		//don't worry; I'm taking the square root in the orchestra file
		pan = getValueFromTendencyMask(currentTime3/maxGrainTime3, minPanEnv, maxPanEnv);

		//last step is that we format all of these parameters into an instrument call and print to our csd file
		fprintf(csd, "i103 %f %f %f %f %d %d %f %f %f\n", currentTime3, duration, volume, carFreq, sample, envfn, pitchfrq2, pitchfrq3, pan);
		
		//interpolate the current density and use it to determine time until next grain
		density = interpolate(currentTime3 / maxGrainTime3, densityEnv);

		//calculate next grain start time
		//(1 / density) changes grains per second into seconds per grain, and seconds is the unit we need
		//if we want that value to be our average density (and we do), we can choose a value between 0 and twice our average density
		//by definition, this results in an average that is our desired average
		//the following expression could be reduced, but I've left it this way to hopefully make the logic clear
		float grainInterval3 = ((rand() % 1000)/999.) * ((1 / density) * 2);
		currentTime3 += grainInterval3;
	}
	fprintf(csd, "</CsScore>\n");
	fprintf(csd, "</CsoundSynthesizer>\n");

	fprintf(csd, "\n");

	fclose(csd);

	//system("csound myScore.csd -a -o test.aif -O null && open -a Audacity test.aif");
	//system("open -a Audacity test.aif");
	system("csound myScore.csd -odac -O null");
	//system("csound myScore.csd -odac");

	return 0;	
}
//This function converts MIDI values to Frequency, that is better read in Csound
float midiToFrequency(float midi) {
	float frequency = 440. * pow(2, ((midi - 69) / 12));
	return frequency;
}

//This function interpolates values to create a smoother line in the first set of line coordinates above
float interpolate(float index, float envelope[][2]) {
	int nextBP = 1; // BP for breakpoint

	while (envelope[nextBP][0] < index && envelope[nextBP][0] >= 0.) {
		nextBP++;
	}

	float lastX = envelope[nextBP - 1][0];
	float lastY = envelope[nextBP - 1][1];
	float nextX = envelope[nextBP][0];
	float nextY = envelope[nextBP][1];
	
	float percentageThroughWholeThing = index;

	float percentageThroughCurrentSegment = (percentageThroughWholeThing - lastX) / (nextX - lastX);

	float interpolatedValue = (nextY - lastY) * percentageThroughCurrentSegment + lastY;
	return interpolatedValue;
}

//This function retrieves the values from the line envelopes above
float getValueFromTendencyMask(float index, float minEnvelope[][2], float maxEnvelope[][2]) {
	float minValue = interpolate(index, minEnvelope);
	float maxValue = interpolate(index, maxEnvelope);
	float value = (maxValue - minValue) * ((rand() % 1000)/999.) + minValue;
	return value;
}



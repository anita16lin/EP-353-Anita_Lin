#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Building on RhythmStudy02.c, this program converts the information in our pattern into a csd file
//to render the notes using Csound.
//Based on Csound orchestra and samples by Tristan Medjo and Elijah Davis!

//could be more scientific about this, but this gives you a general overall volume knob
#define VOLUME_KNOB 0.5
#define AMPS 32767 * VOLUME_KNOB

typedef struct Note {
	float beat;
	float durInSecs;
	float semitoneOffset;
	float ampsMultiplier;
} Note;

//adding a helper function to convert semitone offset to frequency multiplier
float offsetToMultiplier(float offset) {
	return pow(2, (offset/12.));
}

int main() {

	FILE *csd;
	csd = fopen("ThisSickBeat.csd", "w");
	fprintf(csd, "<CsoundSynthesizer>\n");
	fprintf(csd, "<CsInstruments>\n");
	fprintf(csd, "instr hellosine\n");
	fprintf(csd, "k1 linen 1, .2, p3, .3\n");
	fprintf(csd, "a1 oscili 10000, cpspch(p4), 1\n");
	fprintf(csd, "out a1 * k1\n");
	fprintf(csd, "endin\n");
	fprintf(csd, "instr 1\n");
	fprintf(csd, "aoutL, aoutR loscil p4, p5, p6, 1, 1\n");
	fprintf(csd, "outs aoutL, aoutR\n");
	fprintf(csd, "endin\n");
	fprintf(csd, "</CsInstruments>\n");
	fprintf(csd, "<CsScore>\n");
	fprintf(csd, "f 1  0 8192 10 1\n");
	fprintf(csd, "f 2 0 0 1 \"bass.wav\" 0 4 0\n");
	fprintf(csd, "f 3 0 0 1 \"kick.wav\" 0 4 0\n");
	fprintf(csd, "f 4 0 0 1 \"snare.wav\" 0 4 0\n");
	fprintf(csd, "f 5 0 0 1 \"hat.wav\" 0 4 0\n");
	fprintf(csd, "f 6 0 0 1 \"stab.wav\" 0 4 0\n");
	fprintf(csd, "f 8 0 0 1 \"gritbass.wav\" 0 4 0\n");
	fprintf(csd, "f 9 0 0 1 \"bigsnare.wav\" 0 4 0\n");
	fprintf(csd, "f 10 0 0 1 \"tom.wav\" 0 4 0\n");
	fprintf(csd, "f 11 0 0 1 \"melody2.wav\" 0 4 0\n");
	fprintf(csd, "f 12 0 0 1 \"bass2.wav\" 0 4 0\n");
	fprintf(csd, "f 13 0 0 1 \"wood.wav\" 0 4 0\n");

	Note pattern01[] = { 
		{0,		2.,		0., 	1.}, 
		{0.5,	2.,		-12.,	0.85}, 
		{1.,	2.,		0., 	0.5}, 
		{1.25,	2.,		-2., 	0.6}, 
		{1.5, 	2.,		0., 	0.7}, 
		{1.75, 	2.,		1., 	1.}, 
		{4,		2.,		-12., 	1.}, 
		{4.5,	2.,		-24.,	0.85}, 
		{5.,	2.,		0., 	0.6}, 
		{5.25,	2.,		-2., 	0.7}, 
		{5.5, 	2.,		0., 	0.8}, 
		{5.75, 	2.,		-9., 	1.} }; 
	int pattern01Length = sizeof(pattern01)/sizeof(pattern01[0]);
	int pattern01Index = 0;

	float bpm = 120.;
	float secsPerBeat = 60 / bpm;
	int totalBeats = 8;
	int ticksPerBeat = 16;

	for (int tick = 0; tick < totalBeats * ticksPerBeat; ++tick)
	{
		float beat = (float)tick/ticksPerBeat;
		float time = secsPerBeat * beat;
		//uncomment these if you want to see how these are all related...
		//printf("Current tick: %d\n", tick);
		//printf("Current beat: %f\n", beat);
		//printf("Current time: %f\n", time);
		
		if (beat >= pattern01[pattern01Index].beat && pattern01Index < pattern01Length)
		{
			Note currentNote = pattern01[pattern01Index];
			printf("Time: %f; Beat: %f; Dur: %f; Note: %f; Amps: %f\n", time, currentNote.beat, currentNote.durInSecs, currentNote.semitoneOffset, currentNote.ampsMultiplier);
			fprintf(csd, "i1 %f %f %f %f 11\n", time, currentNote.durInSecs, currentNote.ampsMultiplier * AMPS, offsetToMultiplier(currentNote.semitoneOffset));
			pattern01Index++;
		}
	}

	fprintf(csd, "</CsScore>\n");
	fprintf(csd, "</CsoundSynthesizer>\n");
	fprintf(csd, "\n");

	fclose(csd);

	system("csound ThisSickBeat.csd -odac");

	return 0;
}
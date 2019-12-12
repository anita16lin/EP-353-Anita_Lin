#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Building on RhythmStudy02.c, this program converts the information in our pattern into a csd file
//to render the notes using Csound.
//Composition, Csound orchestra, and samples by Tristan Medjo and Elijah Davis!
//I regret that took almost all of the neat microtonality out of the original composition (which used pitch multipliers instead of semitone offsets)
//by implementing the offset multiplier function, 
//but I thought that this helper function would be a useful thing to demonstrate

/* Ideas for how to expand this program...

As the length of the piece increases, it would be useful to add a concept of measure
Either write a helper function to which you pass measure, beat, and meter and it returns the beat
or implement a struct that contains measure and beat and rewrite the scheduler function to use it

You can descide whether it's more convenient to specify a start time and number of repetitions
or a start time plus end time

Add the ability to play a portion of a rhythm or to repeat just a part of it
Maybe choose which parts gets repeated randomly to add variation
Maybe add the ability to scale a rhythm (e.g., play it twice as fast or twice as slow)

Implement statistical variation in musical parameters such as amplitude, 
so that each repetition (or each note) is a little bit different
(e.g., add a subtle random variation to the hi hat amplitude)

Think about how to use some of the tendency mask ideas in the granular synthesis demo
to appy an envelope to these rhythms as they play (e.g., fade out)

Rewrite the scheduler function to allow you to offset the amplitude of the original phrase with each call

Pass the loscil looping flag to the scheduler, so you can turn it on when you want it

Implement a function that will choose from a set of phrases at random,
perhaps with a random pause between phrases, but still oriented on the beat
*/

//could be more scientific about this, but this gives you a general overall volume knob
#define VOLUME_KNOB 0.45
#define AMPS 32767 * VOLUME_KNOB
#define BPM 60.0

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

void schedulePattern(FILE *csd, Note* originalPattern, int originalPatternLength, float startBeat, int numberOfRepetitions, float repetitionInterval, int ftable) {
	
	int newPatternLength = originalPatternLength * numberOfRepetitions;
	Note *newPattern = malloc(sizeof(Note) * newPatternLength);
	

	//int noteCountInNewPattern = originalPatternLength * numberOfRepetitions;
	for (int rep = 0; rep < numberOfRepetitions; ++rep)
	{
		for (int note = 0; note < originalPatternLength; ++note)
		{
			int newNote = note + (rep * originalPatternLength);
			printf("original note beat: %f\n", originalPattern[note].beat);
			newPattern[newNote] = originalPattern[note];
			newPattern[newNote].beat += (startBeat + (rep * repetitionInterval));
			printf("copied note: %f\n", newPattern[newNote].beat);
		}
	}

	float secsPerBeat = 60 / BPM;
	int patternIndex = 0;

	while (patternIndex < newPatternLength) {
		Note currentNote = newPattern[patternIndex];

		float time = secsPerBeat * currentNote.beat;
		printf("Time: %f; Beat: %f; Dur: %f; Note: %f; Amps: %f\n", time, currentNote.beat, currentNote.durInSecs, currentNote.semitoneOffset, currentNote.ampsMultiplier);
		fprintf(csd, "i1 %f %f %f %f %d\n", time, currentNote.durInSecs, currentNote.ampsMultiplier * AMPS, offsetToMultiplier(currentNote.semitoneOffset), ftable);
		patternIndex++;
	}

	free(newPattern);
}


int main() {

	FILE *csd;
	csd = fopen("ThisSickBeat.csd", "w");
	fprintf(csd, "<CsoundSynthesizer>\n");
	fprintf(csd, "<CsInstruments>\n");
	fprintf(csd, "instr 1\n");
	//note: the last parameter is the loop mode; 0 is off
	fprintf(csd, "aoutL, aoutR loscil p4, p5, p6, 1, 0\n");
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

	//some of these could be the same, but making them different 
	//so we can adjust duration, volume, pitch independently
	//you might consider rewriting the scheduler to allow the same pattern to be
	//played with different offsets
	Note gritBassPattern[] = { {0, 1., 0., 0.3} };

	Note gritBassPattern2[] = { {0, 1., 0., 0.3},
								{1, 1., 0., 0.3},
								{2, 1., 0., 0.3} };

	Note kickPattern[] = { {0, 0.4, 0., 0.75} };

	Note bigSnarePattern[] = { {0, 1., 0., 1.} };

	Note hatPattern1[] = { {0, 0.15, 0., 0.5} };

	/*
	Note hatPattern2[] = {
		{0.125,	1.,		0., 	0.8}, 
		{0.25,	1.,		0.,		0.9}, 
		{0.375,	1.,		0., 	1.0} }; 
	*/

	Note snarePattern[] = { {0, 0.4, 0.5, 1.05} };

	Note tomPattern[] = { 
		{0.375, 0.5, -12., 0.3},
		{0.75, 0.5, -2.2, 0.3} };

	Note melodyPattern[] = { 
		{0,		2.,		0., 	0.5}, 
		{0.5,	2.,		-12.,	0.425}, 
		{1.,	2.,		0., 	0.25}, 
		{1.25,	2.,		-2., 	0.3}, 
		{1.5, 	2.,		0., 	0.35}, 
		{1.75, 	2.,		1., 	0.5}, 
		{4,		2.,		-12., 	0.5}, 
		{4.5,	2.,		-24.,	0.425}, 
		{5.,	2.,		0., 	0.3}, 
		{5.25,	2.,		-2., 	0.35}, 
		{5.5, 	2.,		0., 	0.4}, 
		{5.75, 	2.,		-9., 	0.5} }; 

	Note woodblockPattern[] = { 
		{0.125, 0.1, 12., 0.3},
		{0.25, 0.1, 12., 0.6},
		{0.375, 0.1, 12, 0.9} };

	//this gradually ascending figure is easy to procedurally generate
	Note bassWobPattern[16];
	for (int i = 0; i < 16; i++) {
		float beat = i * 0.25;
		float durInSecs = 0.15;
		float semitoneOffset = (i / 16.0) * 3.0;
		float ampsMultiplier = 0.2;
		Note newNote = { beat, durInSecs, semitoneOffset, ampsMultiplier};
		bassWobPattern[i] = newNote;
	}

	Note wubPattern[] = { 
		{0.0, 1., 0., 0.6},
		{1.5, 1., 0., 0.6},
		{2.625, 1., 0., 0.6},
		{2.75, 0.15, 3., 0.6},
		{3.0, 0.8, 0., 0.6},
		{3.5, 0.8, 1., 0.6} };

	//...int originalPatternLength, float startBeat, int numberOfRepetitions, int repetitionInterval, int ftable) {
	schedulePattern(csd, gritBassPattern, 1, 0, 64, 1, 8);
	schedulePattern(csd, gritBassPattern2, 3, 64, 8, 4, 8);
	schedulePattern(csd, kickPattern, 1, 8, 172, 0.5, 3);
	schedulePattern(csd, bigSnarePattern, 1, 15.5, 3, 8, 9);
	schedulePattern(csd, hatPattern1, 1, 16.25, 32, 0.5, 5);
	schedulePattern(csd, hatPattern1, 1, 32, 256, 0.125, 5);
	schedulePattern(csd, hatPattern1, 1, 64.25, 32, 0.5, 5);
	schedulePattern(csd, tomPattern, 2, 16, 48, 1, 10);
	schedulePattern(csd, melodyPattern, 12, 32, 4, 8, 11);
	schedulePattern(csd, snarePattern, 1, 16.5, 72, 1, 4);
	schedulePattern(csd, woodblockPattern, 3, 80, 29, 0.5, 13);
	schedulePattern(csd, bassWobPattern, 16, 47.95, 4, 4, 2);
	schedulePattern(csd, wubPattern, 6, 64, 8, 4, 12);

	fprintf(csd, "</CsScore>\n");
	fprintf(csd, "</CsoundSynthesizer>\n");
	fprintf(csd, "\n");

	fclose(csd);

	//system("csound ThisSickBeat.csd -odac -d --nodisplays");
	system("csound ThisSickBeat.csd -o rs.wav -d --nodisplays");

	return 0;
}
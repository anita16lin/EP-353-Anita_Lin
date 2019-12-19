#include <stdio.h>

//Building on RhythmStudy01.c, this program not only tracks beats, 
//but also encapsulates multiple parameters into the concept of a single "note" using a struct

typedef struct Note {
	float beat;
	float durInSecs;
	float semitoneOffset;
	float ampsMultiplier;
} Note;

Note myFavoriteNote = { 2.25, 20000., 64., 0.00001 };

int main() {

	Note pattern01[] = { 
		{0,		2.,		0., 	1.}, 
		{0.5,	2.,		-12.,	1.}, 
		{1.,	2.,		0., 	1.}, 
		{1.25,	2.,		-2., 	1.}, 
		{1.5, 	2.,		0., 	1.}, 
		{1.75, 	2.,		1., 	1.}, 
		{4,		2.,		0., 	1.}, 
		{4.5,	2.,		-12.,	1.}, 
		{5.,	2.,		0., 	1.}, 
		{5.25,	2.,		-2., 	1.}, 
		{5.5, 	2.,		0., 	1.}, 
		{5.75, 	2.,		-9., 	1.} }; 
	int pattern01Length = sizeof(pattern01)/sizeof(pattern01[0]);
	int pattern01Index = 0;

	float bpm = 120.;
	float secsPerBeat = 60 / bpm;
	int totalBeats = 4;
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
			printf("Time: %f; Beat: %f; Dur: %f; Note: %f; Amps: %f\n", time, 
				currentNote.beat, currentNote.durInSecs, currentNote.semitoneOffset, currentNote.ampsMultiplier);
			pattern01Index++;
		}
	}

	return 0;
}
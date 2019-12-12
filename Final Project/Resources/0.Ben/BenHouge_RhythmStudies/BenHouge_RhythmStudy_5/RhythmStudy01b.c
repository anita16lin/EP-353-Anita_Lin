#include <stdio.h>

//This program doesn't play any sound, 
//but illustrates one way to define a rhythmic pattern and turn it into time.
//Try changing the pattern or the bpm and see how the output changes.

int main() {

	//actually better: sizeof(pattern01)/sizeof(pattern01[0])
	float pattern01[] = { 0., 0.5, 1., 1.25, 1.5, 1.75 };
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
		
		if (beat >= pattern01[pattern01Index] && pattern01Index < pattern01Length)
		{
			printf("Time: %f; Beat: %f\n", time, pattern01[pattern01Index]);
			pattern01Index++;
		}
	}

	return 0;
}
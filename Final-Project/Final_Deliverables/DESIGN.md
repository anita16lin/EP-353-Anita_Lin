# Design Document
Welcome to the **C & Csound Granularizer**! This is the design document for this project to give you an in-depth look at the implementation and design choices I made. 

## How it started
I first started really wanting to make a granular synthesizer. It was a little ambitious, so then my teacher (Akito) suggested I use Csound in conjunction with C. A lot of this code is based on the code by Ben Houge and a huge part of the credit goes to him. You can find his code in the /references folder. I expanded his code by implementing granular synthesis with the Sine Oscillator and audio files. 

## Interesting bits to note
For the granularizer for audio files, you can add any audio file you want by changing the ftable callback to your own audio file. Please refer to the User Manual (readme.md) for specifics. I really wanted to make audio playback possible with granular synthesis because that's where I think granular synthesis is most useful and interesting. The Csound instrument I have made allows you to play back the audio file at different pitches, and to modulate the pitch as it plays. 

I decided to make different pitch envelopes for each of the instrument so that each of them can be controlled separately. I also decided to make different variables for the start and end times for each instrument so that it was easier to control which instrument is playing and to have different sections. Each **while loop** contains a separate instrument so that it can print out the score for each instrument in sections. Since Csound can playback the whole score at once through determining the start times of the score, I separated the score by instrument so that it is easier to read and understand how each instrument is being granularized.  

I also implemented the sine wave because I wanted to see how to implement different oscillators. Based on that, I think implementing any other csound instrument is pretty straightforward and is something I would like to do in the future. The biggest challenge was mapping the paramters in the csound instruments to the parameters in the c file and making sure they are giving and receiving the correct values.

## Future Implementations

I really tried hard to integrate global variables like distortion, delay and reverb but it was giving a bit of trouble and I did not get it working without errors in time. In the future, I would like to pursue this and see how I can implement this. 

---
**Made by Anita Lin**

Berklee College of Music

EP 353 - Audio Programming in C
# User Manual
Welcome to the **C & Csound Granularizer**! This is the documentation for this project to guide you through how to use it. Hope you enjoy!

## Quickstart
To run and compile the main program: 
gcc -o GG 1GrainDemo_SineFMAudio.c && ./GG && csound -odac -d -O null myScore.csd

To run and compile the example composition: 
gcc -o GG 2Composition.c && ./GG && csound -odac -d -O null myScore.csd

Please make sure you have the associated files that come in the /Final_Deliverables folder.

## Components of the Program
### Files
This program contains these files:
1. 1GrainDemo_SineFMAudio.c
2. 2Composition.c
3. final-anita.orc
4. GG
5. hellorcb.aif
6. myScore.csd
7. sing.aif

**The main program requires all of these associated files to run.**
You will also need to enable the csound extension in VisualStudioCode and have Csound downloaded on your computer in order to run the program in the terminal.

### What is it?
This program showcases three csound instruments: Sine, FM, and Audio File that uses C to create granular synthesis. It does it very ingeniously by creating very miniscule durations and printing hundreds of lines of score that would otherwise be impractical in Csound. I started from Ben Houge's implementation of granular in FM that my teacher, Akito, shared with me. The program first plays 2 seconds of the original sound without granular synthesis, and then it plays 5 seconds of the sound with granular synthesis. It first plays a good old Sine, then an FM implementation, and then two Audio files. 

### Components
The main part of the program that generates the granular synthesis is 1GrainDemo_SineFMAudio.c. It prints into the myScore.csd file so that Csound can run as usual. Firstly, final-anita.orc is an orchestra file that contains all of the Csound instruments that the main program reads and prints into the myScore.csd file. Secondly, the main file prints down the score lines that makes up the bulk of the granular implementation. The headers and other formatting is also printed in the proper place. And so, myScore.csd is a regular csd file written by C that Csound can read. 

1GrainDemo_SineFMAudio.c contains all the parameters of the instruments including duration, volume, pitch, pan and more. It also uses envelopes to smoothly express these parameters. 

## Things to Explore
If you want to load your own audio file, then put the audio file (.aif files only) into the same folder as the program files. Then add this line of code into line 58: 
fprintf(csd, "f5 0 0 1 \"youraudiofile.aif\" 0 0 0\n");
Be sure to comment out or delete line 53 that also uses ftable f5.

---
**Made by Anita Lin**

Berklee College of Music

EP 353 - Audio Programming in C
#include <stdio.h>

//typedef and enumeration outside of the int main() function. Starting from 1. 
typedef enum Scalemode {
    Ionian = 1, Dorian, Phrygian, Lydian, Mixolydian, Aeolian, Locrian
} Scalemode;

//Create a structure for the scale
typedef struct Scale {
    unsigned char rootNote;
    unsigned char note2;
    unsigned char note3;
    unsigned char note4;
    unsigned char note5;
    unsigned char note6;
    unsigned char note7;
    unsigned char note8;
} Scale;

//Nest the notes of the scale inside the Scale Structure

typedef struct Note {
    Scale scale[7];
} Note;

int main()
{
    //Ask the user what type of scale they would like
    Scalemode scalemode;
    printf("Type in which waveform you would like (1~7)?\n");
    scanf("%d", &scalemode);
    
    //Ask the user what root note they would like
    int UserRootNote;
    printf("Type in which midi root note you would like (0~127)?\n");
    scanf("%d", &UserRootNote);

    Note notes = {{
        {0, 2, 4, 5, 7, 9, 11, 12},
        {0, 2, 3, 5, 7, 9, 10, 12},
        {0, 1, 3, 5, 7, 8, 10, 12},
        {0, 2, 4, 6, 7, 9, 11, 12},
        {0, 2, 4, 5, 7, 9, 10, 12},
        {0, 2, 3, 5, 7, 8, 10, 12},
        {0, 1, 3, 5, 6, 8, 10, 12}
    }};

    //I couldn't figure out a smart way to do this so here it is copy-pasta method
    switch(scalemode){
        case Ionian:
            printf("First note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].rootNote + UserRootNote);
            printf("Second note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note2 + UserRootNote);
            printf("Third note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note3 + UserRootNote);
            printf("Fourth note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note4 + UserRootNote);
            printf("Fifth note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note5 + UserRootNote);
            printf("Sixth note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note6 + UserRootNote);
            printf("Seventh note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note7 + UserRootNote);
            printf("Octave note of Ionian (1) with root note %d is: %d\n", UserRootNote, notes.scale[0].note8 + UserRootNote);
        break;
        case Dorian:
            printf("First note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].rootNote + UserRootNote);
            printf("Second note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note2 + UserRootNote);
            printf("Third note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note3 + UserRootNote);
            printf("Fourth note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note4 + UserRootNote);
            printf("Fifth note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note5 + UserRootNote);
            printf("Sixth note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note6 + UserRootNote);
            printf("Seventh note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note7 + UserRootNote);
            printf("Octave note of Dorian (2) with root note %d is: %d\n", UserRootNote, notes.scale[1].note8 + UserRootNote);
        break;
        case Phrygian:
            printf("First note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].rootNote + UserRootNote);
            printf("Second note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note2 + UserRootNote);
            printf("Third note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note3 + UserRootNote);
            printf("Fourth note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note4 + UserRootNote);
            printf("Fifth note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note5 + UserRootNote);
            printf("Sixth note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note6 + UserRootNote);
            printf("Seventh note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note7 + UserRootNote);
            printf("Octave note of Phrygian (3) with root note %d is: %d\n", UserRootNote, notes.scale[2].note8 + UserRootNote);
        break;
        case Lydian:
            printf("First note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].rootNote + UserRootNote);
            printf("Second note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note2 + UserRootNote);
            printf("Third note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note3 + UserRootNote);
            printf("Fourth note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note4 + UserRootNote);
            printf("Fifth note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note5 + UserRootNote);
            printf("Sixth note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note6 + UserRootNote);
            printf("Seventh note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note7 + UserRootNote);
            printf("Octave note of Lydian (4) with root note %d is: %d\n", UserRootNote, notes.scale[3].note8 + UserRootNote);
        break;
        case Mixolydian:
            printf("First note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].rootNote + UserRootNote);
            printf("Second note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note2 + UserRootNote);
            printf("Third note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note3 + UserRootNote);
            printf("Fourth note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note4 + UserRootNote);
            printf("Fifth note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note5 + UserRootNote);
            printf("Sixth note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note6 + UserRootNote);
            printf("Seventh note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note7 + UserRootNote);
            printf("Octave note of Mixolydian (5) with root note %d is: %d\n", UserRootNote, notes.scale[4].note8 + UserRootNote);
        break;
        case Aeolian:
            printf("First note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].rootNote + UserRootNote);
            printf("Second note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note2 + UserRootNote);
            printf("Third note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note3 + UserRootNote);
            printf("Fourth note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note4 + UserRootNote);
            printf("Fifth note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note5 + UserRootNote);
            printf("Sixth note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note6 + UserRootNote);
            printf("Seventh note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note7 + UserRootNote);
            printf("Octave note of Aeolian (6) with root note %d is: %d\n", UserRootNote, notes.scale[5].note8 + UserRootNote);
        case Locrian:
            printf("First note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].rootNote + UserRootNote);
            printf("Second note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note2 + UserRootNote);
            printf("Third note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note3 + UserRootNote);
            printf("Fourth note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note4 + UserRootNote);
            printf("Fifth note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note5 + UserRootNote);
            printf("Sixth note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note6 + UserRootNote);
            printf("Seventh note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note7 + UserRootNote);
            printf("Octave note of Locrian (7) with root note %d is: %d\n", UserRootNote, notes.scale[6].note8 + UserRootNote);
        break;
    }
    
    return 0;
}
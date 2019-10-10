/*Claude is the mastermind behind this one. Claude, Edward and I spent 5
hours on thursday working on this and so I have 3 versions. Only this one works. */
#include <stdio.h>
#include <string.h>

int main() {

  FILE *file;

  file = fopen("LoremIpsum.txt", "r");

  // This is to run through the file and make sure it has stuff
  if(file == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; 
  }

  char str[2]; 
  int acount = 0;
  int bcount = 0;
  int ccount = 0;
  int dcount = 0;
  int ecount = 0;
  int fcount = 0;
  int gcount = 0;
  int hcount = 0;
  int icount = 0;
  int jcount = 0;
  int kcount = 0;
  int lcount = 0;
  int mcount = 0;
  int ncount = 0;
  int ocount = 0;
  int pcount = 0;
  int qcount = 0;
  int rcount = 0;
  int scount = 0;
  int tcount = 0;
  int ucount = 0;
  int vcount = 0;
  int wcount = 0;
  int xcount = 0;
  int ycount = 0;
  int zcount = 0;
  int Acount = 0;
  int Bcount = 0;
  int Ccount = 0;
  int Dcount = 0;
  int Ecount = 0;
  int Fcount = 0;
  int Gcount = 0;
  int Hcount = 0;
  int Icount = 0;
  int Jcount = 0;
  int Kcount = 0;
  int Lcount = 0;
  int Mcount = 0;
  int Ncount = 0;
  int Ocount = 0;
  int Pcount = 0;
  int Qcount = 0;
  int Rcount = 0;
  int Scount = 0;
  int Tcount = 0;
  int Ucount = 0;
  int Vcount = 0;
  int Wcount = 0;
  int Xcount = 0;
  int Ycount = 0;
  int Zcount = 0;
  int periodcount = 0;

  
  while(fgets(str, 2, file) != NULL) { 
    if(strcmp(str, "a") == 0) acount++;
    if(strcmp(str, "b") == 0) bcount++;
    if(strcmp(str, "c") == 0) ccount++;
    if(strcmp(str, "d") == 0) dcount++;
    if(strcmp(str, "e") == 0) ecount++;
    if(strcmp(str, "f") == 0) fcount++;
    if(strcmp(str, "g") == 0) gcount++;
    if(strcmp(str, "h") == 0) hcount++;
    if(strcmp(str, "i") == 0) icount++;
    if(strcmp(str, "j") == 0) jcount++;
    if(strcmp(str, "k") == 0) kcount++;
    if(strcmp(str, "l") == 0) lcount++;
    if(strcmp(str, "m") == 0) mcount++;
    if(strcmp(str, "n") == 0) ncount++;
    if(strcmp(str, "o") == 0) ocount++;
    if(strcmp(str, "p") == 0) pcount++;
    if(strcmp(str, "q") == 0) qcount++;
    if(strcmp(str, "r") == 0) rcount++;
    if(strcmp(str, "s") == 0) scount++;
    if(strcmp(str, "t") == 0) tcount++;
    if(strcmp(str, "u") == 0) ucount++;
    if(strcmp(str, "v") == 0) vcount++;
    if(strcmp(str, "w") == 0) wcount++;
    if(strcmp(str, "x") == 0) xcount++;
    if(strcmp(str, "y") == 0) ycount++;
    if(strcmp(str, "z") == 0) zcount++;
    if(strcmp(str, "A") == 0) Acount++;
    if(strcmp(str, "B") == 0) Bcount++;
    if(strcmp(str, "C") == 0) Ccount++;
    if(strcmp(str, "D") == 0) Dcount++;
    if(strcmp(str, "E") == 0) Ecount++;
    if(strcmp(str, "F") == 0) Fcount++;
    if(strcmp(str, "G") == 0) Gcount++;
    if(strcmp(str, "H") == 0) Hcount++;
    if(strcmp(str, "I") == 0) Icount++;
    if(strcmp(str, "J") == 0) Jcount++;
    if(strcmp(str, "K") == 0) Kcount++;
    if(strcmp(str, "L") == 0) Lcount++;
    if(strcmp(str, "M") == 0) Mcount++;
    if(strcmp(str, "N") == 0) Ncount++;
    if(strcmp(str, "O") == 0) Ocount++;
    if(strcmp(str, "P") == 0) Pcount++;
    if(strcmp(str, "Q") == 0) Qcount++;
    if(strcmp(str, "R") == 0) Rcount++;
    if(strcmp(str, "S") == 0) Scount++;
    if(strcmp(str, "T") == 0) Tcount++;
    if(strcmp(str, "U") == 0) Ucount++;
    if(strcmp(str, "V") == 0) Vcount++;
    if(strcmp(str, "W") == 0) Wcount++;
    if(strcmp(str, "X") == 0) Xcount++;
    if(strcmp(str, "Y") == 0) Ycount++;
    if(strcmp(str, "Z") == 0) Zcount++;
    if(strcmp(str, ".") == 0) periodcount++;
  }

  rewind(file);

  printf("A number of times a string \"a\" appeared in the file is: %d.\n", acount);
  printf("A number of times a string \"b\" appeared in the file is: %d.\n", bcount);
  printf("A number of times a string \"c\" appeared in the file is: %d.\n", ccount);
  printf("A number of times a string \"d\" appeared in the file is: %d.\n", dcount);
  printf("A number of times a string \"e\" appeared in the file is: %d.\n", ecount);
  printf("A number of times a string \"f\" appeared in the file is: %d.\n", fcount);
  printf("A number of times a string \"g\" appeared in the file is: %d.\n", gcount);
  printf("A number of times a string \"h\" appeared in the file is: %d.\n", hcount);
  printf("A number of times a string \"i\" appeared in the file is: %d.\n", icount);
  printf("A number of times a string \"j\" appeared in the file is: %d.\n", jcount);
  printf("A number of times a string \"k\" appeared in the file is: %d.\n", kcount);
  printf("A number of times a string \"l\" appeared in the file is: %d.\n", lcount);
  printf("A number of times a string \"m\" appeared in the file is: %d.\n", mcount);
  printf("A number of times a string \"n\" appeared in the file is: %d.\n", ncount);
  printf("A number of times a string \"o\" appeared in the file is: %d.\n", ocount);
  printf("A number of times a string \"p\" appeared in the file is: %d.\n", pcount);
  printf("A number of times a string \"q\" appeared in the file is: %d.\n", qcount);
  printf("A number of times a string \"r\" appeared in the file is: %d.\n", rcount);
  printf("A number of times a string \"s\" appeared in the file is: %d.\n", scount);
  printf("A number of times a string \"t\" appeared in the file is: %d.\n", tcount);
  printf("A number of times a string \"u\" appeared in the file is: %d.\n", ucount);
  printf("A number of times a string \"v\" appeared in the file is: %d.\n", vcount);
  printf("A number of times a string \"w\" appeared in the file is: %d.\n", wcount);
  printf("A number of times a string \"x\" appeared in the file is: %d.\n", xcount);
  printf("A number of times a string \"y\" appeared in the file is: %d.\n", ycount);
  printf("A number of times a string \"z\" appeared in the file is: %d.\n", zcount);
  printf("A number of times a string \"A\" appeared in the file is: %d.\n", Acount);
  printf("A number of times a string \"B\" appeared in the file is: %d.\n", Bcount);
  printf("A number of times a string \"C\" appeared in the file is: %d.\n", Ccount);
  printf("A number of times a string \"D\" appeared in the file is: %d.\n", Dcount);
  printf("A number of times a string \"E\" appeared in the file is: %d.\n", Ecount);
  printf("A number of times a string \"F\" appeared in the file is: %d.\n", Fcount);
  printf("A number of times a string \"G\" appeared in the file is: %d.\n", Gcount);
  printf("A number of times a string \"H\" appeared in the file is: %d.\n", Hcount);
  printf("A number of times a string \"I\" appeared in the file is: %d.\n", Icount);
  printf("A number of times a string \"J\" appeared in the file is: %d.\n", Jcount);
  printf("A number of times a string \"K\" appeared in the file is: %d.\n", Kcount);
  printf("A number of times a string \"L\" appeared in the file is: %d.\n", Lcount);
  printf("A number of times a string \"M\" appeared in the file is: %d.\n", Mcount);
  printf("A number of times a string \"N\" appeared in the file is: %d.\n", Ncount);
  printf("A number of times a string \"O\" appeared in the file is: %d.\n", Ocount);
  printf("A number of times a string \"P\" appeared in the file is: %d.\n", Pcount);
  printf("A number of times a string \"Q\" appeared in the file is: %d.\n", Qcount);
  printf("A number of times a string \"R\" appeared in the file is: %d.\n", Rcount);
  printf("A number of times a string \"S\" appeared in the file is: %d.\n", Scount);
  printf("A number of times a string \"T\" appeared in the file is: %d.\n", Tcount);
  printf("A number of times a string \"U\" appeared in the file is: %d.\n", Ucount);
  printf("A number of times a string \"V\" appeared in the file is: %d.\n", Vcount);
  printf("A number of times a string \"W\" appeared in the file is: %d.\n", Wcount);
  printf("A number of times a string \"X\" appeared in the file is: %d.\n", Xcount);
  printf("A number of times a string \"Y\" appeared in the file is: %d.\n", Ycount);
  printf("A number of times a string \"Z\" appeared in the file is: %d.\n", Zcount);
  printf("A number of times a string \".\" appeared in the file is: %d.\n", periodcount);
  
  //Close opened file
  if(file) fclose(file);

  return 0;
}
#include<stdio.h>
#include<string.h>

extern char *decode ();

int main ()
{
  char plaintext[300];
  int rotatingKey[20]={1,2,3,14,3,6,7,12}; // init rotating key
  int lenOfKey=8; // lenght of rotating key array
  int key=0;      // to decide position key in for loop
  
 //read myfile.txt and save into plaintext 
  FILE *f;
  f = fopen ("encode.txt", "r"); // open file with permission read
  fscanf (f, "%[^EOF]", plaintext);
  fclose (f);

  FILE *f_save;
  f_save = fopen ("decode.txt", "w+");
 
 
  for (int i = 0; i < strlen (plaintext); i++)
    {
      char n[5] = ""; // save double  characters in plaintext
      strncat (n, &plaintext[i], 2); // 
      fputs (decode (n, rotatingKey[key]), f_save);
       key++; // increase  key for next loop 
      if (key >= lenOfKey) // if key greater thang lenght of arr, asign key =0 
	  {
	  	key = 0;
	  
	  }
	   
      i++;// increase i because program read doube characters
    }
   fclose (f_save);// close file
}

//
//  main.cpp
//  Cstring
//
//  Created by maria saenz on 8/21/14.
//  Copyright (c) 2014 maria saenz. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;


void strcpy_slide(){
	char str1[]="Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2,str1);
	strcpy(str3,"copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
}

void strncpy_slide(){
	  char str1[]= "To be or not to be";
	  char str2[40];
	  char str3[40];

	  /* copy to sized buffer (overflow safe): */
	  strncpy ( str2, str1, sizeof(str2) );

	  /* partial copy (only 5 chars): */
	  strncpy ( str3, str2, 5 );
	  str3[5] = '\0';   /* null character manually added */

	  puts (str1);
	  puts (str2);
	  puts (str3);

}

void strcat_slide(){
    	char str[80];
	  strcpy (str,"these ");
	  strcat (str,"strings ");
	  strcat (str,"are ");
	  strcat (str,"concatenated.");
	  puts (str);
}

void strncat_slide(){
	char str1[20];
	  char str2[20];
	  strcpy (str1,"To be ");
	  strcpy (str2,"or not to be");
	  strncat (str1, str2, 6);
	  puts (str1);
}

void strcmp_slide(){
	char key[] = "apple";
  char buffer[80];
  do {
     printf ("Guess my favorite fruit? ");
     fflush (stdout);
     scanf ("%79s",buffer);
  } while (strcmp (key,buffer) != 0);
  puts ("Correct answer!");
}

void strncmp_slide(){
	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
  int n;
  puts ("Looking for R2 astromech droids...");
  for (n=0 ; n<3 ; n++)
    if (strncmp (str[n],"R2xx",2) == 0)
    {
      printf ("found %s\n",str[n]);
    }
}

void strchr_slide(){
	char str[] = "This is a sample string";
  char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=strchr(str,'s');
  while (pch!=NULL)
  {
    printf ("found at %ld\n",pch-str+1);
    pch=strchr(pch+1,'s');
  }
}

void strrchr_slide(){
  char str[] = "This is a sample string";
  char * pch;
  pch=strrchr(str,'s');
  printf ("Last occurence of 's' found at %ld \n",pch-str+1);
  
}

void strstr_slide(){
	char str[] ="This is a simple string";
  char * pch;
  pch = strstr (str,"simple");
  strncpy (pch,"sample",6);
  puts (str);
}

int main(){
	strcpy_slide();
	cout<<endl;
	strncpy_slide();
	cout<<endl;
	strcat_slide();
	cout<<endl;
	strncat_slide();
	cout<<endl;
	strcmp_slide();
	cout<<endl;
	strncmp_slide();
	cout<<endl;
	strchr_slide();
	cout<<endl;
	strrchr_slide();
	cout<<endl;
	strstr_slide();
	cout<<endl;
	return 0;
}


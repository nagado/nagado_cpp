#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int max_line = 254;

void putError(const char* text)
{
  cerr << "ERROR " << text << "\n";
  exit(1);
}

int main()
{
  FILE * fp = fopen("text.txt", "r");

  if (fp == 0)
    putError("Cannot open file");

  char * line = new char[max_line + 1];
  
  while (fgets(line, max_line + 1, fp))
  { 
    if (strlen(line) > max_line)
      putError("The string is too long");
    cout << line;
  } 

  delete line;
  fclose(fp);
  
  return 0;
} 


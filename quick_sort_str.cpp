#include <iostream>
#include <array>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int max_amount_lines = 1000;


void sort_worker (int begin, int end, char ** data)
{
  int k = begin;
  int k2 = end;
  char * num = data[(k + k2) / 2];
  char * copy;

  while (k <= k2)
  {
      while (strcmp(data[k],num) < 0)
      k++;

    while (strcmp(data[k2],num) > 0)
      k2--;
  
    if (k <= k2)
    {
      copy = data[k];
      data[k] = data[k2];
      data[k2] = copy;

      k++;
      k2--;
    }
  } 
  if (begin < k2)
    sort_worker (begin, k2, data);
  if (end > k)
    sort_worker (k, end, data);
}

void putError(const char * text)
{
  cerr << "ERROR " << text << "\n";
  exit(1);

}

int main ()
{
  const int max_line = 254;
  FILE * f;
  int lineNum = 0;
  char ** data = new char * [max_amount_lines];
  char * line = new char[max_line + 1];
  f = fopen("text.txt", "r");
  if (f == 0)
    putError("Cannot open file");
  
  while (fgets(line, max_line + 1, f))
  {
    data[lineNum] = new char [strlen(line) + 1];
    strcpy(data[lineNum++], line);
//    *(data + lineNum++) = MEANS THE SAME
  }
  if (lineNum > max_amount_lines - 1)
    putError("too many lines"); 
  else
    data[lineNum] = 0;
    
  fclose(f);
  sort_worker (0, lineNum - 1, data);
  
  for (int i = 0; i < lineNum; i++)
  {
    cout << data[i];
    delete data[i];
    data[i] = 0;
  }
  
  delete line;
  delete data;
  return 0;
}


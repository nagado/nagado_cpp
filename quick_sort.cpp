#include <iostream>
#include <array>
using namespace std;


void sort_worker (int begin, int end, int data[])
{
  int k = begin;
  int k2 = end;
  int num = data[(k + k2) / 2];
  int copy;

  while (k <= k2)
  {
    while (data[k] < num)
      k++;

    while (data[k2] > num)
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


int main ()
{
  const int l = 10;
  int data [] = { 10, 2, 5, 30, 27, 3, 16, 70, 6, 1 };
  sort_worker (0, l - 1, data);
  cout << data;

  return 0;
}


#include <iostream>
using namespace std;


int length(int num)
{
  int len;

  for (len = 0; num != 0; len++)
    num /= 10;

  return len;
}

char * integerToString(int num, char * numStr, int len)
{
  for (int i = 0; i < len; i++)
    {
    numStr[len - i - 1] = char(num % 10 + 48);   
    num /= 10;
    }
   
  return numStr;
}


int main()
{
  int num = 1234567890; 
  int len = length(num);
  char numStr [len + 1];
  numStr[len] = 0;
  cout << integerToString(num, numStr, len) << '\n';

  return 0;
}

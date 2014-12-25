#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

const char * numStr1 = "1234567890";
const char * numStr2 = "1234r23545";


int length(const char * numStr)
{
  int len = 0;
  
  for  (len = 0; numStr[len] != 0; len++);

  return len; 
}


int stringToInteger(const char * numStr)
{
  int num = 0; 
  const int len = length(numStr);

  for (int i = 0; i < len; ++i)
  {
    if ((int(numStr[i]) >= '0') && (int(numStr[i]) <= '9'))
      num += pow(10, len - i - 1) * (int(numStr[i]) - '0');
    else
    {
      cout << "ERROR: Only numbers are allowed in the string\n";
      exit(-1);
    }
  }
 
  return num;
}


int main()
{
  cout << stringToInteger(numStr1) << '\n';
  
  return 0;
}

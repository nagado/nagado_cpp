#include "list.hpp"


int main()
{
  List list;

  list.add(3);
  list.add(5);

  ListIter iter = list;
  
  for(ListIter iter = list; iter; ++iter)
  {
    std::cout << iter->data << " ";
  }

  std::cout << std::endl;

  return 0;

}

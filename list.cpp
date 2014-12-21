#include <iostream>
using namespace std;

struct Element
{
  int information;
  Element * lastElement;
  Element * nextElement;   
};

Element * List;

Element * createElement()
{
  Element * el = new Element;
  el -> information = 0;
  el -> lastElement = 0;
  el -> nextElement = 0;  

  return el;
} 

Element * getLastElement(Element * el)
{
  return el -> lastElement;
}

Element * getNextElement(Element * el)
{
  return el -> nextElement;
}

void insertAfter(struct Element * newEl, struct Element * oldEl)
{
  newEl -> lastElement = oldEl;
  newEl -> nextElement = oldEl -> nextElement;
  oldEl -> nextElement = newEl;

  if ((newEl -> nextElement) != 0) 
    (newEl -> nextElement) -> lastElement = newEl;
}

void insertBefore(struct Element * newEl, struct Element * oldEl)
{
  newEl -> lastElement = oldEl -> lastElement;
  oldEl -> lastElement = newEl;
  newEl -> nextElement = oldEl;

  if ((newEl -> lastElement) != 0)
    (newEl -> lastElement) -> nextElement = newEl;
  else
    List = newEl;
}

void deleteElement(Element * el)
{
  if ((el -> lastElement) != 0)
    (el -> lastElement) -> nextElement = (el -> nextElement);
  else
    List = el -> nextElement;

  if ((el -> nextElement) != 0)
    (el -> nextElement) -> lastElement = (el -> lastElement);

  delete el;
}

void printElement(struct Element * el)
{
  cout << "Information: " << el -> information << "\nLast Element's address: " << el -> lastElement << "\nNext Element's address: " << el -> nextElement << endl;
 
}

int test1()
{
  int check = 0;
  Element * currentElement = 0;
  List = createElement();
  currentElement = List;

  currentElement -> information = 12;
  insertAfter(createElement(), currentElement);
  currentElement = getNextElement(currentElement);
  currentElement -> information = 15;

  if (currentElement -> information != 15)
    check = -1;
  if (List -> information != 12)
    check = -1;

  insertBefore(createElement(), List);
  List -> information = 10;

  if (List -> information != 10)
    check = -1;

  return check;
}

int test2()
{
  int check = 0;
  Element * currentElement = 0;
  List = createElement();
  currentElement = List;

  currentElement -> information = 10;
  insertAfter(createElement(), currentElement);
  currentElement = getNextElement(currentElement);
  currentElement -> information = 20;
  insertAfter(createElement(), currentElement);
  currentElement = getNextElement(currentElement);
  currentElement -> information = 30;

  deleteElement(getLastElement(currentElement));
  if (((getLastElement(currentElement) -> information) != 10) || ((currentElement -> information) != 30))
    check = -1;

  return check;  
}


int main()
{
  if (test1())
     cerr << "Someting is  wrong. Test1 (Creation. Insertion before and after).\n";

  if (test2())
    cerr << "Something is wrong. Test2 (Creation, insertion after, walking forward and backward, deleting).\n";

  return 0;
}



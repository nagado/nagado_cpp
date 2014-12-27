#include <iostream>
using namespace std;

struct Element
{
  int information;
  Element * previous;
  Element * next;   
};

Element * createElement()
{
  Element * el = new Element;
  el->information = 0;
  el->previous = 0;
  el->next = 0;  

  return el;
} 

Element * getPreviousElement(Element * el)
{
  return el -> previous;
}

Element * getNextElement(Element * el)
{
  return el -> next;
}

void insertAfter(Element * newEl, Element * oldEl)
{
  newEl->previous = oldEl;
  newEl->next = oldEl->next;
  oldEl->next = newEl;

  if (newEl->next != 0) 
    (newEl->next)->previous = newEl;
}

void insertBefore(Element * newEl, Element * oldEl, Element * head)
{
  newEl->previous = oldEl->previous;
  oldEl->previous = newEl;
  newEl->next = oldEl;

  if (newEl->previous != 0)
    (newEl->previous)->next = newEl;
  else
    head = newEl;
}

void deleteElement(Element * el, Element * head)
{
  if (el->previous != 0)
    (el->previous)->next = (el->next);
  else
    head = el->next;

  if (el->next != 0)
    (el->next)->previous = (el->previous);

  delete el;
}

void printElement(Element * el)
{
  cout << "Information: " << el->information << "\nLast Element's address: " << el->previous << "\nNext Element's address: " << el->next << endl;
 
}

int test1()
{
  int check = 0;
  Element * current = 0;
  Element * head = createElement();
  current = head;

  current->information = 12;
  insertAfter(createElement(), current);
  current = getNextElement(current);
  current->information = 15;

  if (current->information != 15)
    check = -1;
  if (head->information != 12)
    check = -1;

  insertBefore(createElement(), current, head);
  head->information = 10;

  if (head->information != 10)
    check = -1;

  return check;
}

int test2()
{
  int check = 0;
  Element * current = 0;
  Element * head = createElement();
  current = head;

  current->information = 10;
  insertAfter(createElement(), current);
  current = getNextElement(current);
  current->information = 20;
  insertAfter(createElement(), current);
  current = getNextElement(current);
  current->information = 30;

  deleteElement(getPreviousElement(current), head);
  if (((getPreviousElement(current)->information) != 10) || ((current->information) != 30))
    check = -1;

  return check;  
}


int main()
{
  if (test1())
     cerr << "Someting is  wrong. Test1 (Creation. Insertion before and after).\n";
  else
    cout << "Test 1 successfully comleted\n";

  if (test2())
    cerr << "Something is wrong. Test2 (Creation, insertion after, walking forward and backward, deleting).\n";
  else
    cout << "Test 2 successfully comleted\n";

  return 0;
}



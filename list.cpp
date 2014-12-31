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

Element * getPrevious(Element * el)
{
  return el -> previous;
}

Element * getNext(Element * el)
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

Element * insertBefore(Element * newEl, Element * oldEl, Element * head)
{
  newEl->previous = oldEl->previous;
  oldEl->previous = newEl;
  newEl->next = oldEl;

  if (newEl->previous != 0)
    (newEl->previous)->next = newEl;
  else
    head = newEl;

  return head;
}

Element * deleteElement(Element * el, Element * head)
{
  if (el->previous != 0)
    (el->previous)->next = (el->next);
  else
    head = el->next;

  if (el->next != 0)
    (el->next)->previous = (el->previous);

  delete el;

  return head;
}

void printElement(Element * el)
{
  cout << "Information: " << el->information << "\nLast Element's address: " << el->previous << "\nNext Element's address: " << el->next << endl;
 
}

void testGetPrevious()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  if (getPrevious(head) != 0)
    check = -1;

  insertAfter(createElement(), current); 
  current = getNext(current);

  if (getPrevious(current) != head)
    check = -1;

  if (check)
    cout << "Function getPrevious() is not working as it supposed to.\n";
  else
    cout << "Testing function getPrevious().......well done!.\n";
}

void testGetNext()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  if (getNext(current) != 0)
    check = -1;

  current = createElement();
  head = insertBefore(current, head, head);
  if (current != head)
    check = -1;

  if (check)
    cout << "Function getNext() is not working as it supposed to.\n";
  else
    cout << "Testing function getNext()...........well done!.\n";
}

void testInsertBefore()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  current = createElement();
  head = insertBefore(current, head, head); 

  if (head != current)
    check = -1;

  if (getPrevious(current) != 0)
    check = -1;

  if (check)
    cout << "Function insertBefore() is not working as it supposed to.\n";
  else
    cout << "Testing function insertBefore()......well done!.\n";
}

void testInsertAfter()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  current = createElement();
  insertAfter(current, head); 

  if (getNext(head) != current)
    check = -1;

  if (check)
    cout << "Function insertAfter() is not working as it supposed to.\n";
  else
    cout << "Testing function insertAfter().......well done!.\n";
}

void testDeleteElement()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  insertAfter(createElement(), head); 
  current = getNext(head);
  head = deleteElement(current, head);

  if (getNext(head) != 0) 
    check = -1;

  if (check)
    cout << "Function deleteElement() is not working as it supposed to.\n";
  else
    cout << "Testing function deleteElement().....well done!.\n";
}

void test1()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  current->information = 12;
  insertAfter(createElement(), current);
  current = getNext(current);
  current->information = 15;

  if (current->information != 15)
    check = -1;
  if (head->information != 12)
    check = -1;

  head = insertBefore(createElement(), current, head);
  head->information = 10;

  if (head->information != 10)
    check = -1;

  if (check)
    cout << "Global test 1 is not completed properly\n";
  else
    cout << "Global test 1...Done.\n";

}

void test2()
{
  int check = 0;
  Element * head = createElement();
  Element * current = head;

  current->information = 10;
  insertAfter(createElement(), current);
  current = getNext(current);
  current->information = 20;
  insertAfter(createElement(), current);
  current = getNext(current);
  current->information = 30;

  head = deleteElement(getPrevious(current), head);
  if (((getPrevious(current)->information) != 10) || ((current->information) != 30))
    check = -1;

  if (check)
    cout << "Global test 2 is not completed properly\n";
  else
    cout << "Global test 2...Done.\n";
}

void testing()
{
  testGetPrevious();
  testGetNext();
  testInsertBefore();
  testInsertAfter();
  testDeleteElement();

  test1();
  test2();
}


int main()
{
  testing();

  return 0;
}



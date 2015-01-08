#include <iostream>


class Element
{
  friend class List;
  friend class ListIter;
  
  Element* previous;
  Element* next;
  public:
    int data;

    Element(Element * p = 0, int d = 0, Element * n = 0)
    {previous = p; data = d; next = n; }

};

class List
{
  friend class ListIter;

  Element* first;
  Element* last;

  public:

    List()
    {first = 0; last = 0; }

    List(const List& list2)
    {first = list2.first; last = list2.last; }

    void add(int d)
    {
      Element* el = new Element(last, d); 
      if (first == 0)
        first = el;
      else
        (el->previous)->next = el;

      el->previous = last;
      last = el;
    }
};

class ListIter
{
  List* list;
  Element* current;

  public:
    ListIter()
    {current = 0; }
    ListIter(List& list2)
    {list = &list2; current = list->first; }

    operator bool() const {if (current == 0) return false; else return true;} 
//    operator ListIter* () const {return current;}
    Element* operator++() {current = current->next; return current;}
    Element* operator->()  {return current;}
};

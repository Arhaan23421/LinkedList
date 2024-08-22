#include <iostream>
#include <stdexcept>
#include <stddef.h>

using namespace std;

class List
{
  public:

  ~List()
  {
    clear();
  }

  void add(char data)
  {
    this->length +=1;
    if(head== nullptr)
    {
      Node* tempres = new Node();
      tempres-> data = data;
      head = tempres;
      return;
    }
    Node* temp = head;
    while(temp->next)
    {
        temp =temp->next;
    }
    Node* result = new Node();
    temp->next = result;
    result->data = data;
  }

  void print()
  {
    cout << "[";
    Node* temp = head;
      while(temp)
      {
        cout<<temp->data;
        if (temp->next) {
          cout << ", ";
        }
        temp = temp->next;
      }
      cout << "]" << endl;
  }

  void insert( char datas, int index)
  {
    this->length+=1;
    Node* temp = head;
    Node* news = new Node();
    news->data = datas;
    if(index==0)
    {
      news->next = head;
      head = news;
      return;
    }
    int counter = 1;
    Node* temp2 = head;
    while(counter != index)
    {
        temp2 = temp2->next;
      counter++;
    }
    news->next = temp2->next;
    temp2->next = news;
  }

  void del( int index)
  {
    this->length-=1;
    Node* temp = head;
    if(index==0)
    {
      Node* temp2 = head->next;
      delete head;
      head = temp2;
      return;
    }
    int counter = 1;
    Node* temp3=  head;
    while(counter != index)
    {
      temp3 = temp3->next;
      counter++;
    }
    Node* temp2 = temp3->next->next;
    delete temp3->next;
    temp3->next = temp2;

  }

  int lengthret()
  {
    return this->length;
  }

  char get(int index)
  {
    int counter = 0;
    Node* temp3 = head;
    while(counter != index)
    {
      temp3 = temp3->next;
      counter++;
    }
    return temp3->data;
  }

  int indexOf(char sample)
  {
    int counter=0;
    Node* temp3 = head;
    while(sample != temp3->data)
    {
      temp3 = temp3->next;
      counter++;
      if(counter == this->length)
      {
        return -1;
      }
    }
    return counter;
  }

  bool contains(char sample)
  {
    return indexOf(sample) > -1;
  }

  void clear()
  {
    while (this->length)
    {
      this->del(0);
    }
  }

  private:
  struct Node
  {
  public:
    char data;
    Node* next;
  };
  Node* head;
  int length;
};


int main()
{

  List* myList = new List();
  myList->print();
  myList->add('A');
  myList->add('B');
  myList->add('C');
  myList->print();
  myList->insert('D', 0);
  myList->print();
  myList->del(1);
  myList->print();
  cout << "There are " << myList->lengthret() << " elements in the list." << endl;
  cout << "Element at 0: " << myList->get(0) << endl;
  cout << "Element at 1: " << myList->get(1) << endl;
  cout << "Element at 2: " << myList->get(2) << endl;
  cout << "Index of 'C': " << myList->indexOf('C') << endl;
  cout << "Index of 'B': " << myList->indexOf('B') << endl;
  cout << "Index of 'D': " << myList->indexOf('D') << endl;
  cout << "Index of 'A': " << myList->indexOf('A') << endl;
  cout << "Contains 'B': " << myList->contains('B') << endl;
  cout << "Contains 'A': " << myList->contains('A') << endl;
  cout << "Before clear: ";
  myList->print();
  myList->clear();
  cout << "After clear: ";
  myList->print();
  delete myList;
  return 0;
}



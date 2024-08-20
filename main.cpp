#include <iostream>
#include <stdexcept>
#include <stddef.h>

using namespace std;

class Node
{
public:
char data;
Node* next;

int length()
{
  int counter = 0;
  Node* sample = this;
  while(sample)
  {
    counter++;
    sample = sample->next;
  }
  return counter;
}
 // private:

};

class List
{
  public:
  int length;

  void add(char data)
  {
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

  private:
  Node* head;
};

void printList(Node* sample);
int length(Node* sample);
Node* add( Node* head, char datas);
Node* insert( Node* head, char datas, int index);
Node* del(Node* head, int index);


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
  
  return 0;
}



#include <iostream>
#include <stdexcept>

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

private:
};

void printList(Node* sample);
int length(Node* sample);

int main()
{
  Node* sampleA = new Node();
  sampleA->data = 'A';
  Node* sampleB = new Node();
  sampleB->data = 'B';
  Node* sampleC = new Node();
  sampleC->data = 'C';

  sampleA->next = sampleB;
  sampleB->next = sampleC;

  cout << "This is a list of " << sampleA->length() << " elements:" << endl;
  printList(sampleA); // [A, B, C]
  return 0;
}

void printList(Node* sample)
{
  while(sample)
  {
    cout<< sample->data<<endl;
    sample =sample->next;
  }
}


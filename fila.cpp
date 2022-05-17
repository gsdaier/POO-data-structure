using namespace std;
#include <stddef.h>
#include <iostream>

class Node
{
    private:
        int data;
	    Node *next;
	public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        int getData() {
            return data;
        }

        Node* getNext(){
            return next;
        }

        void setData(int data) {
            this->data = data;
        }

        void setNext(Node* next) {
            this->next = next;
        }
};

class List {
    private:
        Node* head;
        int size;
    public:        
        List(){
            this->head = NULL;
            this->size = 0;
        }
        
    void push(int newData) {
        Node* newNode = new Node(newData);
        newNode->setNext(head);
        head = newNode;
        this->size++;
    }
  
    void insertAt(unsigned position, int newData) { 
      Node *newNode = new Node(newData), *temp = this->head, *prev;
      int i = 0;
      if(position == 0) {
        this->push(newData);
        return;
      }
      while (i != position && temp != NULL) {
        i++;
        prev = temp;
        temp = temp->getNext();
      } 
      if (i != position) {
        cout << "It's not possible to insert at this position.\n";
        return;
      }
      prev->setNext(newNode);
      newNode->setNext(temp);
      this->size++;
      return;
    }
    
    void append(int newData) {
      Node* newNode = new Node(newData);
      Node* temp = head;

      if(temp == NULL) {
        this->head = newNode;
        return;
      }
      
      while(temp->getNext() != NULL) {
        temp = temp->getNext();
      }

      temp->setNext(newNode);
      this->size++;
      return;
    }
};

class Stack {
  private:
    List *stack;

  public:
    Stack() {
      List *newList = new List();
      this->stack = newList;
    }
    
    void append(int data) {
      this->stack->append(data);
    }
};

int main(){
    List* list = new List();
    Stack *stack = new Stack();

    stack->append(1);
    stack->append(2);
    stack->append(3);
    stack->append(4);
    stack->append(5);
    cout << "Result: " << list << endl; // Esq. ou Dir.?
    cout << "Result: " << &list << endl; // Esq. ou Dir.?
    cout << "Result: " << stack << endl; 
}
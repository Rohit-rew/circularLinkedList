#include <iostream>
using namespace std;

class Node{
public :
    int data;
    Node* next;
};

class CircleLinkedList{
public:
    Node* head;
    
    int addAtEnd(int val){
        Node* NewNode = new Node();
        NewNode->data = val;
        
        if(head==NULL){
            head = NewNode;
            NewNode->next = head;
        }else{
            
            Node* currentNode = head;
            while (currentNode->next != head) {
                currentNode = currentNode->next;
            }
            currentNode->next = NewNode;
            NewNode->next = head;
            return 0;
        }
        
        return val;
    }

    int addAtTop(int val){
        Node* NewNode = new Node();
        NewNode->data = val;

        Node* currentNode = head;
        while (currentNode->next != head)
        {
            currentNode = currentNode->next;
        }
        
        NewNode->next = head;
        head = NewNode;
        currentNode->next = head;
        return NewNode->data;
    }

    
    void print(){
        Node* currentNode = head;
        cout << "print starts" <<endl;
        while (currentNode->next != head) {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }

        cout << currentNode->data <<endl;
        cout << "print ends" <<endl;
    }

    void printLoop(int num){
        Node* currentNode = head;
        int count = 0;
        cout << "print loop starts" << endl;
        while (count != num)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
            count ++;
        }

        cout << currentNode->data << endl;
        cout << "print loop ends" << endl;
    }
    
    
};

int main(int argc, const char * argv[]) {
    
    CircleLinkedList* CircleList1 = new CircleLinkedList();
    CircleList1->addAtEnd(10);
    CircleList1->addAtEnd(11);
    CircleList1->addAtEnd(12);
    CircleList1->addAtEnd(13);
    CircleList1->addAtEnd(14);
    CircleList1->addAtTop(22);
    CircleList1->print();
    // CircleList1->printLoop(20);
    
    cout << "number : " << CircleList1->head->next->next->next->next->next->next->next->next->next->next->data <<endl;
}

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
    
    int add(int val){
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
    
    
};

int main(int argc, const char * argv[]) {
    
    CircleLinkedList* CircleList1 = new CircleLinkedList();
    CircleList1->add(10);
    CircleList1->add(11);
    CircleList1->add(12);
    CircleList1->add(13);
    CircleList1->add(14);

    CircleList1->print();
    
    cout << "number : " << CircleList1->head->next->next->next->next->next->next->next->next->next->next->data <<endl;
}

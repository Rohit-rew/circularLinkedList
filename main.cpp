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

    int valueAt(int index){
        if(index == 0){
            return head->data;
        }
        int count = 0;
        Node* currentNode = head;
        while (count != index)
        {
            currentNode = currentNode->next;
            count++;
        }

        int currentValue = currentNode->data;
        return currentValue;
        
    }
    
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

    int addAt(int val , int index){
        Node* NewNode = new Node();
        NewNode->data = val;
        int count = 0;

        Node* currentNode = head;
        while (count != index-1)
        {
            currentNode = currentNode->next;
            count++;
        }
        
        NewNode->next = currentNode->next;
        currentNode->next = NewNode;
        return NewNode->data;
    }

    int removeTop(){
        Node* currentNode = head;
        while (currentNode->next != head)
        {
            currentNode = currentNode->next;
        }
        
        int removedVal = head->data;
        head = head->next;
        currentNode->next = head;
        return removedVal;
    }

    int removeBottom(){
        Node* currentNode = head;
        while (currentNode->next->next != head)
        {
            currentNode = currentNode->next;
        }
        int currentVal = currentNode->next->data;

        currentNode->next->next = NULL;
        currentNode->next = head;
        return currentVal;
    }

    int removeAt(int index){
        if(index==0){
            return removeTop();
        }else if(index == size()){
            return removeBottom();
        }
        int count = 0;
        Node* currentNode = head;
        while (count != index-1)
        {
            currentNode = currentNode->next;
            count++;
        }
        int removedVal = currentNode->next->data;
        currentNode->next = currentNode->next->next;
        return removedVal;
    }

    int search(int val){
        Node* currentNode = head;
        int count = 0;
        while (currentNode->next != head)
        {
            if(currentNode->data==val){
                return count;
            }
            currentNode = currentNode->next;
            count++;
        }

        return NULL;
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

    int size(){
        Node* currentNode = head;
        int count = 0;
        while (currentNode->next != head)
        {
            currentNode = currentNode->next;
            count++;
        }
        return count+1;
    }
    
};

int main(int argc, const char * argv[]) {
    
    CircleLinkedList* CircleList1 = new CircleLinkedList();
    CircleList1->addAtEnd(10);
    CircleList1->addAtEnd(11);
    CircleList1->addAtEnd(12);
    CircleList1->addAtEnd(44);
    CircleList1->addAtEnd(55);
    CircleList1->addAtEnd(66);
    CircleList1->addAtEnd(13);
    CircleList1->addAtEnd(14);
    CircleList1->addAtTop(22);
    CircleList1->addAt(77,3);

    cout << "removed bottom value : " << CircleList1->removeBottom() << endl;
    CircleList1->removeTop();
    CircleList1->removeAt(3);
    CircleList1->print();
    // CircleList1->printLoop(20);
    
    cout << CircleList1->valueAt(2) << endl;
    cout << "size of list : " << CircleList1->size() << endl;
    cout << "found value : " << CircleList1->search(68) << endl;
}

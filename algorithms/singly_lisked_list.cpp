#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            this->data = val;
            this->next = NULL;
        }

        
};

class SinglyLinkedList {
    private:
        Node* head;
    public:
        SinglyLinkedList(){
            head = NULL;            
        };

        void insertNodeEnd(int val){
            Node *newnode = new Node(val);
            
            if (head == NULL) {
                head = newnode;
            }
            else{
                Node* current = head;
                while(current->next){
                    current = current->next;
                };
                current->next = newnode;
            };
        };

        void display(){
            if(head==NULL){
                cout << "Nothing in the linked list!!!" << endl;
            }
            else{
            cout << "Linked List: ";
            Node* current = head;
            
            while(current!=NULL){
                cout << current->data << ", ";
                current = current->next;
            };

            cout << endl;
            };
        };
};

int main(){
    SinglyLinkedList sll;

    sll.display();

    sll.insertNodeEnd(9);
    sll.insertNodeEnd(8);
    sll.insertNodeEnd(7);
    sll.insertNodeEnd(6);

    sll.display();


    return 0;

}
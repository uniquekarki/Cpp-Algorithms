#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int val){
        this->data = val;
        this->next = nullptr;
    };
};

class DoublyLL{
    private:
        Node* head;
    public:
        DoublyLL(){
            this->head = nullptr;
        };

        void insertNodehead(int val){
            Node* newNode = new Node(val);
            if(head==nullptr){
                head = newNode;
            }
            else{
                Node* current = head;
                current->next = head->next;
                head = current;
            };
        };

        void displayLL(){
            if(head==nullptr){
                cout << "Linked List Is Empty!!!" << endl;
            }
            else{
                Node* current = head;
                cout << "Doubly Linked List Elements: ";
                while(current!=nullptr){
                    cout << current->data << ", ";
                    current = current->next;
                };
                cout << endl;
            };
        };
};

int main(){
    DoublyLL dll;
    dll.insertNodehead(9);
    dll.displayLL();
    return 0;
}
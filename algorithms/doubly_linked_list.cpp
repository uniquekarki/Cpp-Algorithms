#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
    Node(int val){
        this->data = val;
        this->prev = nullptr;
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
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            };
        };

        void insertNodetail(int val){
            Node* newNode = new Node(val);
            if(head==nullptr){
                head = newNode;
            }
            else{
                Node* current = head;
                while(current->next!= nullptr){
                    current = current->next;
                };
                current->next = newNode;
                newNode->prev = current;
            };
        };

        void insertNodeval(int nodeval, int val){
            Node* current = head;
            Node* newNode = new Node(val);
            while(current->data != nodeval){
                current = current->next;
            };

            newNode->next = current->next;
            newNode->prev = current;

            current->next->prev = newNode;
            current->next = newNode;

        };

        void deleteNodehead(){
            if(head == nullptr){
                cout << "Nothing to delete!!!" << endl;
            }
            else{
                Node* current = head;
                head = head->next;
                head->prev = nullptr;
                delete current;
            };
        };

        void deleteNodetail(){
            if(head == nullptr){
                cout << "Nothing to delete!!!" << endl;
            }
            else{
                Node* current = head;
                while(current->next!=nullptr){
                    current = current->next;
                };
                current->prev->next = nullptr;
                delete current;

            };
        };

        void deleteNodeval(int val){
            if(head == nullptr){
                cout << "The Linked List Is Empty!!!" << endl;
            }
            else{
                Node* current = head;

                while(current->data != val){
                    current = current->next;
                };
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
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

        void displayDesc(){
            if(head==nullptr){
                cout << "Linked List Is Empty!!!" << endl;
            }
            else{
                Node* current = head;
                while(current->next){
                    current = current->next;
                };
                cout << "Doubly Linked List Backwards: ";
                while(current != nullptr){
                    cout << current->data << ", ";
                    current = current->prev;
                };
                cout << endl;
            };
        };
};

int main(){
    DoublyLL dll;
    dll.insertNodehead(9);
    dll.displayLL();

    dll.insertNodehead(8);
    dll.displayLL();

    dll.insertNodetail(7);
    dll.displayLL();

    dll.insertNodetail(99);
    dll.displayLL();

    dll.insertNodetail(88);
    dll.displayLL();

    dll.insertNodetail(77);
    dll.displayLL();

    dll.insertNodeval(99,1);
    dll.displayLL();

    dll.deleteNodehead();
    dll.displayLL();

    dll.deleteNodetail();
    dll.displayLL();

    dll.deleteNodeval(1);
    dll.displayLL();

    dll.displayDesc();

    return 0;
}
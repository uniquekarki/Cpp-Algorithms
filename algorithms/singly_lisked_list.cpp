#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            this->data = val;
            this->next = nullptr;
        }

        
};

class SinglyLinkedList {
    private:
        Node* head;
    public:
        SinglyLinkedList(){
            head = nullptr;            
        };

        void insertNodeEnd(int val){
            Node *newnode = new Node(val);
            
            if (head == nullptr) {
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

        void insertNodehead(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        };

        void insertNodeval(int val, int insert){
            if(head==nullptr){
                cout << "Nothing in the linked list!!!" << endl;
            }
            else{
                Node* newNode = new Node(insert);
                Node* current = head;
                while(current!=nullptr){
                    if(current->data == val){
                        break;
                    };
                    current = current->next;
                };
                cout << "Final Current: " << current->data << endl;

                newNode->next = current->next;
                current->next = newNode;
                
            };
        };

        void display(){
            if(head==nullptr){
                cout << "Nothing in the linked list!!!" << endl;
            }
            else{
            cout << "Linked List: ";
            Node* current = head;
            
            while(current!=nullptr){
                cout << current->data << ", ";
                current = current->next;
            };

            cout << endl;
            };
        };

        void removeNodeEnd(){
            if (head == nullptr){
                cout << "Nothing to delete!!!" << endl;
            }
            else{
                Node* current = head;
                while(current->next->next){
                    current = current->next;
                };
                delete current->next;
                current->next = nullptr;
            };
        };

        void removeNodehead(){
            if(head == nullptr){
                cout << "Nothing to delete!!!" << endl;
            }
            else{
                Node* current = head;
                head = head->next;
                delete current;
            };
        };

        void removeNodeval(int val){
            if(head == nullptr){
                cout << "Nothing to delete!!!" << endl;
            }
            else{
                Node* current = head;
                Node* pred;
                while(current != nullptr){
                    if(current->data == val){
                        break;
                    }
                    pred = current;
                    current = current->next;
                };

                pred->next = current->next;
                delete current;

            }
        };
};

int main(){
    SinglyLinkedList sll;

    sll.display();

    sll.insertNodeEnd(9);
    sll.insertNodeEnd(8);
    sll.insertNodeEnd(7);
    sll.insertNodeEnd(6);
    sll.insertNodeEnd(5);
    sll.insertNodeEnd(4);


    sll.display();

    sll.removeNodeEnd();
    sll.display();

    sll.removeNodehead();
    sll.display();

    sll.removeNodeval(7);
    sll.display();

    sll.insertNodehead(9);
    sll.display();

    sll.insertNodeval(6,99);
    sll.display();

    return 0;

}
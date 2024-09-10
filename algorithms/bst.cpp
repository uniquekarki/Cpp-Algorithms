#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
            this->data = val;
            this->left = nullptr;
            this->right = nullptr;
        };
};

class BST{
    public:
        void insert(Node*& root, Node* newNode){
            if (root == nullptr){
                root = newNode;
            }
            else if(newNode->data < root->data){
                insert(root->left, newNode);
            }
            else if (newNode->data > root->data){
                insert(root->right, newNode);
            };
        };

        void remove(Node*& root, int val){
            Node* current = root;
            Node* parentNode;
            while(current->data!=val){
                parentNode = current;

                if(val < current->data){
                    if(current->left==nullptr){
                        cout << "No such value in BST to remove!!!" << endl;
                        return;
                    };
                    current = current->left;
                }
                else if(val > current->data){
                    if(current->right==nullptr){
                        cout << "No such value in BST to remove!!!" << endl;
                        return;
                    };
                    current = current->right;
                }
            };

            if(current->left == nullptr && current->right == nullptr){
                if(parentNode->left == current){
                    parentNode->left = nullptr;
                }
                else{
                    parentNode->right = nullptr;
                }
                delete current;
            }
            else if(current->left!=nullptr){
                Node* replaceNode = current->left;
                while(replaceNode->right!= nullptr){
                    replaceNode = replaceNode->right;
                };
                current->data = replaceNode->data;

                remove(current->left, replaceNode->data);
            }
            else if(current->right!=nullptr){
                Node* replaceNode = current->right;
                while(replaceNode->left!=nullptr){
                    replaceNode = replaceNode->left;
                };
                current->data = replaceNode->data;
                remove(current->right, replaceNode->data);
            };

        };

        void print(Node* root){
            cout << "Current Node: "<< root->data << endl;

            if(root->left){
                print(root->left);
            };

            if(root->right){
                print(root->right);
            };
        };
};

int main(){
    Node* root = new Node(10);
    BST binary;

    binary.insert(root, new Node(8));
    binary.insert(root, new Node(15));
    binary.insert(root, new Node(5));
    binary.insert(root, new Node(13));
    binary.insert(root, new Node(20));
    binary.insert(root, new Node(14));
    binary.insert(root, new Node(12));
    cout << "Insertion Done!!!" << endl;

    binary.print(root);

    binary.remove(root, 99);
    cout <<endl;
    cout << "After Removal!!!"<<endl;

    binary.print(root);

    return 0;
}
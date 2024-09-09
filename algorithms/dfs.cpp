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

class DFS{
    public:
        void traverse(Node* root){
            cout << "Current Node: "<< root->data << endl;
            if(root->left){
                traverse(root->left);
            };
            if(root->right){
                traverse(root->right);
            };
        };
};

int main(){

    Node* root = new Node(3);

    root->left = new Node(5);
    root->right = new Node(2);

    root->left->left = new Node(10);
    root->left->right = new Node(12);

    root->right->right = new Node(1);

    root->left->right->left = new Node(14);
    root->left->right->right = new Node(17);

    root->right->right->left = new Node(9);
    
    DFS search;
    search.traverse(root);
}
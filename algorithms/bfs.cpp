#include <iostream>
#include <vector>
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

class BFS{
    private:
        vector<Node*> queue;
        vector<int> elements;
    public:
        void traversal(Node* root){
            queue.push_back(root);
            while(!queue.empty()){
                elements.push_back(queue[0]->data);
                if(queue[0]->left){
                    queue.push_back(queue[0]->left);
                };
                if(queue[0]->right){
                    queue.push_back(queue[0]->right);
                };
                queue.erase(queue.begin());
            };

            cout << "Elements traversal in BFS: ";
            for(int i=0; i < elements.size(); i++){
                cout << elements[i] << " ";
            };
            cout << endl;
        };
};

int main(){
    Node* root = new Node(9);
    root->left = new Node(8);
    root->right = new Node(7);

    root->left->left = new Node(6);
    root->left->right = new Node(5);

    root->right->right = new Node(4);

    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);

    root->right->right->left = new Node(1);

    BFS search;
    search.traversal(root);


    return 0;
}
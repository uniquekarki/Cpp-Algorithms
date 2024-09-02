#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int* arr;
        int capacity;
    public:
        Stack (int max){
            capacity = max;
            arr = new int[capacity];
            top = -1;
        }

        ~Stack(){
            cout << "Destructor used!!!" << endl;
            delete[] arr;
        }

        bool isFull(){
            if(top==capacity-1){
                return true;
            }
            else{
                return false;
            };
        }

        bool isEmpty(){
            if(top<0){
                return true;
            }
            else{
                return false;
            };
        }

        void push(int x){
            if(isFull()){
                cout << "Stack is full!!!" << endl;
            }
            else{
                arr[++top] = x;
            };
        }

        void pop(){
            if(isEmpty()){
                cout << "The stack is empty!!!" << endl;
            }
            else{
                cout << arr[top] << " is removed from the stack" << endl;
                top--;
            };
        }

        void peek(){
            if(isEmpty()){
                cout << "The stack is empty!!!" << endl;
            }
            else{
                cout << "Stack: ";
                for(int i=0; i<=top; i++){
                    cout << arr[i] << ", ";
                };
                cout << endl;
            }
        }
};

int main(){
    int max;
    cout << "Max capacity of the stack: ";
    cin >> max;

    Stack stk(5);

    cout << "Peek:" << endl;
    stk.peek();

    cout << "Pop:" << endl;
    stk.pop();

    cout << "Push: 9" << endl;
    stk.push(9);

    cout << "Peek:" << endl;
    stk.peek();
    
    cout << "Push: 4" << endl;
    stk.push(4);

    cout << "Push: 2" << endl;
    stk.push(2);

    cout << "Push: 3" << endl;
    stk.push(3);

    cout << "Push: 1" << endl;
    stk.push(1);

    cout << "Push: 0" << endl;
    stk.push(0);

    cout << "Peek:" << endl;
    stk.peek();

    return 0;
}
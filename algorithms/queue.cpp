#include <iostream>
using namespace std;


class Queue{
    private:
        int* arr;
        int front;
        int rear;
        int capacity;
    
    public:
        Queue(int max){
            capacity = max;
            arr = new int[capacity];
            front = -1;
            rear = -1;
        }

        ~Queue(){
            cout << "Destructor used!!!" << endl;
            delete[] arr;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            };
        }

        bool isFull(){
            if(rear == capacity - 1){
                return true;
            }
            else{
                return false;
            };
        }

        void enqueue(int val){
            if(isFull()){
                cout << "Queue is full!!! Cannot enqueue: " << val << endl;
            }
            else if(isEmpty()){
                front++;
                rear++;
                arr[rear] = val;
                cout << "Added element: " << val << " to the stack." << endl;
            }
            else{
                rear++;
                arr[rear] = val;
                cout << "Added element: " << val << " to the stack." << endl;
            };
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty!!! Nothing to remove." << endl;
            }
            else if(front == 0 && rear == 0){
                cout << "Removed element: " << arr[front] << " from the stack." << endl;
                front--;
                rear--;
            }
            else{
                cout << "Removed element: " << arr[front] << " from the stack." << endl;
                for(int i=0;i<rear;i++){
                    arr[i] = arr[i+1];
                };
                rear--;
            }
        }


        void peek(){
            if(isEmpty()){
                cout << "Queue is empty!!! Nothing to show." << endl;
            }
            else{
                cout << "Queue: ";
                for(int i=0; i<=rear; i++){
                    cout << arr[i] << ", ";
                }
                cout << "Front: " << front << " Rear: " << rear << endl;
            };
        }

};

int main(){

    int max;
    cout << "Max capacity of the queue: ";
    cin >> max;

    Queue que(max);

    cout << "Peek:" << endl;
    que.peek();

    cout << "dequeue:" << endl;
    que.dequeue();

    cout << "enqueue: 9" << endl;
    que.enqueue(9);

    cout << "Peek:" << endl;
    que.peek();
    
    cout << "enqueue: 8" << endl;
    que.enqueue(8);
    
    cout << "Peek:" << endl;
    que.peek();

    cout << "dequeue:" << endl;
    que.dequeue();

    cout << "Peek:" << endl;
    que.peek();

    cout << "dequeue:" << endl;
    que.dequeue();

    cout << "Peek:" << endl;
    que.peek();

    cout << "enqueue: 9" << endl;
    que.enqueue(9);

    cout << "enqueue: 8" << endl;
    que.enqueue(8);

    cout << "enqueue: 7" << endl;
    que.enqueue(7);

    cout << "enqueue: 6" << endl;
    que.enqueue(6);

    cout << "enqueue: 5" << endl;
    que.enqueue(5);

    cout << "enqueue: 4" << endl;
    que.enqueue(4);

    cout << "Peek:" << endl;
    que.peek();

    return 0;
}
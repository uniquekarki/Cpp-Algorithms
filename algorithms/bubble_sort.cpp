#include <iostream>
using namespace std;

int bubble_sort(int *arr){
    int temp;
    for(int i = 0; i<4; i++){
        for(int j = i+1; j < 5; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

int main(){
    int arr[5];
    
    for(int i=0; i<5; i++){
        cout << "Enter number into the array: ";
        cin >> arr[i];
    }
    
    cout << "You array is: ";
    for(int j=0;j<5;j++){
        cout << arr[j] << " ";
    }
    cout << endl;

    bubble_sort(arr);

    cout << "The sorted array: ";
    for(int k = 0; k < 5; k++){
        cout << arr[k] << " ";
    }

    return 0;
}
// C++ program to demonstrate std::distance()
#include <iostream>
#include <vector>
#include <unordered_set>
#include "main.h"

using namespace std;

int main(){
    // Example data: a list of points in 2D space
    vector<vector<float>> data = {
        {1.0, 2.0},
        {2.0, 3.0},
        {4.0, 5.0},
        {5.0, 6.0},
        {7.0, 8.0},
        {8.0, 9.0},
        {10.0, 11.0},
        {11.0, 12.0},
        {13.0, 14.0},
        {14.0, 15.0}
    };


    float alpha = 1.2; // Example distance threshold
    int R = 2; // Maximum number of out-neighbors for the node
    int L_size = 3;
    vector<vector<int>> G = vamana(data, R, L_size, alpha);

    cout << "Final Graph After Vamana:\n";
    for (const auto &row: G){
        for (const auto &elem: row){
            cout << elem << " ";
        };
        cout << endl;
    };

    cout << "You are going to University of California, Riverside Mr. Unique Karki but soon Dr. Unique Karki\n";

    return 0;
}
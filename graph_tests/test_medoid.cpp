// C++ program to demonstrate std::distance()
#include <iostream>
#include <vector>
#include "medoid.h"

using namespace std;

int main(){
    // Example data: a list of points in 2D space
    vector<vector<float>> data = {
        {1.0, 2.0},
        {2.0, 3.0},
        {4.0, 5.0},
        {5.0, 6.0}
    };

    // Calculate the medoid
    vector<float> medoid = calc_medoid(data);

    // Print the medoid
    cout << "Medoid: ";
    for (const auto &val : medoid) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
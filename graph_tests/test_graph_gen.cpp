// C++ program to demonstrate std::distance()
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main(){
    // Example data: a list of points in 2D space
    vector<vector<float>> data = {
        {1.0, 2.0},
        {2.0, 3.0},
        {4.0, 5.0},
        {5.0, 6.0}
    };

    vector<vector<int>> graph = create_graph(data, 3);

    // Print the medoid
    cout << "Graph: " << endl;
    for(int i=0; i < graph.size(); i++){
        cout << "Out edge for " << i << " : ";
        for(const auto &out: graph[i]){
            cout << out << " ";
        };
        cout << endl;
    };
    
    cout << endl;
    return 0;
}
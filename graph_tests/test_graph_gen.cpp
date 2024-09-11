// C++ program to demonstrate std::distance()
#include <iostream>
#include <vector>
#include <unordered_set>
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
    // cout << "Graph: " << endl;
    // for(int i=0; i < graph.size(); i++){
    //     cout << "Out edge for " << i << " : ";
    //     for(const auto &out: graph[i]){
    //         cout << out << " ";
    //     };
    //     cout << endl;
    // };
    
    // cout << "Index of {4.0, 5.0} = " << get_index(data, {5.0, 6.0});
    vector<float> s = calc_medoid(data);
    vector<float> xq = {7.0,7.0};
    pair<vector<int>, unordered_set<int>> result = greedy_search(data, graph, s, xq, 2, 3);

    // Extract the nearest k elements and the set of visited nodes from the result
    vector<int> nearest_k_elements = result.first;
    unordered_set<int> visited_nodes = result.second;
    cout << "Nearest K elems: \n";
    for (const auto &elem: nearest_k_elements){
        cout << elem << " ";
    };

    cout << "\nVisited Nodes: \n";
    for (const auto &elem: visited_nodes){
        cout << elem << " ";
    };


    cout << endl;
    return 0;
}
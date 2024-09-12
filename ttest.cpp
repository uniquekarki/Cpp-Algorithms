// C++ program to demonstrate std::distance()
#include <iostream>
#include <vector>
#include <unordered_set>
#include "graph.h"
#include "prune.h"


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

    vector<vector<int>> graph = create_graph(data, 5);

    // Print the medoid
    cout << "Graph: " << endl;
    for(int i=0; i < graph.size(); i++){
        cout << "Out edge for " << i << " : ";
        for(const auto &out: graph[i]){
            cout << out << " ";
        };
        cout << endl;
    };
    
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

    // Parameters for robust pruning
    float alpha = 1.2; // Example distance threshold
    int R = 2; // Maximum number of out-neighbors for the node
    int p = nearest_k_elements[0]; // Assume the first nearest neighbor as the point of reference
    
    // Run robust pruning on the graph
    graph = robust_prune(p, graph[p], alpha, R, data, graph);
    
    // Optionally, print the updated graph
    for (int i = 0; i < graph.size(); i++) {
        cout << "Neighbors of node " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


// cout << "p: " << p << endl;
//     cout << "alpha: " << alpha << endl;
//     cout << "R: " << R << endl;
    
//     cout << "P:\n";
//     for(const auto &row: P){
//         for(const auto &elem: row){
//             cout << elem << " ";
//         };
//         cout << endl;
//     };

//     cout << "G:\n";
//     for(const auto &row: G){
//         for(const auto &elem: row){
//             cout << elem << " ";
//         };
//         cout << endl;
//     };

//     cout << "V:\n";
//     for(const auto &elem: V){
//         cout << elem << " ";
//     };
//     cout << endl;
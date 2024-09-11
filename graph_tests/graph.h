#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<vector<int>> create_graph(const vector<vector<float>> &P, int R){
    vector<vector<int>> G;
    int n = P.size();

    srand(time(0));
    for (int i=0; i<n; i++){
        vector<int> edges;
        while (edges.size() < R){

            // The random integer created would be the random edge for vector in i-th position
            int randomNum = rand() % n;
            
            // Avoid self and duplicates
            if(randomNum!=i && find(edges.begin(), edges.end(), randomNum) == edges.end() ){
                edges.push_back(randomNum);
            };
        };
        G.push_back(edges);
    };

    return G;
};
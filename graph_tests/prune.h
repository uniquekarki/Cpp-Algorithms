#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include "medoid.h"
using namespace std;

vector<vector<int>> robust_prune(
    const int p,
    const float alpha,
    const int R,
    const vector<vector<float>> &P,
    vector<vector<int>> &G
){
    vector<int> N_out_p;
    vector<int> V = G[p];

    if (V.empty()) {
        // If V is empty, just return the current state of G
        G[p] = N_out_p;
        return G;
    }

    int p_star =-1;
    float minDist = numeric_limits<float>::max();
    for(const auto &elem: V){
        float dist = euclideanDistance(P[elem], P[p]);

        if(dist < minDist){
            minDist = dist;
            p_star = elem;
        };
    };

    N_out_p.push_back(p_star);
    if (N_out_p.size() == R) {
        G[p] = N_out_p;
        return G;
    };

    for(const auto &elem: V) {
        float dist_p_star = euclideanDistance(P[p_star], P[elem]);
        float dist_p = euclideanDistance(P[p], P[elem]);

        if (alpha * dist_p_star >= dist_p) {
            N_out_p.push_back(elem);
            if (N_out_p.size() == R) {
                break;
            };
        };
    };

    G[p] = N_out_p;
    return G;

};
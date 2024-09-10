#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<float>> getData(const string& filename){
    vector<vector<float>> data;
    string line;

    ifstream dataFile(filename);
    while (getline(dataFile, line)){
        vector<float> v;
        stringstream ss(line);
        float value;
        while (ss >> value){
            v.push_back(value);
        };
        data.push_back(v);
    };
    dataFile.close();
    return data;
};

void printData(const vector<vector<float>>& data){
    cout << "DATA:" << endl;
    for (const auto& row: data){
        for (const auto& val: row){
            cout << val << " "; 
        };
        cout << endl;
    };
};

int main(){
    const string filename = "data.txt";
    vector<vector<float>> data = getData(filename);

    printData(data);
    return 0;
}
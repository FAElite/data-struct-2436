#include "tracker.h"

#include "ArgumentManager.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    ifstream fin(input);
    ofstream fout(output);
    
    int r = 15;
    int c = 5;

    vector<vector<int>> grid(r, vector<int>(c, 0)); 

    string line;
    read(input, line);

    vector<string> cards = split(line);

    changeGrid(cards, grid);

    printGrid(output, grid);

    return 0;




}

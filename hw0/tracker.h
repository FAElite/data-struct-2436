#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


void read(const string &inputFile, string &inputLine);

vector<string> split(const string &line);

void changeGrid(const vector<string> &cards, vector<vector<int>> &grid);

void printGrid(const string &outputFile, const vector<vector<int>> &grid);

int getRowIndex(const string &value);

int getColIndex(char suit);

#endif

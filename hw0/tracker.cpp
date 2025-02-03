#include "tracker.h"

void read(const string &inputFile, string &inputLine) {
    ifstream file(inputFile);

    getline(file, inputLine);
    file.close();
}


vector<string> split(const string &line) {
    vector<string> cards;
    stringstream ss(line);
    string card;

    while (getline(ss, card, ',')) {
        if (card[0] == ' '){
            card = card.substr(1);  
        } 
        cards.push_back(card);
    }
    return cards;
}

int getRowIndex(const string &value) {
    if (value == "P"){
        return 0;
    }

    if (value == "2"){
        return 1;
    }

    if (value == "3"){
        return 2;
    }

    if (value == "4"){
        return 3;
    }

    if (value == "5"){
        return 4;
    }

    if (value == "6"){
        return 5;
    }

    if (value == "7"){
        return 6;
    }

    if (value == "8"){
        return 7;
    }

    if (value == "9"){
        return 8;
    }

    if (value == "10"){
        return 9;
    }

    if (value == "R"){
        return 10;
    }

    if (value == "N"){
        return 11;
    }

    if (value == "B"){
        return 12;
    }

    if (value == "Q"){
        return 13;
    }

    if (value == "K"){
        return 14;
    }

    return -1; 
}

int getColIndex(char suit) {
    if (suit == 'A'){
        return 0;
    }

    if (suit == 'E'){
        return 1;
    }

    if (suit == 'F'){
        return 2;
    }

    if (suit == 'W'){
        return 3;
    }

    if (suit == 'H'){
        return 4;
    }

    return -1; 
}

void changeGrid(const vector<string> &cards, vector<vector<int>> &grid) {
    for (const string &card : cards) {
        string part = "";
        char suit = ' ';

        for (char c : card) {
            if (isdigit(c) || c == 'P' || c == 'R' || c == 'N' || c == 'B' || c == 'Q' || c == 'K') {
                part += c;
            } 
            else{

                suit = c;
            }
        }

        int row = getRowIndex(part);
        int col = getColIndex(suit);

        if (row != -1 && col != -1) {
            grid[row][col]++;  
        }

    }
}

void printGrid(const string &outputFile, const vector<vector<int>> &grid) {
    ofstream fout(outputFile);

    for (auto &row : grid) {
        for (size_t i = 0; i < row.size(); i++) {
            fout << row[i];
            if (i < row.size() - 1) fout << " "; 

        }

        fout << endl;
    }

    fout.close();
}

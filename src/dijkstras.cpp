// dijsktras.cpp
#include <iostream>
#include <vector> 
#include <map>
// Main Execution
using namespace std;
int main(int argc, char *argv[]) {
    int numTiles;
    while (cin >> numTiles) {
        //vector<char> tileNames(numTiles);
        map<char, int> tiles;
        for (int i = 0; i < numTiles; i++) {
            char tileName;
            int tileCost;
            cin >> tileName >> tileCost;
            tiles.insert(pair<char,int>(tileName, tileCost));
            //tileCosts[i] = tileCost;
        }
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> map(rows);
        for (int i = 0; i < rows; i++) {
            vector<int> mapRow(cols);
            for (int j = 0; j < cols; j++) {
                char temp;
                cin >> temp;
                mapRow[j] = tiles[temp];
            }
            map[i] = mapRow;
        }
        int runnerStartRow, runnerStartCol, runnerEndRow, runnerEndCol;
        cin >> runnerStartRow >> runnerStartCol >> runnerEndRow >> runnerEndCol;
    }
    return 0;
}


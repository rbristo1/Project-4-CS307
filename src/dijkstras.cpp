// dijsktras.cpp
#include <iostream>
#include <vector> 
#include <map>
using namespace std;

//returns total cost
int BFS(vector<pair<int,int>> * path, vector<vector<int>> * map, int runnerStartRow, int runnerStartCol, int runnerEndRow, int runnerEndCol) {
    return 1;
}

// Main Execution
int main(int argc, char *argv[]) {
    int numTiles;
    while (cin >> numTiles) {
        //arranges the different types of tiles and their associated cost into a map
        map<char, int> tiles;
        for (int i = 0; i < numTiles; i++) {
            char tileName;
            int tileCost;
            cin >> tileName >> tileCost;
            tiles.insert(pair<char,int>(tileName, tileCost));
        }

        //finds the dimensions of the map and takes the map in
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> map(rows);
        for (int i = 0; i < rows; i++) {
            vector<int> mapRow(cols);
            for (int j = 0; j < cols; j++) {
                char temp;
                cin >> temp;
                //converts map letters into weights instead
                mapRow[j] = tiles[temp];
            }
            map[i] = mapRow;
        }
        //final stored map is a 2d vector of weights rather than chars

        //finds runner start and end positions
        int runnerStartRow, runnerStartCol, runnerEndRow, runnerEndCol;
        cin >> runnerStartRow >> runnerStartCol >> runnerEndRow >> runnerEndCol;

        //finds path and outputs total size
        vector<pair<int,int>> path;
        cout << BFS(&path, &map, runnerStartRow, runnerStartCol, runnerEndRow, runnerEndCol) << endl;
        //outputs path
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i].first << " " << path[i].second << endl;
        }
    }
    return 0;
}


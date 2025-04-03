// dijsktras.cpp
#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int DIRECTIONS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//returns total cost
int BFS(vector<pair<int,int>> * path, vector<vector<int>> * map, int runnerStartRow, int runnerStartCol, int runnerEndRow, int runnerEndCol) {
    // map[row][column] = weight
    // path = coords the runner moves to

    vector<vector<int>> distances(map->size(), vector<int> (map[0].size(), INT_MAX)); // A vector that gives the distances
    vector<vector<pair<int, int>>> prevNode(map->size(), vector<pair<int, int>>(map[0].size(), make_pair(-1, -1))); // A vector that keeps track of the previous nodes
    vector<vector<bool>> visited(map->size(), vector<bool> (map[0].size(), false)); // A vector that keeps track of all of the visited nodes
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; // Stores the distance, the row, and the column, in that order
    int maxRow = map->size();
    int maxCol = map[0].    size();
    
    visited[runnerStartRow][runnerStartCol] = true;
    q.push(make_pair(0, make_pair(runnerStartRow, runnerStartCol)));

    while (!q.empty()){
        pair<int, int> node = q.top().second;
        int dist = q.top().first;
        q.pop();

        int row = node.first;
        int col = node.second;
        int weight = (*map)[row][col];
        int tempDist = dist + weight;
        for (int i = 0; i < 4; i++) {
            int tempRow = row + DIRECTIONS[i][0];
            int tempCol = col + DIRECTIONS[i][1];



            if (0 <= tempRow && tempRow < maxRow && 0 <= tempCol && tempCol < maxCol) { // Check for bounds
                visited[tempRow][tempCol] = true;
                if (tempDist < distances[tempRow][tempCol]){
                    distances[tempRow][tempCol] = tempDist;
                    prevNode[tempRow][tempCol] = make_pair(row, col);
                    q.push(make_pair(distances[tempRow][tempCol], make_pair(tempRow, tempCol)));
                }


            }

        }
    }

    pair<int, int> pathNodes = make_pair(runnerEndRow, runnerEndCol);
    path->push_back(pathNodes);
    while (pathNodes != make_pair(runnerStartRow, runnerStartCol)) {
        pathNodes = prevNode[pathNodes.first][pathNodes.second];
        path->push_back(pathNodes);
    }
    // At this point, path is backwords, so we need to reverse it.
    reverse(path->begin(), path->end());

    return distances[runnerEndRow][runnerEndCol];
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


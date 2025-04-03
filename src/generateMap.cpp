#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Please use format ./generateMap N" << endl;
        return 1;
    }
    srand(time(0));
    vector<char> tiles;
    int tile = rand()%10;
    if (tile < 3) {
        tile = 3;
    }
    cout << tile << endl;
    for (int i = 0; i < tile; i++) {
        cout << (char)('a' + i) << " " << (rand() % 9) + 1 << endl;
        tiles.push_back('a' + i);
    }
    cout << argv[1] << " " << argv[1] << endl;
    for (int i = 0; i < stoi(argv[1]); i++) {
        for (int j = 0; j < stoi(argv[1]); j++) {
            cout << tiles[rand() % tiles.size()] << " ";
        }
        cout << endl;
    }
    cout << rand() % stoi(argv[1]) << " " << rand() % stoi(argv[1]) << endl;
    cout << rand() % stoi(argv[1]) << " " << rand() % stoi(argv[1]) << endl;

}
#include <iostream>
#include <vector>
using namespace std;

class SudokuSolver {
private:
    int* grid;
    int n;

public:

    SudokuSolver(const vector<vector<int>>& s) {
        int x = 0;
        int dim = s.size();
        n = dim;
        grid = new int[dim * dim];
        for (unsigned int i = 0; i < s.size(); i++) {
            for(unsigned int j = 0; j < s[i].size(); j++)
                grid[i * dim + j] = (int)(s[i][j]);
        }
    }

    void solve() {
        try {
            placeNumber(0);
            cout << "Unsolvable!" << endl;
        }
        catch (char* ex) {
            cout << ex << endl;
            cout << this->toString() << endl;
        }
    }

    void placeNumber(int pos) {
        if (pos == n * n) {
            throw (char*)"Finished!";
        }
        if (grid[pos] > 0) {
            placeNumber(pos + 1);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (checkValidity(i, pos % n, pos / n)) {
                grid[pos] = i;
                placeNumber(pos + 1);
                grid[pos] = 0;
            }
        }
    }

    bool checkValidity(int val, int x, int y) {
        for (int i = 0; i < n; i++) {
            if (grid[y * n + i] == val || grid[i * n + x] == val)
                return false;
        }
        /*int startX = (x / 3) * 3;
        int startY = (y / 3) * 3;
        for (int i = startY; i < startY + 3; i++) {
            for (int j = startX; j < startX + 3; j++) {
                if (grid[i * 9 + j] == val)
                    return false;
            }
        }*/
        return true;
    }

    string toString() {
        string sb;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c[2];
                c[0] = grid[i * n + j] + '0';
                c[1] = '\0';
                sb.append(c);
                sb.append(" ");
            }
            sb.append("\n");
        }
        return sb;
    }
};

int array_add(vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += (arr[i] * (i + 1));
    }
    return sum;
}

int mains() {
    /*const auto& board = vector<vector<int>>{
        vector<int>({ 8,5,0,0,0,2,4,0,0 }),
        vector<int>({ 7,2,0,0,0,0,0,0,9 }),
        vector<int>({ 0,0,4,0,0,0,0,0,0 }),
        vector<int>({ 0,0,0,1,0,7,0,0,2 }),
        vector<int>({ 3,0,5,0,0,0,9,0,0 }),
        vector<int>({ 0,4,0,0,0,0,0,0,0 }),
        vector<int>({ 0,0,0,0,8,0,0,7,0 }),
        vector<int>({ 0,1,7,0,0,0,0,0,0 }),
        vector<int>({ 0,0,0,0,3,6,0,4,0 })
    };*/
    auto board = vector<vector<int>>{
        vector<int>({4,0,0,0}),
        vector<int>({0,4,0,0}),
        vector<int>({0,0,2,0}),
        vector<int>({0,0,0,1})
    };
    int n = 4;
    int k = 11;
    vector<int> occur(n);
    occur[n - 1] = n;                       // Take Maximum Possible Elements For Diagonal
    vector<int> arr(n, n);
    for (int i = 0; i = n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i] = j;
            if (array_add(arr) != k)
                continue;
        }
    }
    SudokuSolver sm(board);
    sm.solve();
    return 0;
}
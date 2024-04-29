#include <iostream>
#include <vector>
using namespace std;

bool issafe(int row, int col, vector<string>& board, int n) {
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    row = duprow;
    col = dupcol;

    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (issafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '-';
        }
    }
}

int main() {
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '-'));

    solve(0, board, ans, n);

    // Output the first solution found
    vector<string>& answer = ans[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

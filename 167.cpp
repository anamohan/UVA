#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int row[9], maxScore, currScore, k, mat[9][9];
bool place(int try_row, int col) {
	for (int prev = 1; prev < col; prev++) {
		if (row[prev] == try_row || abs(row[prev] - try_row + 0.0) == abs(prev - col + 0.0)) {
			return false;
		}
	}
	return true;
}

int score() {
	int sum = 0;
	for (int i = 1; i <= 8; i++) {
		int x = row[i];
		int y = i;
		sum += mat[x][y];
	}
	return sum;
}

void backtrack(int col) {
	for (int try_row = 1; try_row <= 8; try_row++) {
		if (place(try_row, col)) {
			row[col] = try_row;
			if (col == 8) {
				currScore = score();
				if (currScore > maxScore) {
					maxScore = currScore;
				}
			} else {
				backtrack(col + 1);
			}
		}
	}
}

int main() {
	scanf("%d", &k);
	while (k--) {
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		memset(row, 0, sizeof row);
		maxScore = INT_MIN;
		backtrack(1);
		printf("%5d\n", maxScore);
	}
	return 0;
}

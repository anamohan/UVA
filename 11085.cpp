#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>


using namespace std;

int row[9], original[9], minSteps, currSteps;

bool place(int try_row, int col) {
	for (int prev = 1; prev < col; prev++) {
		if (row[prev] == try_row || abs(row[prev] - try_row + 0.0) == abs(prev - col + 0.0)) {
			return false;
		}
	}
	return true;
}

int getSteps() {
	int steps = 0;
	for (int i = 1; i <= 8; i++) {
		int orig_x = original[i];
		int x = row[i];
		if (x != orig_x) {
			steps++;
		}
	}
	return steps;
}

void backtrack(int col) {
	for (int try_row = 1; try_row <= 8; try_row++) {
		if (place(try_row, col)) {
			row[col] = try_row;
			if (col == 8) {
				currSteps = getSteps();
				if (currSteps < minSteps) {
					minSteps = currSteps;
				}
			} else {
				backtrack(col + 1);
			}
		}
	}
}

int main() {
	int caseNum = 1;
	while (scanf("%d %d %d %d %d %d %d %d", &original[1], 
		&original[2], &original[3], &original[4], 
		&original[5], &original[6], &original[7], &original[8]) == 8) {
		
		memset(row, 0, sizeof row);
		minSteps = INT_MAX;
		backtrack(1);
		printf("Case %d: %d\n", caseNum, minSteps);
		caseNum++;
	}
	return 0;
}
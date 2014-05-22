#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int row[9], T, a, b, lineCounter;

bool place(int try_row, int col) {
	for (int prev = 1; prev < col; prev++) {
		if (row[prev] == try_row || (abs(row[prev] - try_row + 0.0) == abs(prev - col + 0.0))) {
			return false;
		}
	}
	return true;
}

void backtrack(int col) {
	for (int try_row = 1; try_row <= 8; try_row++) {
		if (place(try_row, col)) {
			row[col] = try_row;
			if (col == 8 && row[b] == a) {
				printf("%2d      %d", ++lineCounter, row[1]);
				for (int j = 2; j <= 8; j++) {
					printf(" %d", row[j]);	
				}
				printf("\n");
			} else {
				backtrack(col + 1);
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		memset(row, 0, sizeof row);
		lineCounter = 0;
		printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(1);
		if (T) {
			printf("\n");
		}
	}
	return 0;
}
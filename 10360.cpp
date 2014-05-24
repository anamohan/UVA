#include <cstdio>
#include <cstring>

using namespace std;

int killed[1024][1024], T, row, col, population, d, n, res_row, res_col;


int main() {
	scanf("%d", &T);

	while (T--) {
		memset(killed, 0, sizeof(killed[0][0]) * 1024 * 1024);
		scanf("%d", &d);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &row, &col, &population);

			for (int j = row - d; j <= row + d; j++) {
				if (j < 0 || j >= 1024) continue;

				for (int k = col - d; k <= col + d; k++) {
					if (k < 0 || k >= 1024) continue;
					killed[j][k] += population;
				} 
			}
		}

		int maxKilled = -1;
		for (int i = 0; i < 1024; i++) {
			for (int j = 0; j < 1024; j++) {
				if (killed[i][j] > maxKilled) {
					maxKilled = killed[i][j];
					res_row = i;
					res_col = j;
				}
			}
		}
		printf("%d %d %d\n", res_row, res_col, maxKilled);
	}
	return 0;
}
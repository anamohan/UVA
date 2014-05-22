#include <cstdio>
#include <cmath>

using namespace std;

bool all_digits_diff(int n, int m) {
	if (n >= 100000)
		return false;

	int c, mask = 0;
	for (int i = 0; i < 5; i++) {
		c = (int) (n / pow(10.0, i + 0.0)) % 10;
		if ((mask >> c) % 2)
			return false;
		mask |= 1 << c;
	}
	for (int i = 0; i < 5; i++) {
		c = (int) (m / pow(10.0, i + 0.0)) % 10;
		if ((mask >> c) % 2)
			return false;
		mask |= 1 << c;
	}

	return true;
}

int main() {
	int N, num, denom, count = 0;

	while (scanf("%d", &N) == 1) {
		if (N == 0) break;
		int max = 98765 / N;
		bool found = false;
		count++;
		if (count > 1)
			printf("\n");
		for (int i = 1234; i <= max; i++) {
			denom = i;
			num = denom * N;
			if (all_digits_diff(num, denom)) {
				found = true;
				printf("%05d / %05d = %d\n", num, denom, N);
			}
		}
		if (!found) {
			printf("There are no solutions for %d.\n", N);
		}
	}
	return 0;
}
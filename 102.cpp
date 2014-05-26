#include <cstdio>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

long brown[3], green[3], clear[3], min_steps, curr_steps, index;
const string possib[] = { "BGC", "BCG", "GBC", "GCB", "CBG", "CGB" };
int main() {
	while (scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld", &brown[0], &green[0], &clear[0], 
		&brown[1], &green[1], &clear[1], &brown[2], &green[2], &clear[2]) == 9) {
		int comb[] = { 0, 1, 2 };
 
        min_steps = LONG_MAX;
        string res = "BGC";
        index = 0;
		do {
            curr_steps = brown[0] + brown[1] + brown[2] 
  						 + green[0] + green[1] + green[2] 
  						 + clear[0] + clear[1] + clear[2];
 
            for(int i = 0; i < 3; i++) {
                switch(comb[i]) {
                case 0:
                    curr_steps -= brown[i];
                    break;
                case 1:
                    curr_steps -= green[i];
                    break;
                case 2:
                    curr_steps -= clear[i];
                    break;
                }
            }
 
            if(min_steps > curr_steps || (min_steps == curr_steps && possib[index] < res)) {
                min_steps = curr_steps;
                res = possib[index];
            }
 
            index++;
        } while(next_permutation(comb, comb + 3));
        cout << res << " " << min_steps << endl;
	}
	return 0;
}
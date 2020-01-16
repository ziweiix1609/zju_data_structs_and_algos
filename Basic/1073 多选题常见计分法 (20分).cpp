#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, optnum, truenum, tmp, maxcnt = 0;
	int hash[] = {1, 2, 4, 8, 16}, opt[1010][110] = {0};
	char c;
	scanf("%d %d", &n, &m);
	vector<int> tot(m), trueopt(m);
	vector<vector<int>> cnt(m, vector<int>(5));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &tot[i], &optnum, &truenum);
		for (int j = 0; j < truenum; j++) {
			scanf(" %c", &c);
			trueopt[i] += hash[c-'a'];
		}
	}
	for (int i = 0; i < n; i++) {
		double grade = 0;
		for (int j = 0; j < m; j++) {
			getchar();
			scanf("(%d", &tmp);
			for (int k = 0; k < tmp; k++) {
				scanf(" %c)", &c);
				opt[i][j] += hash[c-'a'];
			}
			int exor = opt[i][j] ^ trueopt[j];
			if (exor) {
				if ((opt[i][j] | trueopt[j]) == trueopt[j])
					grade += tot[j] * 1.0 / 2;
				if (exor)
					for (int k = 0; k < 5; k++)
						if (exor & hash[k]) cnt[j][k]++;
			} else grade += tot[j];
		}
		printf("%.1f\n", grade);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 5; j++)
			maxcnt = maxcnt > cnt[i][j] ? maxcnt : cnt[i][j];
	if (maxcnt == 0) printf("Too simple\n");
	else
		for (int i = 0; i < m; i++)
			for (int j = 0; j < cnt[i].size(); j++)
				if (maxcnt == cnt[i][j])
					printf("%d %d-%c\n", maxcnt, i+1, 'a'+j);
	return 0;
}

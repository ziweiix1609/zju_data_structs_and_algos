#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct peo {
	int id, ge, gi, fin;
	vector<int> choice;
};
bool cmp(peo &a, peo &b) { return a.fin != b.fin ? a.fin > b.fin : a.ge > b.ge; }
bool cmp2(peo &a, peo &b) { return a.id < b.id; }
int main() {
	int n, m, k, quota[110];
	scanf("%d%d%d", &n, &m, &k);
	vector<peo> stu(n), sch[110];
	for (int i = 0; i < m; i++)
		scanf("%d", &quota[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		stu[i].id = i;
		stu[i].fin = stu[i].ge + stu[i].gi;
		stu[i].choice.resize(k);
		for (int j = 0; j < k; j++)
			scanf("%d", &stu[i].choice[j]);
	}
	sort(stu.begin(), stu.end(), cmp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			int sid = stu[i].choice[j];
			int lastindex = sch[sid].size() - 1;
			if (sch[sid].size() < quota[sid] || stu[i].fin == sch[sid][lastindex].fin && stu[i].ge == sch[sid][lastindex].ge) {
				sch[sid].push_back(stu[i]);
				break;
			}
		}
	for (int i = 0; i < m; i++) {
		sort(sch[i].begin(), sch[i].end(), cmp2);
		for (int j = 0; j < sch[i].size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", sch[i][j].id);
		}
		printf("\n");
	}
	return 0;
}

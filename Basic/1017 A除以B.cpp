#include <iostream>
using namespace std;
int main() {
	string a, q;
	int b, r = 0;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		r = r * 10 + a[i] - '0';
		if (r >= b) {
			q.push_back(r/b + '0');
			r %= b;
		} else q.push_back('0');
	}
	while (q.length() > 0 && q[0] == '0') q.erase(q.begin());
	cout << (q.length() != 0 ? q : "0") << ' ' << r;
	return 0;
}

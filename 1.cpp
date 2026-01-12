#include <iostream>
#include <string>
#include <clocale>
#include <map>
#define int long long
using namespace std;

int aa(int a) {
	if (a < 1) return 0;
	if (a <= 2) {
		return 1;
	}
	return aa(a - 1) + aa(a - 2);
}

signed main() {
	int n;
	cin >> n;
	cout << aa(n);
}

#include <iostream>
#include <cstring>
using namespace std;

int n,m;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//기저사례 : 모두 짝이 있는 경우
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;

}

int main() {
	int cnt;
	

	cin >> cnt;
	while (cnt--) {
		
		areFriends[10][10];
		memset(areFriends, 0, sizeof(areFriends));
		cin >> n >> m;
		for (int numFri = 0; numFri < m; numFri++) {
			int pair1, pair2;
			cin >> pair1 >> pair2;
			areFriends[pair1][pair2] = areFriends[pair2][pair1] = true;
		}
		bool taken[10] = { false, };
		cout << countPairings(taken) << endl;
		
	}
	
	return 0;

}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int MAX;
int symmetricSW = 0;
int antisymmetricSW = 0;
string symmetric(vector<pair<int, int>> v) {
	pair<int, int> posit;
	bool isSearch = false;
	for (int i = 0; i < MAX; i++) {
		posit = v[i];
		for (int j = 0; j < MAX; j++) {
			if (posit.first == v[j].second && posit.second == v[j].first) {
				isSearch = true;
				break;
			}
			else
				isSearch = false;
		}
		if (isSearch == false) {
			symmetricSW = 1;
			return "non-symmetric";
		}
			
	}
	return "symmetric";
}
string antisymmetric(vector<pair<int, int>> v) {
	pair<int, int> posit;
	bool isSearch = false;
	for (int i = 0; i < MAX; i++) {
		posit = v[i];
		for (int j = 0; j < MAX; j++) {
			if (posit.first == v[j].second && posit.second == v[j].first && i != j) {
				isSearch = true;
				break;
			}
			else
				isSearch = false;
		}
		if (isSearch == true) {
			antisymmetricSW = 1;
			return "non-antisymmetric";
		}

	}
	return "antisymmetric";
}



int input_to_Int(string str, string n, string m) {

	int positionN = str.find(n) + 1;
	int positionM = str.find(m) - 1;
	return atoi(str.substr(positionN, positionM).c_str());
}

int main() {
	// 집합 R의 튜플들
	cin >> MAX;
	vector<pair<int, int>> v(MAX);

	cout << "(a,b) 의 형태로 튜플을 만들어주세요" << endl;
	for (int i = 0; i < MAX; i++) {
		int a, b;
		string tmp;
		cin >> tmp;
		a = input_to_Int(tmp, "(", ",");
		b = input_to_Int(tmp, ",", ")");
		v[i] = make_pair(a, b);
	}

	for (int i = 0; i < MAX; i++) {
		if (i == 0)
			cout << "R = {";
		cout << "(" << v[i].first << ", " << v[i].second << "), ";
	}
	cout << "\b\b}\n\n";

	if (symmetricSW != 0 && antisymmetricSW != 0) {
		cout << "result : " << symmetric(v) << endl;
		cout << "result : " << antisymmetric(v);
	}
	else {
		cout << "result : none" ;
	}


}

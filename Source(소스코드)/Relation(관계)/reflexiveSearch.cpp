#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int MAX;
int R_setSize;
string solved(vector<pair<int, int>> v, vector<int> Rset) {
	queue<pair<int, int>> Essential;
	bool isSearch = false;
	for (int j = 0; j < R_setSize; j++) {
		Essential.push(make_pair(Rset[j], Rset[j]));
		for (int i = 0; i < MAX; i++) {
			if (v[i].first == Essential.front().first && v[i].second == Essential.front().second) {
				isSearch = true;
				break;
			} 	
		}
		if (isSearch == false) {
			return "Non- reflexive";
		}

		Essential.pop();

	}
	return "reflexive";
}

int input_to_Int(string str, string n, string m) {

	int positionN = str.find(n) + 1;
	int positionM = str.find(m) - 1;
	return atoi(str.substr(positionN, positionM).c_str());
}

int main() {

	cin >> R_setSize;
	vector<int> Rset(R_setSize);
	
	for (int i = 0; i < R_setSize; i++) {
		cin>>Rset[i];
	}

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

	cout << "result : " << solved(v,Rset);


}

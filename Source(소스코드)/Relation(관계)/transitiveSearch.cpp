#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int MAX;
string solved(vector<pair<int,int>> v) {
	pair<int, int> posit;
	//isCompare
	pair<int, int> isCompare;
	for (int i = 0; i < MAX; i++) {
		posit = v[i];
		for (int j = 0; j < MAX; j++) {
			//자신 제외
			if (i != j) {

				//전이적 조건 1
				if (posit.second == v[j].first) {
					isCompare = make_pair(posit.first, v[j].second);

					//존재 유무
					for (int k = 0; k < MAX; k++) {
						if (isCompare.first != v[k].first || isCompare.second != v[k].second) {
							return "transitive : false";
							
						}
					}
				}
			}
		}
	}
	return "transitive : true";
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

	cout <<"result : "<<solved(v);
	
	
}

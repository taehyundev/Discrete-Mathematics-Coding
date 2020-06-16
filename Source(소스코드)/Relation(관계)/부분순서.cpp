#include <iostream>
using namespace std;
int matrix[100][100];
bool isReflexive(int max) {
	//반사적
	for (int i = 0; i < max; i++)
		if (matrix[i][i] != 1)
			return false;
	return true;
}

bool isAntisymmetirc(int max) {
	//반대칭적
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++)
			if ((matrix[i][j] == 1 && matrix[j][i] == 0) || (matrix[i][j] == 0 && matrix[j][i] == 1))
				return true;
	return false;
}

bool transitive(int max) {
	//전이적
	for (int cnt = 0; cnt < max; cnt++) 
		for (int i = 0; i < max; i++) 
			for (int j = 0; j < max; j++) 
				if (matrix[i][cnt] == 1 && matrix[cnt][j]==1) 
					if (matrix[i][j] != 1)
						return false;
	return true;
}

bool partialOrder(int loop_max) {
	// reflexive , antisymmetric, transitive 판별
	if (isReflexive(loop_max) && isAntisymmetirc(loop_max) && transitive(loop_max)) {
		return true;
	}
}
int main() {

	int n;
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	if (partialOrder(n))
		cout << "부분순서이다.";
	else
		cout << "부분순서가 아니다.";
}
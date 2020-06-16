#include <iostream>
using namespace std;
int matrix[100][100];
bool isReflexive(int max) {
	//�ݻ���
	for (int i = 0; i < max; i++)
		if (matrix[i][i] != 1)
			return false;
	return true;
}

bool isSymmetirc(int max) {
	//��Ī��
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++)
			if ((matrix[i][j] == 1 && matrix[j][i] == 0) || (matrix[i][j] == 0 && matrix[j][i] == 1))
				return false;
	return true;
}

bool transitive(int max) {
	//������
	for (int cnt = 0; cnt < max; cnt++)
		for (int i = 0; i < max; i++)
			for (int j = 0; j < max; j++)
				if (matrix[i][cnt] == 1 && matrix[cnt][j] == 1)
					if (matrix[i][j] != 1)
						return false;
	return true;
}

bool partialOrder(int loop_max) {
	// reflexive , antisymmetric, transitive �Ǻ�
	if (isReflexive(loop_max) && isSymmetirc(loop_max) && transitive(loop_max)) {
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
		cout << "��ġ�����̴�.";
	else
		cout << "��ġ���谡 �ƴϴ�.";
}
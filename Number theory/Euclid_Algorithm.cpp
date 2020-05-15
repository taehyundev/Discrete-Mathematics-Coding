#include <iostream>
using namespace std;
class gcd {
private:
	int x, y;
	int Remainder;
	int value;
public :
	gcd(int a,int b);
	int Euclid();
};
gcd::gcd(int a, int b) {
	if (a >= b) {x = a; y = b;}
	else if (a < b) { x = b; y = a; }
}
int gcd::Euclid() {
	do {
		Remainder = x % y;
		value = x / y;
		cout << x << " = " << y << " * " << value << " + " << Remainder << endl;
		x = y;
		y = Remainder;
	} while (Remainder != 0);
	return x;
}

int main() {
	int x, y;
	cout << "gcd(x,y)" << endl<<">> ";
	cin >> x >> y;
	gcd gcd(x,y);
	int gcd_value=gcd.Euclid();
	cout << "최대 공약수는 " << gcd_value << "입니다." << endl;
}
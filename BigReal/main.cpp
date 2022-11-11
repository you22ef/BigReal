#include "BigReal.h"


int main() {
	BigReal b;
	BigReal b1("-3245.13445");
	BigReal b2("-1.0");

	BigReal b3 = b1 + b2;
	BigReal b4 = b1 - b2;

	cout << b3 << " " << b4;


	


}
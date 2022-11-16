#include "BigReal.h"


int main() {
	{
		cout << "//-----------------test-1--------------\n";
		BigReal b1("-2.391");
		BigReal b2("1.956");

		BigReal b3 = b1 + b2;
		BigReal b4 = b1 - b2;
		BigReal b5 = b2 - b1;

		cout << "b1 = " << b1 << '\n' << "b2 = " << b2 << '\n';
		cout << "b1 + b2 = " << b3 << '\n';
		cout << "b1 - b2 = " << b4 << '\n';
		cout << "b2 - b1 = " << b5 << '\n';
		cout << "b1 sign is : " << b1.sign() << '\n';
		cout << "b1 < b2 : " <<  (b1 < b2) << '\n';
		cout << "b1 > b2 : " << (b1 > b2) << '\n';
		cout << "b1 size : " << b1.size() << '\n';
	}
	{
		cout << "//-----------------test-2--------------\n";
		BigReal b1("-9.391");
		BigReal b2("-9.956");

		BigReal b3 = b1 + b2;
		BigReal b4 = b1 - b2;
		BigReal b5 = b2 - b1;

		cout << "b1 = " << b1 << '\n' << "b2 = " << b2 << '\n';
		cout << "b1 + b2 = " << b3 << '\n';
		cout << "b1 - b2 = " << b4 << '\n';
		cout << "b2 - b1 = " << b5 << '\n';
		cout << "b1 sign is : " << b1.sign() << '\n';
		cout << "b1 < b2 : " << (b1 < b2) << '\n';
		cout << "b1 > b2 : " << (b1 > b2) << '\n';
		cout << "b1 size : " << b1.size() << '\n';
	}
	{
		cout << "//-----------------test-3--------------\n";
		BigReal b1("5.34123");
		BigReal b2("-5.956");

		BigReal b3 = b1 + b2;
		BigReal b4 = b1 - b2;
		BigReal b5 = b2 - b1;

		cout << "b1 = " << b1 << '\n' << "b2 = " << b2 << '\n';
		cout << "b1 + b2 = " << b3 << '\n';
		cout << "b1 - b2 = " << b4 << '\n';
		cout << "b2 - b1 = " << b5 << '\n';
		cout << "b1 sign is : " << b1.sign() << '\n';
		cout << "b1 < b2 : " << (b1 < b2) << '\n';
		cout << "b1 > b2 : " << (b1 > b2) << '\n';
		cout << "b1 size : " << b1.size() << '\n';
	}
	{
		cout << "//-----------------test-4--------------\n";
		BigReal b1("-9.391");
		BigReal b2("9.956");

		BigReal b3 = b1 + b2;
		BigReal b4 = b1 - b2;
		BigReal b5 = b2 - b1;

		cout << "b1 = " << b1 << '\n' << "b2 = " << b2 << '\n';
		cout << "b1 + b2 = " << b3 << '\n';
		cout << "b1 - b2 = " << b4 << '\n';
		cout << "b2 - b1 = " << b5 << '\n';
		cout << "b1 sign is : " << b1.sign() << '\n';
		cout << "b1 < b2 : " << (b1 < b2) << '\n';
		cout << "b1 > b2 : " << (b1 > b2) << '\n';
		cout << "b1 size : " << b1.size() << '\n';
	}
}
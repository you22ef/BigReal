#include "BigReal.h"


int main() {
	BigReal b;
	BigReal b1("36182368126381263861.2312313492374923874982734987");
	BigReal b2("894631846816481648164.999237947239472938748923");

	BigReal b3 = b1 + b2;
	BigReal b4 = b1 - b2;

	cout << b3 << " " << b4;

}
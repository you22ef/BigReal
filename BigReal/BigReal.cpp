#include "BigReal.h"

BigReal::BigReal(double realNumber)
{
	if (realNumber == 0.0) {
		intPart = to_string(0);
		decPart.push_back(0);
	}
	else {

		intPart = to_string((long)realNumber);
	
		string decimalPart = to_string(realNumber - int(realNumber)).substr(2);
	
		for (int i = decimalPart.size()-1; i >= 0; i--) {
			decPart.push_back(int(decimalPart[i]) - 48);
		}
	}
}

BigReal::BigReal(string realNumber)
{
	int dotPos=0;
	for (int i = realNumber.size() - 1; i >= 0; i--) {
		if (realNumber[i] == '.') {
			dotPos = i;
			break;
		}
		decPart.push_back(int(realNumber[i]) - 48);
	}
	intPart = realNumber.substr(0, dotPos);
}

BigReal::BigReal(BigDecimalInt bigInteger)
{
	intPart = bigInteger;
	decPart.push_back(0);
}


BigReal& BigReal::operator=(BigReal& other)
{
	cout << "assign" << endl;
	if (this != &other) {
		intPart = other.intPart;
		decPart = other.decPart;
	}
	return *this;
}

BigReal& BigReal::operator=(BigReal&& other)
{
	cout << "move assign" << endl;
	if (this != &other) {
		intPart = other.intPart;
		decPart = other.decPart;
	}
	return *this;
}




BigReal BigReal::operator+(BigReal other)
{
	BigReal result;
	BigReal cp = *this;
	if (cp.sign() == 1 && other.sign() == 1) {
		result.intPart = cp.intPart + other.intPart;
		while (cp.decPart.size() < other.decPart.size()) {
			cp.decPart.insert(cp.decPart.begin(), 0);
		}
		while (cp.decPart.size() > other.decPart.size()) {
			other.decPart.insert(other.decPart.begin(), 0);
		}
		int temp;
		int carry;
		for (int i = 0; i < cp.decPart.size(); i++) {
			temp = (cp.decPart[i] + other.decPart[i]) % 10;
			carry = (cp.decPart[i] + other.decPart[i]) / 10;
			result.decPart.push_back(temp);
			if (i == cp.decPart.size() - 1) {
				if (carry != 0) {
					result.intPart = result.intPart + BigDecimalInt("1");
				}
			}
			else {
				cp.decPart[i + 1] += carry;
			}
		}

	}
	else if (cp.sign() == 0 && other.sign() == 1) {
		cp.intPart.setNumber(cp.intPart.getNumber());
		result = cp - other;
		result.intPart.setNumber('-' + result.intPart.getNumber());
	}
	else if (cp.sign() == 0 && other.sign() == 0) {
		cp.intPart.setNumber(cp.intPart.getNumber());
		other.intPart.setNumber(other.intPart.getNumber());
		result = cp + other;
		result.intPart.setNumber('-' + result.intPart.getNumber());
	}
	else if (cp.sign() == 1 && other.sign() == 0) {
		other.intPart.setNumber(other.intPart.getNumber());
		result = cp - other;
	}
	return result;
}

BigReal BigReal::operator-(BigReal other)
{
	BigReal result;
	BigReal cp = *this;


	if (cp > other && other.sign() == 1) {
 		result.intPart = cp.intPart - other.intPart;
		while (cp.decPart.size() < other.decPart.size()) {
			cp.decPart.insert(cp.decPart.begin(), 0);
		}
		while (cp.decPart.size() > other.decPart.size()) {
			other.decPart.insert(other.decPart.begin(), 0);
		}
		for (int i = 0; i < cp.decPart.size(); i++) {
			if (i < (cp.decPart.size() - 1)) {
				if (cp.decPart[i] < other.decPart[i]) {
					cp.decPart[i] += 10;
					cp.decPart[i + 1]--;

				}
			}
			if(i==cp.decPart.size()-1) {
				if (cp.decPart[i] < other.decPart[i]) {
					cp.decPart[i] += 10;
					result.intPart = result.intPart - BigDecimalInt("1");
				}
			}
			result.decPart.push_back(cp.decPart[i] - other.decPart[i]);
		}
	}
	else if (cp > other && other.sign()==0) {
		other.intPart.setNumber(other.intPart.getNumber());
		result = cp + other;
	}
	else if (cp < other && other.sign() == 1 && cp.sign()==1) {

		result = other - cp;
		result.intPart.setNumber('-' + result.intPart.getNumber());
	}
	else if (cp < other && other.sign() == 0 && cp.sign()==0) {
		cp.intPart.setNumber(cp.intPart.getNumber());
		other.intPart.setNumber(other.intPart.getNumber());
		result = cp - other;
		result.intPart.setNumber('-' + result.intPart.getNumber());
	}
	else if (cp < other && other.sign() == 1 && cp.sign() == 0) {
		cp.intPart.setNumber(cp.intPart.getNumber());
		other.intPart.setNumber(other.intPart.getNumber());
		result = cp + other;
		result.intPart.setNumber('-' + result.intPart.getNumber());
	}
	return result;
}

bool BigReal::operator<(BigReal anotherReal)
{
	
	if (intPart < anotherReal.intPart ) {
		return true;
	}
	else if (intPart > anotherReal.intPart) {
		return false;
	}
	else {
		for (int i = decPart.size() - 1; i >= 0 ; i--) {
			if (decPart[i] < anotherReal.decPart[i]) {
				return true;
			}
		}
	}

	return false;
}

bool BigReal::operator>(BigReal anotherReal)
{
	
	if (intPart > anotherReal.intPart) {
		return true;
	}
	else if (intPart < anotherReal.intPart) {
		return false;
	}
	else {
		for (int i = decPart.size() - 1; i >= 0; i--) {
			if (decPart[i] > anotherReal.decPart[i]) {
				return true;
			}

		}
	}

	return false;

	
}

int BigReal::size()
{
	return intPart.size()+decPart.size();
}

bool BigReal::operator==(BigReal anotherReal)
{
	
	return !(*this <anotherReal) && !(*this>anotherReal);
}

int BigReal::sign()
{
	return intPart.sign();
}

ostream& operator<<(ostream& out, BigReal& num)
{

	out << num.intPart;
	out << '.';
	for (int i = num.decPart.size()-1; i>=0; i--) {
		out << num.decPart[i];
	}
	return out;
}

istream& operator>>(istream& in, BigReal& num)
{
	string realNumber;
	in >> realNumber;
	num = BigReal(realNumber);
	return in;

}

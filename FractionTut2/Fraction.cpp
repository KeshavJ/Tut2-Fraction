#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
													// Declaration of all methods
	void setNumDenom(int, int);
	Fraction getNumDenom();
	Fraction add(Fraction);
	Fraction subtract(Fraction);
	Fraction multiply(Fraction);
	Fraction divide(Fraction);
	void print();
	int hcf(int, int);
	Fraction();
	Fraction(int, int);								//Constructor declaration
	~Fraction();									//Destructor declaration
};

Fraction::Fraction() {
}

Fraction::~Fraction() {
}

Fraction::Fraction(int n, int d) {					//Default constructor
	numerator = n;
	denominator = d;
}

void Fraction::setNumDenom(int num, int den) {		//Mutator function
	numerator = num;
	denominator = den;
}

Fraction Fraction::getNumDenom() {					//Accessor function
	return Fraction(numerator, denominator);
}

Fraction Fraction::add(Fraction f) {
	return Fraction(((numerator*f.denominator) + (f.numerator * denominator)), (denominator * f.denominator));
}

Fraction Fraction::subtract(Fraction f) {
	return Fraction(((numerator*f.denominator) - (f.numerator * denominator)), (denominator * f.denominator));
}

Fraction Fraction::multiply(Fraction f) {
	return Fraction((numerator*f.numerator), (denominator * f.denominator));
}

Fraction Fraction::divide(Fraction f) {
	return Fraction((numerator * f.denominator), (denominator * f.numerator));
}

int Fraction::hcf(int n, int d) {
	if (d == 0){
		return n;
	}
	else {
		return
			hcf(d, n % d);
	}
}

void Fraction::print() {
	int i = 0;
	int a = numerator;
	int b = denominator;
	int rem = a%b;									//gets remainder
	int hcf1 = hcf(a, b);							//hcf for numerator & denominator
	int hcf2 = hcf(rem, b);							//hcf for remainder and denominator

		if (a > b || (-1)*a > b || a > (-1)*b)			// counts how many times the denominator goes to te numerator if it is an improper fraction
		{
			if (a < 0)
			{
				do
				{
					a += b;
					i++;
				} while (a < 0);
			}

			else
			{
				do
				{
					a -= b;
					i++;
				} while (a > 0);
			}
		}

		if ((i - 1) == 0)
		{

			cout << a / hcf1 << "/" << b / hcf1 << endl;
		}
		else {

			cout << i - 1 << " " << rem / hcf2 << "/" << b / hcf2 << endl;
		}
	}


int main() {
	Fraction fract;
	int num, den;

	cout << "Enter numerator" << endl;
	cin >> num;
	cout << "Enter denominator" << endl;
	cin >> den;

	fract.setNumDenom(num, den);
	fract.print();

}
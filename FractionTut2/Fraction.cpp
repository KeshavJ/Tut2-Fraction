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
	Fraction operator+(Fraction &);  // allows f1+f2
	Fraction operator-(Fraction &); // allows f1-f2
	Fraction();
	Fraction(int, int);								//Constructor declaration
	~Fraction();									//Destructor declaration
};

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
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

Fraction Fraction::operator+(Fraction &f) {
	return Fraction(((numerator*f.denominator) + (denominator*f.numerator)), (denominator * f.denominator));
}

Fraction Fraction::operator-(Fraction &f) {
	return Fraction(((numerator*f.denominator) - (denominator*f.numerator)), (denominator * f.denominator));
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


	if (a > b)			// counts how many times the denominator goes to te numerator if it is an improper fraction
	{
		
			do
			{
				a -= b;
				i++;
			} while (a > 0);
		}

		if ((i) == 0)
		{

			cout << a/hcf1 << "/" << b/hcf1;
		}
		else {

			cout << i-1 << " " << rem / hcf2 << "/" << b / hcf2;
		}
	}



int main() {
	Fraction fract1, fract2, fract3;
	int num, den;

	cout << "Enter numerator of fraction 1" << endl;
	cin >> num;
	cout << "Enter denominator fraction 1" << endl;
	cin >> den;
	fract1.setNumDenom(num, den);

	cout << "Enter numerator of fraction 2" << endl;
	cin >> num;
	cout << "Enter denominator fraction 2" << endl;
	cin >> den;
	fract2.setNumDenom(num, den);

	fract1.print();
	cout << " + ";
	fract2.print();
	cout << " = ";

	//overloading the + operator which allows addition
	fract3 = fract1 + fract2;
	fract3.print();
	cout << endl;

}
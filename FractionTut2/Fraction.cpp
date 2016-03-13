#include <iostream>

using namespace std;

class Fraction {

public:
	int numerator;
	int denominator;
									// Declaration of all methods
	void setNumDenom(int, int);
	Fraction getNumDenom();
	int hcf(int, int);
	Fraction operator+(Fraction &);	// allows addition of objects fract1+fract2
	Fraction operator-(Fraction &);	// allows subtraction of objects fract1-fract2
	Fraction operator*(Fraction &);
	Fraction operator/(Fraction &);
	friend ostream& operator << (ostream &, const Fraction &); 
	friend istream& operator >> (istream &, const Fraction &);
	Fraction();
	Fraction(int, int);	//Constructor declaration
	~Fraction();	//Destructor declaration
};

Fraction::Fraction() {
}

Fraction::~Fraction() {
}

Fraction::Fraction(int n, int d) {	//constructor with parameters
	numerator = n;
	denominator = d;
}

void Fraction::setNumDenom(int num, int den) {	//Mutator function
	numerator = num;
	denominator = den;
}

Fraction Fraction::getNumDenom() {	//Accessor function
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator+(Fraction &f) {
	return Fraction(((numerator*f.denominator) + (denominator*f.numerator)), (denominator * f.denominator));
}

Fraction Fraction::operator-(Fraction &f) {
	return Fraction(((numerator*f.denominator) - (denominator*f.numerator)), (denominator * f.denominator));
}

Fraction Fraction::operator*(Fraction &f) {
	return Fraction((numerator*f.numerator), (denominator * f.denominator));
}


Fraction Fraction::operator/(Fraction &f) {
	return Fraction((numerator*f.numerator), (denominator * f.denominator));
}

int Fraction::hcf(int n, int d) {
	if (d == 0) {
		return n;
	}
	else {
		return
			hcf(d, n % d);
	}
}

 istream &operator >> (istream &input, Fraction &frac) {
	input >> frac.numerator >> frac.denominator; 
	return input;
	
}

 ostream &operator << (ostream &output, Fraction &frac) {
	 int i = 0;
	 int a = frac.numerator;
	 int b = frac.denominator;
	 int rem = a % b;	//gets remainder
	 int hcf1 = frac.hcf(a, b);	//hcf for numerator & denominator
	 int hcf2 = frac.hcf(rem, b);		//hcf for remainder and denominator

	 if (a > b)	// counts how many times the denominator goes to te numerator if it is an improper fraction
	 {

		 do
		 {
			 a -= b;
			 i++;
		 } while (a >= 0);
	 }

	 if ((i) == 0)
	 {
		 output << a/hcf1 << "/" << b/hcf1;
	 }
	 else {
		 output << i - 1 <<" " << rem/ hcf2 << "/" << b/hcf2;
	 }
	return output;
	
}

int main() {
	Fraction fract1, fract2, fract3;
	int num, den;

	cout << "Enter the numerator and denominator of the First Fraction" << endl;
	cin >> fract1;
	cout << "Enter the numerator and denominator of the Second Fraction" << endl;
    cin >> fract2;


	cout << fract1 << " + " << fract2 << " = ";
	fract3 = fract1 + fract2;
	cout << fract3 << endl;
	cout << endl;	

	cout << fract1 << " - " << fract2 << " = ";
	fract3 = fract1 - fract2;
	cout << fract3 << endl;
	cout << endl;

	cout << fract1 << " * " << fract2 << " = ";
	fract3 = fract1 * fract2;
	cout << fract3 << endl;
	cout << endl;

	cout << fract1 << " / " << fract2 << " = ";
	fract3 = fract1 / fract2;
	cout << fract3 << endl;
	cout << endl;
}

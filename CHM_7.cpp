#include <iostream>
#include <cmath>

using namespace std;

float Function(float x)

{
	return (log(x * x + 1)/log(10)) /(x);

}

float Gaussian_metod(float a, float b, int m)

{
	const int n = 5;
	const double Xi[n] = { -0.906180,-0.538470,0,0.906180,0.538470 };
	const double Ci[n] = { 0.236927, 0.478629, 0.568889, 0.236927, 0.478629 };
	double ra = (b - a) / 2;
	double su = (a + b) / 2;
	double Q, S = 0.0;
	for (int i = 0; i < n; i++)
	{
		Q = su + ra * Xi[i];
		S += Ci[i] * Function(Q);
	}
	return ra * S;
}

void Trapeze_metod(float a, float b, int n, float epsilon)

{
	double h, x, s = 0, s_old;

	do

	{
		h = (b - a) / n;

		s_old = s;
		s = 0;

		for (x = a; x < b; x += h)
			s += (Function(x + h) + Function(x)) / 2 * h;
	} 
	while ((abs(s_old - s) > epsilon) && (n *= 2));
	cout << "I = " << s;

}


int main()

{
	float a, b, epsilon;
	float s = 0;
	int m = 2, n = 61;
	cout << "Enter a, b and epsilon: ";
	cin >> a >> b >> epsilon;
	cout << "Method of trapezes:" << endl;
	Trapeze_metod(a, b, n, epsilon);
	cout << endl << "Method of Gauss:" << endl;
	for (int i = 0; i < m; ++i)
	{
		s += Gaussian_metod(a + i * (b - a) / m, a + (i + 1) * (b - a) / m, m);
	}
	cout << "I = " << s << endl;

	return 0;
}

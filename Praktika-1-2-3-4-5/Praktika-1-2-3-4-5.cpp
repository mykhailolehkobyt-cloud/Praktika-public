#include <cmath>
#include <iostream>

double Getsum(double arr[], int size)
{
	double sumabs = 0;
	for (int i = 0; i < size; i++)
	{
		sumabs += fabs(arr[i]);
	}
	return sumabs;
}

double GetProductOfFractions(double arr[], int size)
{
	double sort = 1;
	for (int i = 0; i < size; i++)
	{
		sort = sort * (1.0 / arr[i]);
	}
	return sort;
}



int main()
{
	using namespace std;
	double A[6] = { -2.3, 6.2, 5.8, -3.4, 7.1, 0.05 };
	double B[6] = { 3.0, -2.3, 4.1, 2.5, 6.8, 4.5 };

	double X = Getsum(A, 6);
	double Y = Getsum(B, 6);

	double a = GetProductOfFractions(A, 6);
	double b = GetProductOfFractions(B, 6);

	double p = (a + b) / (X - Y);
	double W;

	if (p > 0)
	{
		W = a * X + Y;
	}
	else
	{
		W = b * X + Y;
	}
	cout << "Result W: " << W << endl;

	return 0;
}

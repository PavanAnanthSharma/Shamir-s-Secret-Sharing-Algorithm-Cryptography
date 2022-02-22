// C++ implementation of shamir’s
// secret sharing algorithm

#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate the value
// of y 
// y = poly[0] + x*poly[1] + x^2*poly[2] + ...
int calculate_Y(int x, vector<int>& poly) 
{
	// Initializing y 
	int y = 0;
	int temp = 1;

	// Iterating through the array
	for (auto coeff : poly) {

		// Computing the value of y
		y = (y + (coeff * temp));
		temp = (temp * x);
	}
	return y;
}

// Function to perform the secret
// sharing algorithm and encode the
// given secret
void secret_sharing(int S, vector<pair<int, int> >& points,
					int N, int K)
{
	// A vector to store the polynomial
	// coefficient of K-1 degree
	vector<int> poly(K);

	// Randomly choose K - 1 numbers but
	// not zero and poly[0] is the secret
	// create polynomial for this

	poly[0] = S;

	for (int j = 1; j < K; ++j) {
		int p = 0;
		while (p == 0)

			// To keep the random values
			// in range not too high
			// we are taking mod with a
			// prime number around 1000
			p = (rand() % 997);

		// This is to ensure we did not
		// create a polynomial consisting
		// of zeroes.
		poly[j] = p;
	}

	// Generating N points from the
	// polynomial we created
	for (int j = 1; j <= N; ++j) {
		int x = j;
		int y = calculate_Y(x, poly);

		// Points created on sharing
		points[j - 1] = { x, y };
	}
}

// This structure is used for fraction
// part handling multiplication
// and addition of fractiontion
struct fraction {
	int num, den;

	// A fraction consists of a
	// numerator and a denominator
	fraction(int n, int d)
	{
		num = n, den = d;
	}

	// If the fraction is not
	// in its reduced form
	// reduce it by dividing
	// them with their GCD
	void reduce_fraction(fraction& f)
	{
		int gcd = __gcd(f.num, f.den);
		f.num /= gcd, f.den /= gcd;
	}

	// Performing multiplication on the
	// fraction
	fraction operator*(fraction f)
	{
		fraction temp(num * f.num, den * f.den);
		reduce_fraction(temp);
		return temp;
	}

	// Performing addition on the
	// fraction
	fraction operator+(fraction f)
	{
		fraction temp(num * f.den + den * f.num,
					den * f.den);

		reduce_fraction(temp);
		return temp;
	}
};

// Function to generate the secret
// back from the given points
// This function will use Lagrange Basis Polynomial
// Instead of finding the complete Polynomial
// We only required the poly[0] as our secret code,
// thus we can get rid of x terms
int Generate_Secret(int x[], int y[], int M)
{

	fraction ans(0, 1);

	// Loop to iterate through the given
	// points
	for (int i = 0; i < M; ++i) {

		// Initializing the fraction
		fraction l(y[i], 1);
		for (int j = 0; j < M; ++j) {

			// Computing the lagrange terms
			if (i != j) {
				fraction temp(-x[j], x[i] - x[j]);
				l = l * temp;
			}
		}
		ans = ans + l;
	}

	// Return the secret
	return ans.num;
}

// Function to encode and decode the
// given secret by using the above
// defined functions
void operation(int S, int N, int K)
{

	// Vector to store the points
	vector<pair<int, int> > points(N);

	// Sharing of secret Code in N parts
	secret_sharing(S, points, N, K);

	cout << "Secret is divided to " << N
		<< " Parts - " << endl;

	for (int i = 0; i < N; ++i) {
		cout << points[i].first << " "
			<< points[i].second << endl;
	}

	cout << "We can generate Secret from any of "
		<< K << " Parts" << endl;

	// Input any M points from these
	// to get back our secret code.
	int M = 2;

	// M can be greater than or equal to threshold but
	// for this example we are taking for threshold
	if (M < K) {
		cout << "Points are less than threshold "
			<< K << " Points Required" << endl;
	}

	int* x = new int[M];
	int* y = new int[M];

	// Input M points you will get the secret
	// Let these points are first M points from
	// the N points which we shared above
	// We can take any M points

	for (int i = 0; i < M; ++i) {
		x[i] = points[i].first;
		y[i] = points[i].second;
	}

	// Get back our result again.
	cout << "Our Secret Code is : "
		<< Generate_Secret(x, y, M) << endl;
}

// Driver Code
int main()
{
	int S = 65;
	int N = 4;
	int K = 2;

	operation(S, N, K);
	return 0;
}

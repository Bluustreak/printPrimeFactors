#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long long testNumber)   		// testNumber may not be larger than 18,446,744,073,709,551,615
{
	unsigned long upperLimit = sqrt(testNumber); 	// no need to check testNumber's divisability with anything over upperLimit.. due to reasons I don't quite understand.

	for (unsigned int i = 2; i <= upperLimit; i++)
		if (testNumber%i == 0)
			return false;							//if the number is evenly divisible with i, it's not a prime

	return true;
}


void printPrimeFactors(int n)
{
	int divider = 2;
	bool finished = false;

	while (divider <= n / 2)
	{
		int exp = 0;
		while (n%divider == 0)
		{
			exp++;
			n = n / divider;
		}
		if (exp > 0)
			cout << divider << "^" << exp << endl;

		while (!isPrime(++divider));
		exp = 0;

	}
}

int main()
{
	printPrimeFactors(2000);
}
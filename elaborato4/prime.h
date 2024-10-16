#include <math.h>
#include <limits.h>

unsigned short int is_prime(unsigned short int n) {
	int i;
	if (n <= 1) return 0;

	if (n == 2) return 1;

	if (!(n % 2)) return 0;

	for (i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return 0;
	return  1;
}

unsigned short int nth_prime(unsigned short int n) {
	int num_pri = 0, i = 0, nu = 0;
	while (num_pri <= n)
	{
		if (is_prime(i) == 1)
		{
			num_pri++;
			nu = i;
		}
		i++;
	}
	if (nu > USHRT_MAX) return 0;
	return nu;
}


unsigned short int succ_prime(int reset) {
	return  0;
}


unsigned short int co_prime(unsigned short int m, unsigned short int n) {
	return 0;
}


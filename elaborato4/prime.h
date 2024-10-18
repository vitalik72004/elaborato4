#include <math.h>
#include <limits.h>

unsigned short int current_int = 2;

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
	if (reset != 0)
	{
		current_int = 2;
		return current_int;
	}

	while (1)
	{
		if (is_prime(current_int))
		{
			unsigned short int res = current_int;
			current_int++;

			if (res > USHRT_MAX)
			{
				current_int = 2;
				return 0;
			}
			return res;
		}
		current_int++;
	}
}


unsigned short int co_prime(unsigned short int m, unsigned short int n) {
	unsigned short int temp;
	while(n!=0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}

	if (m == 1) return 1;
	else return 0;
}


#include <math.h>


unsigned short int is_prime(unsigned short int n) {
	int i;
	if (n <= 1) return 0;

	if (n == 2) return 1;

	for (i = 3; i <= sqrt(n); i+=2)
		if (n % i == 0)
			return 0;
	return  1;
}

unsigned short int nth_prime(unsigned short int n) {
	int num_pri = 0, i = 0;
	while (num_pri <= n)
	{
		if (is_prime(i) == 1)
			num_pri++;
		i++;
	}
	return  i;
}



unsigned short int succ_prime(int reset) {

}


unsigned short int co_prime(unsigned short int m, unsigned short int n) {
	return 0;
}


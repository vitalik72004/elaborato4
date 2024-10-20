#include <math.h>
#include <limits.h>

unsigned short int current_int = 2; 

unsigned short int is_prime(unsigned short int n) { 
	int i;
	if (n <= 1) return 0;	// Numeri minori o uguali a 1 non sono primi

	if (n == 2) return 1;	// Il numero 2 è l'unico numero primo pari

	if (!(n % 2)) return 0;	// Se il numero è pari, non è primo

	for (i = 3; i <= sqrt(n); i += 2)	// Controlla solo i divisori dispari da 3 fino alla radice quadrata di n
		if (n % i == 0)
			return 0;
	return  1;	// Se non ci sono divisori, il numero è primo

}

unsigned short int nth_prime(unsigned short int n) {
	int num_pri = 0, i = 0, nu = 0;

	while (num_pri <= n)	// Il ciclo continua fino a trovare n numeri primi
	{
		if (is_prime(i) == 1)	// Se il numero è primo, incrementa il contatore di numeri primi
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
	if (reset != 0)	// Se reset è diverso da 0, ritorna 2
	{
		current_int = 2;
		return current_int;
	}

	while (1)	// Cerca il prossimo numero primo
	{
		current_int++;
		if (is_prime(current_int))		// Controlla se il numero è primo
		{
			unsigned short int res = current_int;
			current_int++;

			// Se il numero supera il valore massimo per il tipo, ricomincia
			if (res > USHRT_MAX)
			{
				current_int = 2;
				return 0;
			}
			return res;
		}
	}
}

unsigned short int co_prime(unsigned short int m, unsigned short int n) {
	unsigned short int temp;
	while (n != 0)	// Utilizza l'algoritmo di Euclide per trovare il massimo comun divisore
	{
		temp = n;
		n = m % n;
		m = temp;
	}

	if (m == 1) return 1;	// Se il massimo comun divisore è 1, i numeri sono coprimi
	else return 0;
}

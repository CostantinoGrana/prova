#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap_elem(void *a, size_t size, size_t n, size_t m) {
	void *tmp = malloc(size);
	memcpy(tmp, (char*)a + n * size, size);
	memcpy((char*)a + n * size, (char*)a + m * size, size);
	memcpy((char*)a + m * size, tmp, size);
	free(tmp);
}

void ordina(void *a, size_t size, size_t n, bool(*minore)(void*, size_t, size_t)) {
	for (size_t i = 0; i < n - 1; i++) {
		size_t indice_min = i;
		for (size_t j = i + 1; j < n; j++) {
			if (minore(a, j, indice_min)) {
				indice_min = j;
			}
		}
		swap_elem(a, size, indice_min, i);
	}
}

bool minore_int(void *a, size_t n, size_t m) {
	int *p = a;
	return p[n] < p[m];
}
bool minore_double(void *a, size_t n, size_t m) {
	double *p = a;
	return p[n] < p[m];
}
bool minore_charptr(void *a, size_t n, size_t m) {
	char **p = a;
	return strcmp(p[n], p[m]) < 0;
}

int main(void)
{
	int a[] = { 7, -3, 5, 9, -1, -6, 2 };
	double b[] = { 7.9, -3.2, 5.8, 9.1, -1.08, -6.2, 2.3 };
	char *c[] = { "casa", "aereo", "prova", "banana", "zio", "gioco", "test" };
	size_t n = 7;

	ordina(a, sizeof(int), n, minore_int);
	ordina(b, sizeof(double), n, minore_double);
	ordina(c, sizeof(char*), n, minore_charptr);

	return 0;
}

/* Versione 1 - solo int
#include <stdlib.h>

void swap_elem(int *a, size_t n, size_t m) {
	int tmp = a[n];
	a[n] = a[m];
	a[m] = tmp;
}

void ordina(int *a, size_t n) {
	for (size_t i = 0; i < n - 1; i++) {
		size_t indice_min = i;
		for (size_t j = i + 1; j < n; j++) {
			if (a[j] < a[indice_min]) {
				indice_min = j;
			}
		}
		swap_elem(a, indice_min, i);
	}
}

int main(void)
{
	int a[] = { 7, -3, 5, 9, -1, -6, 2 };
	size_t n = 7;

	ordina(a, n);

	return 0;
}
*/
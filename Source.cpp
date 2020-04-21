#include <stdio.h>
#include <omp.h>
int n;
#pragma omp threadprivate(n)
int main(int argc, char *argv[])
{
	int num, n = 1;
#pragma omp parallel private (num)
	{

		num = omp_get_thread_num();
		printf("Znachennja n na potoci %d (na vxodi): %d\n", num, n);
		n = omp_get_thread_num();
		printf("Znachennja n na potoci %d (na vixodi): %d\n", num, n);
	}
	printf("Znachennja n (seredina): %d\n", n);
#pragma omp parallel private (num)
	{
		num = omp_get_thread_num();
		printf("Znachennja n na potoci %d (znovy): %d\n", num, n);
	}
}
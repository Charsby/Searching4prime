#include<iostream>
#include<time.h>
#include<math.h>
#define infinity 20000000

void Searching1(long seed) {
	clock_t start, finish;
	double runtime;
	long count = 1;
	long i, j;
	bool flag = true;
	std::cout << "Get started with Method1";
	start = clock();
	for (i = 3; i < infinity; i += 2,flag = true) {
		for (j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) count++;
		if (count == seed) {
			std::cout << "\nBingo! The result is:" << i;
			break;
		}
	}
	finish = clock();
	runtime = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << "\nRuntime of Method1 is" << runtime;
	getchar();
}

void Searching2(long seed) {
	clock_t start, finish;
	double runtime;
	long count = 1;
	long i, j;
	bool flag = true;
	long *prime = new long[seed];
	std::cout << "Get started with Method2";
	start = clock();
	for (i = 0; i < seed; i++)
		prime[i] = 0;
	prime[0] = 2;
	for (i = 3; i < infinity; i += 2,flag = true) {
		for (j = 0; (prime[j] != 0) && (prime[j] <= sqrt(i)); j++) {
			if (i%prime[j] == 0) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			prime[count] = i;
			count++;
		}
		if (count == seed) {
			std::cout << "\nBingo! The result is:" << prime[count-1];
			break;
		}
	}
	finish = clock();
	runtime = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << "\nRuntime of Method1 is" << runtime;
	getchar();
}

void Searching3(long seed) {
	clock_t start, finish;
	double runtime;
	long count = 0;
	long i, j;
	bool *prime = new bool[infinity];
	std::cout << "Get started with Method3";
	start = clock();
	for (i = 0; i < infinity; i++)
		prime[i] = true;
	prime[0] = false;prime[1] = false;
	for (i = 2; i < infinity ; i++) {
		if (prime[i]){
			for (j = i+i ; j < infinity; j += i)
				prime[j] = false;
		}
	}
	for (i = 0; i < infinity; i++) {
		if (prime[i]) count++;
		if (count == seed) {
			std::cout << "\nBingo! The result is " << i;
			break;
		}
	}
	finish = clock();
	runtime = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << "\nRuntime of Method1 is" << runtime;
	getchar();
}
int main() {
	long seed = 1000000;
	Searching1(seed);
	Searching2(seed);
	Searching3(seed);
}


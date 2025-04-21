#include <iostream>
#include <vector>
#include <cstdio>

void sieveOfEratosthenes(int n) {

    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int p = 2; p * p <= n; ++p) {

        if (isPrime[p]) {

            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    printf("Простые числа до %d: ", n);
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}

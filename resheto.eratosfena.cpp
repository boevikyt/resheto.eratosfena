#include <cstdio>
#include <cstdlib> 

void sieveOfEratosthenes(int n) {
    bool* isPrime = (bool*)calloc(n + 1, sizeof(bool));
    if (!isPrime) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    for (int i = 2; i <= n; ++i) {
        isPrime[i] = true;
    }


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

    free(isPrime);
}

int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}

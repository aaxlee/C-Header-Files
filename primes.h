#ifndef PRIMES_H
#define PRIMES_H

#include "../C-Header-Files/array.h"
#include <math.h>
#include <stdio.h>

int is_prime(int n);
void gen_primes(Array *arr, int interval);
void find_prime_factors(Array *arr, int num);

int is_prime(int n) {
  if (n == 0 || n == 1) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0; // false
    }
  }
  return 1; // true
}

void gen_primes(Array *primes, int interval) {
  int prime_count = 0;
  int num = 2;
  while (prime_count < interval) {
    if (is_prime(num)) {
      primes->push_back(primes, num);
      prime_count++;
    }
    num++;
  }
}

void find_prime_factors(Array *factors, int num) {
  Array *primes = create_array();
  primes->push_back(primes, 2);
  int current_num = 3;
  while (primes->array[primes->index - 1] < num) {
    if (is_prime(current_num)) {
      primes->push_back(primes, current_num);
    }
    current_num++;
  }

  int count = 0;
  while (count < primes->index) {
    if ( !(num % primes->array[count]) ) {
      num /= primes->array[count];
      factors->push_back(factors, primes->array[count]);
      count = 0;
    }
    else count++;
  }
  free_array(primes);
}

#endif //PRIMES_H
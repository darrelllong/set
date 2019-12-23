#include "set.h"
#include <inttypes.h>
#include <stdio.h>

enum items {
  A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U,
      V, W, X, Y, Z };

void printSet(uint32_t s) {
  printf("{ ");
  for (enum items i = A; i <= Z; i += 1) {
    if (memberSet(i, s)) {
      printf("%c ", (char)i + 'A');
    }
  }
  printf("}");
  return;
}

#define nl() printf("\n")

int main(void) {

  set letter = 0;

  for (int i = 0; i <= Z; i += 1) {
    letter = insertSet(i, letter);
  }

  set vowel =
      insertSet(A, insertSet(E, insertSet(I, insertSet(O, insertSet(U, 0)))));

  set consonant = differenceSet(letter, vowel);

  printf("vowels = "); printSet(vowel); nl();
  printf("consonants = "); printSet(consonant); nl();

  set darrell = insertSet(D, insertSet(A, insertSet(R, insertSet(R, insertSet(E, 
                insertSet(L, insertSet(L, 0)))))));

  printf("me ⋂ vowels = "); printSet(intersectSet(darrell, vowel)); nl();
  printf("me ⋂ consonants = "); printSet(intersectSet(darrell, consonant)); nl();

  printf("~vowels = "); printSet(~vowel); nl();
  printf("~consonants = "); printSet(~consonant); nl();

  set universe = (1 << (Z + 1)) - 1;

  int element = A;

  while (universe) {
    printf("U = "); printSet(universe); nl();
    universe = deleteSet(element, universe);
    element += 1;
  }
}

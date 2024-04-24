/* @ensures A: *a == \old(*b);
   @ensures B: *b == \old(*a);
   @ */

void swap (int *a, int *b);

// frama-c -wp swap.c swap1.h
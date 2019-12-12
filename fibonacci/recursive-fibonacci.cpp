/*
 * Recursive Fibonacci algorithms
 * Updated: 2019-12-12
 * By: ChocolateCharlie
 */

/* Naive Recursive Fibonacci algorithm
 * Complexity: O(F(n))
 */
int naiveRecursiveFibonnaci(int n) {
    return(n <= 1 ? n : naiveRecursiveFibonnaci(n - 1) + naiveRecursiveFibonnaci(n - 2));
}

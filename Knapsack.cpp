/*
 * Knapsack Problem
 * Updated: 2019-12-04
 * By: ChocolateCharlie
 */

#include <algorithm>
#include <vector>
#include "Knapsack.h"



/* Discrete Knapsack (without repetitions)
 * Tabulation algorithm (iterative)
 * Complexity: O(nW), with n the number of objects and W the capacity
 * c: capacity of the knapsack
 */
int discreteKnapsack(std::vector<KnapsackObject> &k, int c) {
    int table[k.size() + 1][c + 1];
    for (int i = 0; i < k.size() + 1; i++)  table[i][0] = 0;
    for (int i = 0; i < c + 1; i++)         table[0][i] = 0;

    for (int i = 1; i < k.size() + 1; i++) {
        for (int j = 1; j < c + 1; j++) {
            table[i][j] = table[i - 1][j];
            if (k[i - 1].weight <= j)
                table[i][j] = std::max(table[i - 1][j],
                                       table[i - 1][j - k[i - 1].weight] + k[i - 1].value);
        }
    }

    return(table[k.size()][c]);
}



/* Discrete Knapsack with Repetitions
 * Tabulation algorithm (iterative)
 * Complexity: O(nW), with n the number of objects and W the capacity
 * c: capacity of the knapsack
 */
int discreteRepetitiveKnapsack(std::vector<KnapsackObject> &k, int c) {
    int table[c + 1];
    for (int i = 0; i < c + 1; i++) table[i] = 0;

    for (int i = 0; i < c + 1; i++) {
        for (int j = 0; j < k.size(); j++) {
            if (k[j].weight <= i)
                table[i] = std::max(table[i], table[i - k[j].weight] + k[j].value);
        }
    }

    return(table[c]);
}



/* Fractional Knapsack
 * Greedy algorithm
 * Complexity: O(n log n)
 * WARNING: you might want a better precision than int
 * c: capacity of the knapsack
 */
int fractionalKnapsack(std::vector<KnapsackObject> &k, int c) {
    int ans;
    ans = 0;
    std::sort(k.begin(), k.end(),
              [](const KnapsackObject &a, const KnapsackObject &b)
              -> bool { return(a.vpw < b.vpw); });

    while (c > 0 && !k.empty()) {
        if (k.back().weight <= c) {
            ans += k.back().value;
            c -= k.back().weight;
        }
        else {
            ans += k.back().vpw * c;
            c = 0;
        }
    }

    return(ans);
}

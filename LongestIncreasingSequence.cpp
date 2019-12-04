/*
 * Longest Increasing Sequence (LIS)
 * Updated: 2019-12-04
 * By: ChocolateCharlie
 */

#include <algorithm>
#include <vector>



/* Longest Increasing Sequence
 * Tabulation algorithm (iterative)
 * Complexity: O(n^2)
 */
int longestIncreasingSequence(std::vector<int> &a, int l = -1) {
    l = (l == -1 ? a.size() : l);
    int table[l];

    for (int i = 0; i < l; i++) {
        table[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && table[i] < table[j] + 1)
                table[i] = table[j] + 1;
        }
    }

    return(*std::max_element(table, table + l));
}

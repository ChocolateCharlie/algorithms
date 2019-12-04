/*
 * Edit Distance (weighted)
 * Updated: 2019-12-04
 * By: ChocolateCharlie
 */

#include <string>



/* Edit Distance (weighted)
 * Tabulation algorithm (iterative)
 * Complexity: O(n^2)
 * I: insertion weight
 * D: deletion weight
 * S: substitution weight
 */
int editDistance(std::string a, std::string b, int x = -1, int y = -1, const int I = 1, const int D = 1, const int S = 1) {
    x = (x == -1 ? a.length() : x);
    y = (y == -1 ? b.length() : y);
    int table[x + 1][y + 1];
    int diff;

    table[0][0] = 0;
    for (int i = 1; i < x + 1; i++) table[i][0] = i * D;
    for (int i = 1; i < y + 1; i++) table[0][i] = i * I;

    for (int i = 1; i < x + 1; i++) {
        for (int j = 1; j < y + 1; j++) {
            diff = (a[i - 1] == b[j - 1] ? 0 : S);
            table[i][j] = std::min(std::min(table[i - 1][j] + D, table[i][j - 1] + I), table[i - 1][j - 1] + diff);
        }
    }

    return(table[x][y]);
}

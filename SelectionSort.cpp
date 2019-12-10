/*
 * Selection Sort
 * Updated: 2019-12-10
 * By: ChocolateCharlie
 */

#include <vector>



/* Selection Sort
 * Complexity: O(n^2)
 */
void    selectionSort(std::vector<int> &v) {
    int m;
    int temp;

    for (int i = 0; i < v.size() - 1; i++) {
        m = i;
        for (int j = i + 1; j < v.size(); j++)  if (v[j] < v[m])    m = j;
        temp = v[m];
        v[m] = v[i];
        v[i] = temp;
    }
}

/*
 * Merge Sort
 * Updated: 2019-12-10
 * By: ChocolateCharlie
 */

#include <vector>



/* Merge Sort
 * Complexity: O(n log n)
 */
void    mergeSort(std::vector<int> &v) {
    if (v.size() != 1) {
        std::vector<int> a;
        std::vector<int> b;

        for (int i = 0; i < v.size(); i++) {
            if (i < v.size() / 2)   a.push_back(v[i]);
            else                    b.push_back(v[i]);
        }

        mergeSort(a);
        mergeSort(b);

        for (int i = 0; i < v.size(); i++) {
            if (!a.empty() && (b.empty() ||
                (!b.empty() && a.front() < b.front()))) {
                    v[i] = a.front();
                    a.erase(a.begin(), a.begin() + 1);
                }
            else {
                    v[i] = b.front();
                    b.erase(b.begin(), b.begin() + 1);
            }
        }
    }
}

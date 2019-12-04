/*
 * Knapsack Problem
 * Updated: 2019-12-04
 * By: ChocolateCharlie
 */

#ifndef KNAPSACK_H_INCLUDED
#define KNAPSACK_H_INCLUDED

#include <vector>

struct KnapsackObject {
    int value, weight;
    double  vpw;    // value per weight
};



int discreteKnapsack(std::vector<KnapsackObject> &k, int c);
int discreteRepetitiveKnapsack(std::vector<KnapsackObject> &k, int c);
int fractionalKnapsack(std::vector<KnapsackObject> &k, int c);

#endif // KNAPSACK_H_INCLUDED

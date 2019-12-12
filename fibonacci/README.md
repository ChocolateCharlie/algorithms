# Fibonacci numbers computation 

## Introduction

The [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_number) is defined as follows:
> F<sub>n</sub> = F<sub>n - 1</sub> + F<sub>n - 2</sub> for n > 1
> with F<sub>0</sub> = 0 and F<sub>1</sub> = 1

The first numbers of the sequence can be computed by hand.
For example, F<sub>2</sub> = F<sub>1</sub> + F<sub>0</sub> = 1 + 0 = 1.
However, the sequence increases very quickly. For example, F<sub>10</sub> = 55 and F<sub>20</sub> = 6765.
You may have a look at the sequence [here](https://oeis.org/A000045) to convince yourself.

## Computing Fibonacci numbers

### 1) Naive recursive approach

#### Main idea
Let's write a function ```fibonacci``` that computes F<sub>N</sub> for a given integer N such that N >= 0.
According to the definition of the Fibonacci sequence, ```fibonacci(N)``` = ```fibonacci(N - 1)``` + ```fibonacci(N - 2)```.
Thus, the ```fibonacci``` function will look like:
```cpp
int fibonacci(int N) {
  return(fibonacci(N - 1) + fibonacci(N - 2));
}
```
Of course, the algorithm above never stops running: it keeps calling the ```fibonacci``` function on smaller integers again and again.
We call the fact that a function calls itself _recursivity_.
The ```fibonacci``` function defined above makes _recursive calls_.
Here, the recursive calls to the ```fibonacci``` function never stop, because no condition of ending has been defined.

#### Fixing a condition
A condition could be: when the algorithm reaches a certain number _n_, return F<sub>_n_</sub>.

If _n_ is chosen too big, then N might be smaller than _n_.
In this case, our algorithm will not be able to return a smaller value than F<sub>_n_</sub>, and thus will not be able to compute F<sub>N</sub>.

A solution is to choose the smallest Fibonacci number possible: 0. Let's try it:
```cpp
int fibonacci(int N) {
  if (N == 0) return(0);
  else        return(fibonacci(N - 1) + fibonacci(N - 2));
}
```
This code doesn't work. For example, when computing ```fibonacci(2)```, the algorithm:
* calls ```fibonacci(0)```, which returns 0
* calls ```fibonacci(1)```, which calls
  - ```fibonacci(0)```, which returns 0
  - ```fibonacci(-1)```, which is smaller than the fixed condition (0).
The condition will never be reached, and the recursive calls will never stop.

This can be fixed arranging the condition this way: ```if (N <= 0) return(0);```.
Now the algorithm stops, ans each time it reaches 0 or a smaller value, it returns 0.

However, it still doesn't compute F<sub>N</sub>.
In fact, for any given N, this function returns 0.
Let's try to understand why by analysing the computation of ```fibonacci(2)```.
The algorithm:
* calls ```fibonacci(0)```, which returns 0
* calls ```fibonacci(1)```, which calls:
  - ```fibonacci(0)```, which returns 0
  - ```fibonacci(-1)```, which is smaller than the fixed condition (0), and thus returns 0

We have ```fibonacci(1)``` = ```fibonacci(0)``` + ```fibonacci(-1)``` = 0 + 0 = 0, instead of ```fibonacci(1)``` = 1.
Since it is not possible to compute ```fibonacci(1)``` from 0, a solution is to hardcode it:
```cpp
int fibonacci(int N) {
  if (N <= 0) return(0);
  if (N == 1) return(1);
  else        return(fibonacci(N - 1) + fibonacci(N - 2));
}
```
At last, the algorithm works properly !

#### Cleaning the code
A few remarks about the code above:
* Since the ```return()``` statement aborts the function, it is not necessary to keep the condition ```else```
* The first two lines can be written ```if (N <= 1) return(N);```.
The behavior is quite similar when N >= 0, which is fine.
* Using a ternary condition, one can write this function in a single line:
```cpp
int fibonacci(int N)  { return(N <= 1 ? N : fibonacci(N - 1) + fibonacci(N - 2)); }
```

#### Complexity
This algorithm calls recursively the ```fibonacci``` function until it returns 0 or 1, and sums up the result.
All in all, it is equivalent to doing a huge sum of 1's.
More precisely, for a given N, the algorithm sums up F<sub>N</sub> 1's.
This means that the complexity of the algorithm depends on how fast the Fibonacci sequence grows, which can be written _O(F<sub>n</sub>)_.
Unfortunately, as we have seen in introduction, this sequence increases very quickly.
Some mathematical works, which will not be discussed here, have shown that F<sub>_n_</sub> ~ &phi;<sub>_n_</sub>.
So the algorithm runs with an **exponential time**.
Since it does additions of 1's, it also takes **exponential space**.
One should avoid using this kind of algorithms as much as possible.
We will now cover better algorithms.

## Sources

* [E-Maxx Algorithms - Fibonacci numbers](https://cp-algorithms.com/algebra/fibonacci-numbers.html)
* [Algorithm Implementation - Mathematics: Fibonacci Number Program](https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Fibonacci_Number_Program)
* [Wikipedia - Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number)
* [The On-line Encyclopedia of Integer Sequences](https://oeis.org/A000045)

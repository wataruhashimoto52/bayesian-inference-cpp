#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <numeric>
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/poisson_distribution.hpp>
#include <boost/random/gamma_distribution.hpp>
using namespace std;

int arraySum(int a[], int n) {
    int initial_sum = 0;
    return accumulate(a, a+n, initial_sum);
}

int main() {
    int a = 1;
    int b = 1;
    int N = 100;
    int data[N];
    double randFromUnif;

    size_t seed = 1234567890;
    boost::random::mt19937 engine(seed);

    boost::random::gamma_distribution<> gamma_dist(a, b);

    
}
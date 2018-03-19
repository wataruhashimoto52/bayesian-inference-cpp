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
    int lamb = 4;
    int pred_a;
    double pred_b;
    int data[N];
    double randFromUnif;

    size_t seed = 1234567890;
    boost::random::mt19937 engine(seed);

    boost::random::poisson_distribution<> dist_pois(lamb);
    boost::function<int()> randdata = boost::bind(dist_pois, engine);
    for (size_t n = 0;n < 100;++n) {
        int result = randdata();
        data[n] = result;
        cout << result << endl;
    }
    pred_a = arraySum(data, N) + a;
    pred_b = 1 / (double) (N + b);

    boost::random::gamma_distribution<> dist_gamma(pred_a, pred_b);
    boost::function<double()> randpost = boost::bind(dist_gamma, engine);
    ofstream posterior_file("posterior_poissongamma.txt");

    for (size_t n = 0;n < 1000;++n) {
        posterior_file << randpost() << '\t';
    }
}
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

    boost::random::gamma_distribution<> dist_gamma(a, b);
    boost::function<double()> randdata = boost::bind(dist_gamma, engine);
    for (size_t n = 0;n < 100;++n) {
        // 実際にベルヌーイ分布から乱数生成
        double result = randdata();
        data[n] = result;
        cout << result << endl;
    }


}
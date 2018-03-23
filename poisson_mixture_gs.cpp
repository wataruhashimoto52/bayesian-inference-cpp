#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>
#include <numeric>
#include <string>
#include <cmath>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/random/mersenne_twister.hpp>
using namespace std;

double log_sum_exp(vector<double> &x) {
    double max_x = *max_element(x.begin(), x.end());
    // log_sum_exp
}

// from http://tadaoyamaoka.hatenablog.com/entry/2017/12/10/002854

void random_dirichlet(mt19937_64 &mt, vector<double> &x, const double alpha) {
    gamma_distribution<double> dist_gamma(alpha, 1.0);

    double sum_y = 0;

    for (int i = 0;i < x.size();++i) {
        double y = dist_gamma(mt);

        sum_y += y;
        x[i] = y;
    }

    for_each(x.begin(), x.end(), [sum_y](double &v) { v /= sum_y; });
}

int main() {
    random_device rd;
    mt19937_64 mt(rd());

    // set initial params
    int maxiter = 4000;

    // 

    for (int i = 0;i < maxiter;++i) {
        // sample latent variables

        // sample lambda

        // sample pi
    }
}

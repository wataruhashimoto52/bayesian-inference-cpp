#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "eigen/Eigen/Core"
#include "eigen/Eigen/Geometry"
#include <boost/random/mersenne_twister.hpp>
using namespace std;

double log_sum_exp(vector<double> &x) {
    double max_x = *max_element(x.begin(), x.end());
    // log_sum_exp
}

// from http://tadaoyamaoka.hatenablog.com/entry/2017/12/10/002854

void random_dirichlet(mt19937_64 &mt, vector<double> &x, const double alpha) {
	gamma_distribution<double> gamma(alpha, 1.0);
	
	double sum_y = 0;
	for (int i = 0; i < x.size(); i++) {
		double y = gamma(mt);
		sum_y += y;
		x[i] = y;
	}
	for_each(x.begin(), x.end(), [sum_y](double &v) { v /= sum_y; });
}

int main() {
    random_device rd;
    mt19937_64 mt(rd());
    int N = 500;
    int K = 2;
    int maxiter = 4000;
    vector<int> dt(N, 0);

    // make data
    poisson_distribution<int> dist_pois1(15); 
    for (int i = 0;i < 300;++i) {
        int result = dist_pois1(mt);
        dt.push_back(result);
    }

    poisson_distribution<int> dist_pois2(30);
    for (int j = 0;j < 200;++j) {
        int result = dist_pois2(mt);
        dt.push_back(result);
    }

    // set initial params
    double lmd[2] = {1.0, 1.0};
    double pi[2] = {0.5, 0.5};
    double alpha[2] = {1.0, 1.0};
    int a = 1;
    int b = 1;
    vector<double> sampled_lmd(N, 0);
    vector<double> sampled_pi(N, 0);
    vector<vector<double>> sampled_s;
    

    /*

    for (int i = 0;i < maxiter;++i) {
        // sample latent variables

        // sample lambda

        // sample pi
    }
    */

    for (int i = 0;i < maxiter;++i) {
        
    }
}

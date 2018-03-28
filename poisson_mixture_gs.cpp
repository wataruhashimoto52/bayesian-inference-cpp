#define EIGEN_NO_DEBUG
//#define EIGEN_DONT_VECTORIZE
#define EIGEN_DONT_PARALLELIZE
#define EIGEN_MPL2_ONLY

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <math.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <boost/random/mersenne_twister.hpp>

double log_sum_exp(std::vector<double> &x) {
    double max_x = *max_element(x.begin(), x.end());
    
}

// from http://tadaoyamaoka.hatenablog.com/entry/2017/12/10/002854

void random_dirichlet(std::mt19937_64 &mt, std::vector<double> &x, const double alpha) {
	std::gamma_distribution<double> gamma(alpha, 1.0);
	
	double sum_y = 0;
	for (int i = 0; i < x.size(); i++) {
		double y = gamma(mt);
		sum_y += y;
		x[i] = y;
	}
	for_each(x.begin(), x.end(), [sum_y](double &v) { v /= sum_y; });
}




int main() {

    // set initial params
    std::random_device rd;
    std::mt19937_64 mt(rd());
    int N = 500;
    int K = 2;
    int maxiter = 4000;
    double lmd[2] = {1.0, 1.0};
    double pi[2] = {0.5, 0.5};
    double alpha[2] = {1.0, 1.0};
    const int a = 1;
    const int b = 1;
    double tmp;
    std::vector<double> sampled_lmd(N, 0);
    std::vector<double> sampled_pi(N, 0);
    std::vector<std::vector <double> > sampled_s;
    
    std::vector<int> dt(N, 0);

    // generate data
    std::poisson_distribution<int> dist_pois1(15); 
    for (int i = 0;i < 300;++i) {
        int result = dist_pois1(mt);
        dt.push_back(result);
    }

    std::poisson_distribution<int> dist_pois2(30);
    for (int j = 0;j < 200;++j) {
        int result = dist_pois2(mt);
        dt.push_back(result);
    }

    /*

    for (int i = 0;i < maxiter;++i) {
        // sample latent variables

        // sample lambda

        // sample pi
    }
    */

    for (int i = 0;i < maxiter;++i) {
        double logpi = std::for_each(pi, pi+1, [](double& x) {log(x);});
        double loglmd = std::for_each(lmd, lmd+1, [](double& x) {log(x);});

        Eigen::Map<Eigen::Vector3d> vec(dt.data());

        //あとでeigenに修正
        double tmp = vec*loglmd - lmd + logpi;



    }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <numeric>
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/beta_distribution.hpp>
using namespace std;

int arraySum(int a[], int n) {
    int initial_sum = 0;
    return accumulate(a, a+n, initial_sum);
}

int main() {
    int a = 1;
    int b = 1;
    int pred_a, pred_b;
    int N = 100;
    int data[N];
    double randFromUnif;
    
    random_device seed_gen;
    default_random_engine engine(seed_gen());

    // generate data
    bernoulli_distribution dist_bern(0.25);

    for (size_t n = 0;n < 100;++n) {
        // 実際にベルヌーイ分布から乱数生成
        int result = dist_bern(engine);
        data[n] = result;
    }

    for (size_t n = 0;n < 100;++n) {
        cout << data[n] << endl;
    }
    
    /*
    // read data
    const string file_name = "bernoulli_bayesian.txt";
    ifstream file(file_name.c_str());

    string temp;
    vector<string> items;
    while (getline(file, temp, '\t')) {
        items.push_back(temp);
    }
    for (unsigned i = 0; i < items.size();++i) {
        cout << items[i] << endl;
    }
    */
    
    // posterior
    pred_a = arraySum(data, N) + a;
    pred_b = N - arraySum(data, N) + b;

    size_t seed = 1234567890;
    boost::random::mt19937 engine2(seed);

    boost::random::beta_distribution<> dist_beta(pred_a, pred_b);
    
    ofstream posterior_file("posterior_betabernoulli.txt");
    boost::function<double()> randpost = boost::bind(dist_beta, engine2);
    for (size_t n = 0;n < 1000;++n) {
        posterior_file << randpost() << '\t';
    }
}
#include <iostream>
#include <vector>

using namespace std;

//A type for holding prime factors and their respective powers
typedef pair<int64_t,int64_t> P;

int main(){

  //A prime sieve for sieving primes
  int64_t max_n = 20000000;
  
  vector<int64_t>primes (max_n, 0);

  cout << "Finding primes up to " << max_n << "..." << endl;
  
  //Marks every location by the smallest prime dividing it
  //Clever!
  for(int i = 2; i < max_n; i+= 1){
    if (primes[i] == 0){
	for(int j = i; j < max_n; j += i){
	  primes[j] = i;
	}
      }
  }


  cout << "Finding prime factorizations up to " << max_n << "..." << endl;

  //A script for finding factorizations
  for(int64_t i = 2; i < max_n; i += 1){
    vector<P> factors;
    int64_t cur_val = i;
    while(cur_val != 1){
      int64_t cur_prime = primes[cur_val];
      int64_t cur_power = 0;
      while(primes[cur_val] == cur_prime){
	cur_power += 1;
	cur_val = cur_val/cur_prime;
      }
      factors.push_back(P(cur_prime, cur_power));
    }
    /*
    cout << "Factored value " << i << endl;
    for (int i = 0; i < factors.size(); i++){
      cout << "p: " << factors[i].first << " power: " << factors[i].second << " ";
    }
    cout << endl;
    */
  }
  
}

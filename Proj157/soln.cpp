#include <iostream>
#include <vector>

using namespace std;

//Current solution is using factorization on squared values
//There is a better way
//we're solving x^2-Dy^2=1
//we can rearrange to x^2-1=Dy^2 or (x-1)(x+1)=Dy^2
//then our conditions are
//1) D divides (x-1)(x+1)
//2) the factors of (x-1)(x+1)/D show it is a square
//Now we're factoring linear values rather than square values
//Nice

//A type for holding prime factors and their respective powers
typedef pair<int64_t,int64_t> P;

int main(){

  int64_t max_x = 0;
  int64_t max_D = 0;

  int64_t threshold_D = 100;
  int64_t max_primes = 1000000000;
  
  vector<int64_t>primes (max_primes, 0);

  cout << "Finding primes up through " << max_primes << "..." << endl;
  
  //Marks every location by the smallest prime dividing it
  //Clever!
  for(int64_t i = 2; i < max_primes; i+= 1){
    if (primes[i] == 0){
	for(int64_t j = i; j < max_primes; j += i){
	  primes[j] = i;
	}
      }
  }


  cout << "Solving D values..." << endl;
  
  for(int64_t D = 2; D <= threshold_D; D++){

    cout << "On D: " << D << endl;
    
    //A script for finding factorizations
    //Used to check if D is a square
    int64_t cur_val = D;
    int is_square = 1;
    while(cur_val != 1){
      int64_t cur_prime = primes[cur_val];
      int64_t cur_power = 0;
      while(primes[cur_val] == cur_prime){
	cur_power += 1;
	cur_val = cur_val/cur_prime;
      }
      if (cur_power%2 != 0){
	is_square = 0;
	break;
      }
    }

    if (is_square == 1){
      cout << "Factorized D; it's a square" << endl;
      continue;
    }
    
    int64_t x = 2;
    while (1==1){
      //cout << "current x: " << x << endl;
      //Used to check if the x for each y is square
      if (((x*x)-1)%D != 0){
	x += 1;
	continue;
      }
      int64_t possible_y = ((x*x)-1)/D;

      //cout << "Testing value: " << possible_x << endl;
      
      cur_val = possible_y;
      is_square = 1;
      while(cur_val != 1){
	int64_t cur_prime = primes[cur_val];
	int64_t cur_power = 0;
	while(primes[cur_val] == cur_prime){
	  cur_power += 1;
	  cur_val = cur_val/cur_prime;
	}
	if (cur_power%2 != 0){
	  is_square = 0;
	  break;
	}
	
      }
      if (is_square == 1){
	if (x > max_x){
	  max_x = x;
	  max_D = D;
	}
	break;
      }
      
      x += 1;
	
    }
  }

  cout << "Max x: " << max_x << endl;
  cout << "Max D: " << max_D << endl;
  
}

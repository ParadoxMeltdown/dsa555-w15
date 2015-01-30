#include "timer.h"
#include <cstdlib>
#include <iostream>
using namespace std;
/*
returns n!, n! = n* (n-1) * (n -2)...*1
*/
int factorial(int n){
	int rc=1;
	for(int i=1;i<=n;i++){
		rc=rc*i;
	}
	return rc;
}
/* 5!=5 * 4 * 3 * 2 * 1
     =5 * 4!
   4!= 4*3*2*1
     = 4* 3!
*/

int factorialR(int n){
  int rc=1;
  if(n>0){
		rc=n*factorialR(n-1);
	}
	return rc;
}
/*
returns b^n which is b*b*b...*b do it n times
*/
int power(int b, int n){
	int rc=1;
	for(int i=0;i<n;i++){
		rc=rc*b;
	}
	return rc;
}

int powerR1(int b,int n){
  int rc=1;
  if(n>0){
    rc=b*powerR1(b,n-1);
  }
  return rc;
}


int powerR2(int b,int n){
  int rc=1;
  if(n > 0){
    rc = powerR2(b,n/2);
    rc=rc*rc;
    if(n%2){
      rc=rc*b;
    }
  }
  return rc;
}

/*return the nth fibonnaci number
  fib(0) is 0
  fib(1)  is 1
  fib(2) = fib(1) + fib(0) = 1
  fib(3) = fib(2) + fib(1) = 2
  fib(n) = fib (n-1) + fib (n-2)
  ...
  */

/*recursive version*/
int fibR(int n){
  int rc;
  if(n == 0){
    rc=0;
  }
  else if(n == 1){
    rc=1;
  }
  else{
    rc=fibR(n-1) + fibR(n-2);
  }
  return rc;
}
/*iterative version*/
int fibI(int n){
  int rc;
  if(n == 0){
    rc=0;
  }
  else if(n == 1){
    rc=1;
  }
  else{  // n is 2 or higher
    int prev=1;
    int prevprev=0;
    for(int i=2;i<=n;i++){
      rc=prev+prevprev;
      prevprev=prev;
      prev=rc;
    }
  }
  return rc;
 
}


int main(int argc, char* argv[]){
  int v=atoi(argv[1]);
  Timer T1, T2;
  int a, b;
  T1.start();
  a=fibI(v);
  T1.stop();
  cout << "iterative fib(" << v << ") = " << a << endl;
  cout << "result took "<< T1.currtime() << " seconds to find" << endl;

  T2.start();
  b=fibR(v);
  T2.stop();
  cout << "recursive fibonacci(" << v << ") = " << b << endl;
  cout << "result took "<< T2.currtime() << " seconds to find" << endl;

}




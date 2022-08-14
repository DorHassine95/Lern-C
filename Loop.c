# include <stdio.h>
//Loop code in c 
int GCD(int , int );
int GCD2(int, int);
int IsPrime(int);

void main() {
	int a = 66;
	int b = 33;
	printf("%d\n", GCD(a,b));
	printf("%d", GCD2(a, b));
}
//////////////////////q1///////////////////
int GCD(int a, int b) {
	int gcd = 1;
	for (int i = 1; i <= b; i++) { 
		if (((a % i) && (b % i)) == 0 ) { //to prime gcd && (IsPrime(i)==1)
			gcd = i;
		}
	}
	return gcd;
}
int IsPrime(int p) {
	for (int i = 2; i < p; i++) {
		if ((p % i) == 0) {
			return 0;
		}
	}
	return 1;
}
int GCD2(int a, int b) {
	int gcd = b;
	while (gcd >= 1) {
		if ((a % gcd) == 0 && (b % gcd) == 0 ) { //&& (IsPrime(gcd) == 1)
			return gcd;
		}
			gcd--;
	}
	return 1;// || return gcd;
}
//////////////////////q2////////////////////


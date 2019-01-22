#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <ctime>
#include <complex>

// Site: www.codechef.com
// Challenge: October Challenge '18
// Problem: Appy and Balloons
// Problem Code: HMAPPY
// by lboris


typedef unsigned long long llu;
typedef long long int lls;
typedef unsigned int uint;

#define f(i,s,e) for(int i=s;i<e;++i)
#define fe(i,s,e) for(int i=s;i<=e;++i)
typedef std::vector<int> ivector;
int N;
llu M;
int A[100000];
int B[100000];

llu get_max() {
	llu cR = 0;
	f(i, 0, N) {
		llu cr = (llu)A[i] * (llu)B[i];
		if (cr > cR)cR = cr;
	}
	return cR;
}

bool check_m(llu Mx) {
	llu cM = M;
	f(i, 0, N) {
		llu cr = (llu)A[i] * (llu)B[i];
		if (cr > Mx) {
			llu n = (Mx / B[i]);
			llu cm = (A[i]<n)? 0:((llu)A[i] - n);
			if (cm > cM)return false;
			cM -= cm;
		}
	}
	return true;
}

llu solve() {
	llu l = 0;
	llu r = get_max();
	while (r - l > 1) {
		llu m = (l + r) >> 1;
		if (check_m(m)) r = m;
		else l = m;
	}
	return r;
}

int main(int argc, char **argv){
	clock_t start_tm = clock();
	if (argc > 1) freopen(argv[1], "r", stdin);
	scanf("%d %llu", &N,&M);
	f(i, 0, N) scanf("%d", A + i);
	f(i, 0, N) scanf("%d", B + i);
	llu R = solve();
	printf("%llu\n", R);
	fprintf(stderr, "Time: %lf\n", (double)(clock() - start_tm) / (double)CLOCKS_PER_SEC);
	return 0;
}

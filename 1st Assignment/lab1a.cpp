#include <iostream>
#include <bits/stdc++.h>
#include <vector>
//#include <fstream>
#include <cstdio>


using namespace std;

long long int N, K, D, T;
vector <long long int> l;
long long int Ts, Cs, Tf, Cf;


/***************************************************/
bool is_alright(long long int curr_c, long long int l_mx, long long int new_size) {

long long int dif = Cf-Cs;
long long int sum, part_sum;
sum =0;
vector <long double> xmax;
bool flag=true;
long long int x_floor;


if (l_mx*Cs > curr_c) {return false;}

for (long long int i=0; i<l.size(); i++){
	xmax.push_back((curr_c - Cs*l.at(i))/(dif));
	if (xmax.at(i) < 0 ) {flag = false; break;}
	x_floor = floor(xmax.at(i));
	if (x_floor < l.at(i)) {
		part_sum = (Tf * x_floor) + (Ts * (l.at(i) - x_floor));
	   }
	else {
		part_sum = Tf * l.at(i);

	   }
	sum += part_sum;
	part_sum=0;

	if (sum > T) {flag = false; break;}
}

if(flag == false) {return false; }
	else {return true;}

}
/***************************************************/
long long int approve_c (vector<long long int> c_arr, long long int index, long long int len, long long int lm, long long int ns) {
	long long int minimum_m = -1;
	while (index <= len) {

		long long int m = index + (len-index)/2;
	
		if (is_alright(c_arr.at(m), lm, ns)) {
			minimum_m = m;
			len = m - 1;
		}
		else {
			index = m + 1;
		}
	}
	return minimum_m;
}
/***************************************************/

long long int removeDuplicates (vector <long long int> arr, long long int size){
	if (size==0 || size==1)
		return size;

	long long int j=0;

	for(long long int i=0; i<size-1; i++){
		if(arr.at(i) != arr.at(i+1)) arr.at(j++) = arr.at(i);
	}

	arr.at(j++) = arr.at(size-1); 

	return j;
}
/***************************************************/
int main () {

scanf("%lld" "%lld" "%lld" "%lld", &N, &K, &D, &T);

vector <long long int> P;
vector <long long int> C;
long long int pi, ci;


for (long long int i=0; i<N; i++) {

	scanf("%lld", &pi);
	P.push_back(pi);

    scanf("%lld", &ci);
	C.push_back(ci);
	
}


/*********** sort Ci and sort Pi according to Ci **********/

vector < pair <long long int, long long int> >  C_new;

for (long long int i=0; i<P.size(); ++i) {
	C_new.push_back(make_pair(C.at(i),P.at(i)));
}


sort(C_new.begin(), C_new.end());


for (long long int i=0; i<N; i++){
	C.at(i) = C_new.at(i).first; 
	P.at(i) = C_new.at(i).second;
}
/******************************/

vector <long long int> d;
long long int di;


for (long long int i=0; i<K; i++){

	scanf("%lld", &di);
	d.push_back(di);
}

sort(d.begin(), d.end());

long long int d_new = removeDuplicates (d, K);


l.push_back(d.front());


for (long long int i=1; i<d_new; i++){
l.push_back(d.at(i) - d.at(i-1));
}

l.push_back(D - d.at(d_new-1));

sort(l.begin(), l.end(), greater<long long int>());

long long int lmax = l.front();

scanf("%lld" "%lld" "%lld" "%lld", &Ts, &Cs, &Tf, &Cf);

if (D*Tf > T) {cout << -1 << '\n';}

else {
	long long int min_c = approve_c (C, 0, N-1, lmax, d_new);

	if (min_c == -1) {cout << -1 << '\n';}
	else {

	long long int temp_min = P.at(min_c);
	for (long long int i=min_c; i<P.size(); i++){
		if (temp_min>P.at(i)){
			temp_min = P.at(i);
		}
	}
	cout << temp_min << '\n';
	}
}

}



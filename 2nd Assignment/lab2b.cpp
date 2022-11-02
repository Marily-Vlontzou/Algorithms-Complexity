#include <iostream> 
#include <bits/stdc++.h>

using namespace std;  

#define MAX 5001

int N,M; 
int input=0;
int input2=0;
char type[2];
int sum=0;
int items=0;
int price=0;
int pan[MAX], xif[MAX], asp[MAX], sum1[MAX], sum2[MAX], sum3[MAX];

void minimumcost(vector <pair <int,  int> > I,  int K[]){
	sum=0;
	fill_n(K, N+1, 1000000001);
	K[0]=0;

	for(int i=0; i<I.size(); i++){
		items=I.at(i).first;
		sum+=items;
		price=I.at(i).second;
		for (int j=min(sum, N); j>=1; j--){
			K[j]=min(K[j], K[max(j-items,0)]+price);
		}
	}

}

int main (){

	scanf("%d" "%d\n", &N, &M);

	vector < pair <int,  int> >  a1, a2, a3, b1, b2, b3, c1, c2, c3;



	for(int i=0; i<M; i++){
		scanf("%s", type);
		scanf("%d" "%d\n", &input, &input2);
		if (type[0]=='1'){
			if(type[1]=='A'){
				a1.push_back(make_pair(input,input2));
			}
			else if (type[1]=='B'){
				b1.push_back(make_pair(input,input2));
			}
			else if(type[1]=='C'){
				c1.push_back(make_pair(input,input2));
			}
		}
		else if (type[0]=='2'){
			if(type[1]=='A'){
				a2.push_back(make_pair(input,input2));
			}
			else if (type[1]=='B'){
				b2.push_back(make_pair(input,input2));
			}
			else if (type[1]=='C'){
				c2.push_back(make_pair(input,input2));
			}
		}
		else if (type[0]=='3'){
			if(type[1]=='A'){
				a3.push_back(make_pair(input,input2));
			}
			else if (type[1]=='B'){
				b3.push_back(make_pair(input,input2));
			}
			else if (type[1]=='C'){
				c3.push_back(make_pair(input,input2));
			}

		}

	}

	int iter1=N;
	int iter2=N;
	int iter3=N;
	int totalCost=1000000001;


	minimumcost(a1,pan);
	minimumcost(b1,xif);
	minimumcost(c1,asp);
	fill_n(sum1, N+1, 0);
	for (int i=0; i<N+1; i++){
		if (pan[i]== 1000000001 || xif[i] == 1000000001 || asp[i]==1000000001) {iter1=i-1; break;}
		sum1[i]=pan[i]+xif[i]+asp[i];
	}

	minimumcost(a2,pan);
	minimumcost(b2,xif);
	minimumcost(c2,asp);
	fill_n(sum2, N+1, 0);
	for (int i=0; i<N+1; i++){
		if (pan[i]== 1000000001 || xif[i] == 1000000001 || asp[i]==1000000001) {iter2=i-1; break;}
		sum2[i]=pan[i]+xif[i]+asp[i];
	}

	minimumcost(a3,pan);
	minimumcost(b3,xif);
	minimumcost(c3,asp);
	fill_n(sum3, N+1, 0);
	for (int i=0; i<N+1; i++){
		if (pan[i]== 1000000001 || xif[i] == 1000000001 || asp[i]==1000000001) {iter3=i-1; break;}
		sum3[i]=pan[i]+xif[i]+asp[i];
	}


	if (iter1+iter2+iter3<N) {totalCost=-1; cout<< totalCost << endl; return 0;}

	for (int i=0; i<=min(N,iter1); i++){
		for (int j=0; j<=min(N-i,iter2); j++){
			if (i+j+iter3>=N) {
				totalCost=min(totalCost, sum1[i]+sum2[j]+sum3[N-i-j]);
			}
		}
	}

	cout <<totalCost<<endl;

	return 0;

}
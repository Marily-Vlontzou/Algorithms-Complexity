#include <iostream>      
#include <bits/stdc++.h>           
      
using namespace std;      
      
int N,K;      
int input=0;      
      
int main () {      
    
    scanf("%d" "%d", &N, &K);      
      
    if (N<=K) {      
        cout << 0 << endl;      
    }       
    else {      
        int count;      
        int b;      
      
        vector <vector <int> > partial;      
        vector<int> col;      
        vector <int> fill;      
        fill.push_back(0);      
        partial.push_back(fill);      
        int E[N+1][N+1];      
        int c=0;      
      
        memset(E, 0, sizeof(int) * (N+1) * (N+1));      
      
        for (int i=1; i<N+1; i++){      
            for (int j=1; j<N-i+1; j++){           
                scanf("%d", &input);      
                E[i][j+i] = input;           
            }      
        }         
      
        for (int i=1; i<N+1; i++){      
            count=0;      
            col.push_back(0);      
            if(i<=K) {c++;}       
            for (int j=i+1; j<N-K+c+1; j++){            
                col.push_back(col.at(count) + E[i][j]);      
                count++;      
            }      
            partial.push_back(col);      
            col.clear();          
        }      
      
        memset(E, 0, sizeof(int) * (N+1) * (N+1));      
        c=N;      
      
        for (int i=N-1; i>0; i--){      
                  
            col = partial.at(i);      
            vector<int>().swap(partial.at(i));      
            if(i<K) {c--;}       
                  
            for(int j=c; j>i; j--){      
                b=col.size();      
                E[i][j] = E[i+1][j] + col.at(b-1);      
                col.pop_back();      
     
            }      
            col.clear();      
        }      
      
        if (K==1){      
            cout << E[1][N] << endl;      
        }      
        else {      
        
            int min;      
            int tem;    
            vector <int> l;     
            vector <int> l2;        
      
            for(int i=2; i<N-K+2; i++){       
                l.push_back(E[1][i]);         
            }       
     
                for(int j=2; j<K; j++){        
                    for (int i=j; i<j+N-K+1; i++){    
                        count=0;      
                        min=E[j][i];      
                        for (int t=j; t<i; t++){    
                            tem=l.at(count)+E[t+1][i];       
                            count++;     
                            if(min>tem) {min=tem;}      
                        }    
    
                        if (j!=i){    
                            l2.push_back(min);    
                        }        
                    } 

                    l=l2;    
                    l2.clear();      
                }    
    
                count=0;    
                int final=E[K][N];      
      
                for (int i=K; i<N; i++){     
                    tem=l.at(count)+E[i+1][N];    
                    count++;        
                    if(final>tem) {final=tem;}          
                }           
      
                cout << final <<endl;         
        }       
    } 
         
    return 0;      
} 
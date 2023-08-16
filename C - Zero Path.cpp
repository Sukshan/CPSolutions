#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <deque>
#include <iomanip> 
#include <stack>
#include <iterator>
#include <complex>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
// ORDERED SET PBDS ( USE less<T> after null type for set and    less_equal<T> for multiset)
template<class T> 
using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 
template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout<<'\n';
}
template<typename T>
void printVectorInVector(const T& t){
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
    cout<<'\n';
}
#define GODSPEED_SPIDERMAN ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define OH_oh(t) int t; cin>>t;
#define ull unsigned long long
#define ll long long
#define pb(i) push_back(i);
#define all(a)  a.begin(), a.end()
#define gall(a) a.begin(), a.end(), greater<int>()
#define mp(a, b)  make_pair(a, b)
#define pbk  pop_back()
#define container_print(a) for(auto &it: a){ cout<<it<<" "; }
#define container_print_both(a) for(auto &it: a){ cout<<it.first<<" "<<it.second<<endl; }
#define check(i) cout<<i<<endl;
#define concatenate(a, b) a.insert(a.end(), b.begin(), b.end());
const ll mod=1e9+7;
const ll moD=998244353;
const ll inf_big=1e18;
const ll inf=1e9;
const ll INF=1e18;
long double pi=2* acos(0.0);

ll expo_mania(ll y, ll x){
    if(x==0) return 1;
    if(x==1) return y;
    else if(!(x&1)) return expo_mania(y*y, x/2);
    else return expo_mania(y*y, x/2)*y;
}


int nlim, plim;
int n, m; 
int dfs(int i, int j, int cur_sum, vector<vector<short>>& v, int left){
    if(i>n or j>m or i<1 or j<1) return -1;
    if(i==n and j==m and cur_sum==0){
        return 0;
    }
    if(cur_sum<nlim or cur_sum>plim){
        return -1;
    }
    if(left<abs(cur_sum)){
        return -1;
    }
    return max(dfs(i+1, j, v[i+1][j]==1? cur_sum+1: cur_sum-1, v, left ), dfs(i, j+1, v[i][j+1]==1? cur_sum+1: cur_sum-1, v, left ));
}


int main(){
    GODSPEED_SPIDERMAN;
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<vector<int>>> v(n+2, vector<vector<int>>(m+2, vector<int>(3, inf)));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>v[i][j][0];
                v[i][j][2]=-1*inf;
            }
        }
        // 1 for min and 2 for max
        v[n][m][1]=v[n][m][0];
        v[n][m][2]=v[n][m][0];
        int lim= n+m-1;
        if(lim&1){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=n; i>=1; i--){
            for(int j=m; j>=1; j--){
                if(i==n and j==m) continue;
                if(j==m or i==n){
                    if(i==n){
                        v[i][j][1]= v[i][j][0]+v[i][j+1][1];
                        v[i][j][2]= v[i][j][0]+v[i][j+1][2];
                    }
                    else{
                        v[i][j][1]= v[i][j][0]+v[i+1][j][1];
                        v[i][j][2]= v[i][j][0]+v[i+1][j][2];
                    }
                    continue;
                }
                v[i][j][1]= v[i][j][0]+ min(v[i][j+1][1], v[i+1][j][1]);
                v[i][j][2]= v[i][j][0]+ max(v[i+1][j][2], v[i][j+1][2]);
            }
        }
        if(v[1][1][1]<=0 and v[1][1][2]>=0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

//int
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

ull expo_mania(ull a, ull b, ull m){
    if(b<=1){
        if(b==0) return 1;
        return a;
    }
    if(b&1) return expo_mania((a*a)%m, b/2, m)*b%m;
    return expo_mania((a*a)%m, b/2, m)%m;
}

// int lcs( int i, int j, string &s1, string &s2 , vector<vector<int>& dp){
    
//     if(i<0 or j<0) return 0;

//     if( dp[i][j]>0 ){
//         return dp[i][j];
//     }
//     else{
//         if( s1[i] == s2[j] ){
//             dp[i][j]= 1+ lcs( i-1, j-1, s1, s2 );
//         }
//         else{
//             dp[i][j]= max( lcs( i-1, j, s1, s2 ), lcs( i, j-1, s1, s2 ) );
//         }
//     }
//     return dp[i][j];
// }

int dfs(int cur, char og, string &s, vector<int> v){
    if(s[cur-1]== og){
        return 1;
    }
    return 1+ dfs(v[cur], og, s, v);
}   



int main(){
    GODSPEED_SPIDERMAN;
    OH_oh(t);
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> v(n+1);
        vector<int> parent(n+1), cur(n+1);
        for(int i=1; i<=n; i++){
            cin>>v[i];
        }
        vector<int> lcm;
        bool fir=1;
        int gc=1,  lc=1;
        for(int i=0; i<n; i++){
            int x= dfs(v[i+1], s[i], s, v);
            if(fir){
                fir=0;
                gc=x;
                lc=x;
            }
            else{
                gc= gcd(lc, x);
                lc= (lc*x)/gc;
            }
        }
        cout<<lc<<endl;

    }
}
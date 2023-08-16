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
// find_by_order(k)  returns iterator to (k+1)th element 1,2,3,4 so, fbo(3)=4, o based indexing
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

ll expo_mania(ll x, ll y){
    if(y==0) return 1;
    else if(y==1) return x;
    else if(y&1) return ((expo_mania((x*x), y/2)*x));
    else return expo_mania((x*x), y/2);
}

ll expo_mania(ll x, ll y, ll m){
    if(y==0) return 1;
    else if(y==1) return x;
    else if(y&1) return ((expo_mania((x*x)%m, y/2, m)*x)%m);
    else return expo_mania((x*x)%m, y/2, m);
}
int main(){
    GODSPEED_SPIDERMAN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<1<<" ";
        for(int i=3; i<=n; i++){
            cout<<i<<" ";
        }
        cout<<2<<" ";
        cout<<endl;
    }
}
// ll intint intint lllllll
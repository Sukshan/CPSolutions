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
    int n; cin>>n;
    string s; cin>>s;
    int f1=0;
    while(s[f1]!='1' and f1<n) f1++;
    vector<int> starts, zeros;
    if(f1==n){
        cout<<0<<endl;
        return 0;
    }

    while(s[f1]=='1' and f1<n){
        starts.pb(f1+1);
        f1++;
    }
    if(f1==n){
        bool yes=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1') yes=1;
            if(yes){
                cout<<s[i];
            }
        }
        return 0;
    }
    for(int i=f1; i<n; i++){
        if(s[i]=='0'){
            zeros.pb(i+1);
        }
    }
    for(int i=1; i<zeros.size(); i++){
        int gap= zeros[i]- zeros[0]+1;
        vector<int> v;
        for(int j=0; j<starts.size(); j++){
            if(s[starts[j]+gap-2]=='1'){
                v.pb(starts[j]);
            }
        }
        if(v.empty()==1) continue;
        starts=v;
    }
    string temp=s;
    if(starts.empty()!=1){
        for(int i=zeros[0]-1, j=starts[0]-1; i<n and j<n; j++, i++){
            if(s[i]=='0' and s[j]=='1'){
                temp[i]='1';
            }
        }
    }
    bool yes=0;
    for(int i=0; i<s.length(); i++){
        if(temp[i]=='1') yes=1;
        if(yes){
            cout<<temp[i];
        }
    }
    return 0;
}
// ll intint intint lllllll
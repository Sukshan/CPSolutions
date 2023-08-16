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


int main() {
    GODSPEED_SPIDERMAN;
    OH_oh(t);
    while(t--){
        ll n; cin>>n;
        vector<ll> v;
        bool start=1;
        for(int i=0; i<n; i++){
            ll x; cin>>x;
            if(start and x<=0){
                continue;
            }
            start=0;
            v.pb(x);
        }
        while(v.empty()!=1 and v.back()<=0 ) v.pop_back();
        vector<ll> rv, diff;
        n= v.size();
        bool pos=1;
        ll cur_neg_sum=0;
        if(v.empty()!=1) rv.pb(v[0]);
        // printVector(v);
        for(int i=1; i<n; i++){
            if(v[i]>0){
                rv.pb(cur_neg_sum);
                rv.pb(v[i]);
                cur_neg_sum=0;
            }
            else cur_neg_sum+= v[i];
            if(v[i]>0 and v[i-1]>0){
                pos=0;
                break;
            } 
        }
        // printVector(rv);
        for(int i=1; i<rv.size(); i++){
            if(rv[i]+ rv[i-1]!=0) diff.pb(rv[i]+ rv[i-1]);
        }
        // printVector(diff);
        for(int i=1; i<diff.size(); i++){
            if(diff[i]>0 and diff[i-1]>0) pos=0;
        }
        if(pos){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
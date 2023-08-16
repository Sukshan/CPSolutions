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
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
pair<ll, ll> extended_gcd(ll a, ll b){
    if(b==0) return {1, 1};
    else{
        pair<ll, ll> z= extended_gcd(b, a%b);
        ll x= z.second, y= z.first- (a/b)*z.second;
        return {x, y};
    }
}
ll expo_mania(ll y, ll x){
    if(x==0) return 1;
    if(x==1) return y;
    else if(!(x&1)) return expo_mania(y*y, x/2);
    else return expo_mania(y*y, x/2)*y;
}
ll expo_mania(ll y, ll x, ll m){
    if(x==0) return 1;
    if(x==1) return y;
    else if(!(x&1)) return expo_mania((y*y)%m, (x/2)%m, m)%m;
    else return expo_mania((y*y)%m, (x/2)%m, m)*y%m;
}
int tarr[1];
void sieve(){
    tarr[1]=1;
    for(ll i=2; i*2<=9999998; i++){
        tarr[i*2]=1;
    }
    for(ll i=3; i<=9999; i+=2){
        for(ll j=2; j*i<=9999999; j++){
            tarr[j*i]=1;
        }
    }
}
double radian(double x){
    double ans=x*pi;
    ans=ans/(double)180;
    return ans;
}
int N=500050;
vector<ll> fac(N+9);
void prec(ll m){
    fac[0]=1;
    for(int i=1; i<N+1; i++){
        fac[i]=(fac[i-1]*i)%m;
    }
}
ll ncalr(ll x, ll y, ll m){
    if(x == y) return 1;
    if(y==0) return 1;
    ll n = fac[x];
    ll d = (fac[y]* fac[x-y]) %m;
    ll ans = (n * expo_mania(d, m-2, m) )%m;
    return ans;
}
ll npr(ll x, ll y, ll m){
    ll n= fac[x];
    ll d= fac[x-y];
    return (n/d)%m;
}


int main() {
    GODSPEED_SPIDERMAN;
    OH_oh(t);
    while(t--){
        int n; cin>>n;
        map<string, int> mp;
        vector<int> (500, 0);
        vector<string> v(2*n);

        for(int i=0; i<2*n; i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        string og;
        cin>>og;
        string cur="";
        int k= mp.size();
        int dist=0;
        for(int i=0; i<og.size(); i++){
            cur+=og[i];
            if(mp[cur]>0){
                mp[cur]--;
                dist++;
                cur="";
            }
        }
        for(auto it: mp){
            if(it.second>=4 or it.second==1 and it.first.length()==1){
                cout<<it.first<<endl;
                break;
            }
        }
    }
}
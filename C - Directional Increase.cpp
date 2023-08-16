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
using namespace std;
#define GODSPEED_SPIDERMAN ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define OH_oh(t) int t; cin>>t;
#define ll long long
#define pb(i) push_back(i);
#define all(a)  a.begin(), a.end()
#define gall(a) a.begin(), a.end(), greater<int>()
#define mp(a, b)  make_pair(a, b)
#define pbk  pop_back()
#define container_print(a) for(auto &it: a){ cout<<it<<" "; }
#define container_print1(a) for(auto &it: a){ cout<<it.first<<" "<<it.second<<endl; }
#define container_sit(cont, it, a, type) cont<type>:: iterator it= a.begin();
#define container_eit(cont, it, a, type) cont<type>:: iterator it= a.end();
const ll mod=1e9+7;
const ll moD=998244353;
const ll INF=1e18;
const ll inf=1e9;
long double pi=2* acos(0.0);

ll expo_mania(ll y, ll x, ll m){
    if(x==0) return 1;
    if(x==1) return y;
    else if(!(x&1)) return expo_mania((y*y)%m, (x/2)%m, m)%m;
    else return expo_mania((y*y)%m, (x/2)%m, m)*y%m;
}

template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout<<'\n';
}

template<typename T>
void printVectorInVector(const T& t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

int tarr[1];
void vuid(){
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

int N=8000;
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

bool is_pali(string & s){
    for(int i=0, j=s.length()-1; i<j; i++, j--){
        if(s[i]!=s[j]) return false;
    }
return true;
}

int main(){
    GODSPEED_SPIDERMAN;
    OH_oh(t);
    while(t--){
        ll n; cin>>n;
        if(n==1){
            ll a; cin>>a; 
            if(a==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        vector<ll> v(n);
        ll pre=0;
        for(ll i=0; i<n; i++){
            cin>>v[i];
            pre+=v[i];

        }
        if(pre!=0){
            cout<<"NO"<<endl;
            continue;
        }
        int re=0, rei=0;
        for(int i=n-1; i>=0; i--){
            if(v[i]!=0){
                re=v[i];
                rei=i;
                break;
            }
        }
        int le=v[0];
        if(le<=0 or re>=0 or rei==0){
            if(le==0 and re==0 and rei==0){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
            continue;
        }
        pre=0;
        bool pos=1;
        for(int i=0; i<rei; i++){
            pre+=v[i];
            if(pre<=0){
                pos=0;
            }
        }
        if(!pos){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
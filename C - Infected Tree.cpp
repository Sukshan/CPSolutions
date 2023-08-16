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
// find_by_order(k)  returns iterator(which we need to dereference) to kth element starting from 0;
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


int depthu_and_sizeu(int cur, vector<bool>& visited, int depth, vector<vector<int>> &v, vector<int>& dpt, vector<int>& st){
    visited[cur]=1;
    dpt[cur]= depth;
    for(int i=0; i<v[cur].size(); i++){
        ll j= v[cur][i];
        if(!visited[j]){
            st[cur]+= depthu_and_sizeu(j, visited, depth+1, v, dpt, st);
        }
    }
    return st[cur];
} 

int sol(int cur, vector<vector<int>> & v, vector<int> & subtree_size, vector<bool> & visited, int ans, bool to_add){
    if(cur<1) return 0;
    visited[cur]=1;
    if(to_add){
        return subtree_size[cur];
    }
    if(v[cur].size()<=2){
        if(v[cur].size()==1 and cur!=1) return 0;
        else if(v[cur].size()==1) return subtree_size[v[cur][0]]-1;
        int child;
        if(cur==1){
            int c1= v[cur][0], c2=v[cur][1];
            return max( subtree_size[c2]-1+ sol(c1, v, subtree_size, visited, ans, 0), subtree_size[c1]-1 + sol(c2, v, subtree_size, visited, ans, 0));
        }
        if(visited[v[cur][0]]) child= v[cur][1];
        else child= v[cur][0];
        return subtree_size[child]-1;

    }
    int c1=0, c2=0;
    for(int i=0; i<v[cur].size(); i++){
        if(!visited[v[cur][i]]){
            if(c1==0){
                c1=v[cur][i];
            }
            else c2=v[cur][i];
        }
    }
    return max( subtree_size[c2]-1+ sol(c1, v, subtree_size, visited, ans, 0), subtree_size[c1]-1 + sol(c2, v, subtree_size, visited, ans, 0));
    return 0;
}

int main(){
    GODSPEED_SPIDERMAN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> v(n+1);
        for(int i=1; i<n; i++){
            int a, b; cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        vector<int> subtree_size(n+2, 1), depth(n+2, 0);

        vector<bool> visited(n+2, 0), mark(n+2, 0);
        int kk= depthu_and_sizeu(1, visited, 0, v, depth, subtree_size);
        // for(int i=1; i<=n; i++){
        //     cout<<i<<" "<<depth[i]<<" "<<subtree_size[i]<<endl;
        // }
        subtree_size[0]=0;
        int ans= sol(1, v, subtree_size, mark, 0, 0);
        cout<<ans<<endl;
    }
}
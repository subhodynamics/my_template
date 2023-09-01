//! We can go up or down, either ways I am prepared

//! Hello there! Subhadeep this side.

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mid(low, high) (low + ((high - low) >> 1))

const int64_t MOD = 1000000007;
const int64_t MOD1 = 998244353;
const int64_t INF = (int64_t)1e18;

using ll = int64_t;
using ull = uint64_t;
using lld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


template<class T> inline  T nxt(T) {
    T x;
    cin >> x;
    return x;
}


void solve() {
    int n;
    cin >> n; 
    vector<ll> height(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }

    sort(all(height));

    if (n == 2) {
        cout << height[1] << " " << height[2] << nline;
        return;
    }
    

    int diff = INT_MAX;
    int chosen = 0;

    for (int i = 1; i < n; i++) {
        if (abs(height[i] - height[i+1]) < diff) {
            diff = abs (height[i] - height[i+1]);
            // ans[1] = height[i];
            // ans[n] = height[i+1];

            chosen = i;

            // cout << "-----------" << nline;
            // cout << ans[1] << nline;
            // cout << ans[n] << nline;
            // cout << diff << nline;
            // cout << chosen << nline;
            // cout << "-----------" << nline;
        }
    }

    for (int i = (chosen+1); i <= n; i++) cout << height[i] << " ";
    for (int i = 1; i <= chosen; i++) cout << height[i] << " ";
    cout << nline;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

fastio();
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    
    return 0;
}
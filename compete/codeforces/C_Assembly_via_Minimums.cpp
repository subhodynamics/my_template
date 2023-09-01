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

pair <const int, const int> mod = {1e9 + 7, 1e9 + 9};

pair <int, int> get_hash (string s) {

    int n = s.size();

    pair <int, int> h = {0, 0};

    // hash bana rhe hai (taking each char of string s, one at a time)
    for (int i = 0; i < n; i++) {
        h.first = (h.first * 31 + (s[i] - 'a' + 1)) % mod.first;
        h.second = (h.second * 53 + (s[i] - 'a' + 1)) % mod.second;
    }

    return h;
}

void solve() {
    string s, pattern;
    cin >> ws >> s;
    cin >> ws >> pattern;

    int n = s.length(), m = pattern.length();

    pair <int, int> power = {1, 1}; //power should start from 1 otherwise if 0 then will give 0 always

    //power ka array pehle se calc krke rakh le rhe hai
    for (int i = 0; i < m - 1; i++) {
        power.first = (power.first * 31) % mod.first;
        power.second = (power.second * 53) % mod.second; //here creating p^something wala
    }

    pair <int, int> ht = get_hash(pattern); //hash of whole pattern
    pair <int, int> hs = get_hash (s.substr(0, m)); //hash of whole string

    int count = 0; 
    count += (hs == ht); //if WHOLE string and pattern are the same

    
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
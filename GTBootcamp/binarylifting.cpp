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

vvi adj;

// parents[0] is getting passed as reference, and this dfs will populate parent[0] for every single node
void dfs(int current, int parent, vector<int>& firstParent) {
    firstParent[current] = parent;
    for (int neighbour : adj[current]) {
        if (neighbour == parent) continue;
        else {
            dfs(neighbour, current, firstParent);
        }
    }
}

int kthparent (int x, int k, vector<vector<int>>& parent) {
    int n = parent[0].size();

    for (int i = 0; i <= log2(n); i++) {
        if (k & (1<<i))
            x = parent[i][x];
        if (x == -1) break;
    }
    return x; 
}

void solve() {
    int n;
    cin >> n;

    adj.resize(n, vi());

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // vector<vector<int>> parent1 (n, vector<int> (log2(n)+1));
    vector<vector<int>> parent (log2(n)+1, vector<int> (n, -1));

    // find out the 2^kth parent of node i
    // parent[k][i] = 2^kth  parent of node i
    // parent[k][i] = 2 ^ (k-1) parent of [2^(k-1) parent of i]
    // [2 ^ (k-1)th parent of i] = [intermediate]

    dfs (0, -1, parent[0]);  //parent[0] has 2^0th parent of every node

    for (int k = 1; k <= log2(n); k++) { //this is basically parents

        for (int i = 0; i < n; i++) { //looping over all the nodes, this will help populating for all the nodes

            int intermediate = parent[k-1][i];

            if (intermediate != -1) { //if intermediate exists
                parent [k][i] = parent [k-1][intermediate];
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

fastio();
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    
    return 0;
}
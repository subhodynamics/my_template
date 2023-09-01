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
vi color;

// sameornot is integer will contain the vertex if all color same otherwise -1;

bool dfs (int current, int parent, int thiscolor) {

    if (color[current] != thiscolor) return false;

    for (auto x : adj[current]) {
        if (x != parent) 
        if (!dfs(x, current, thiscolor)) return false;
    }
    return true;
}

bool check (int node) {
    for(int x : adj[node]){
        if(!(dfs(x, node, color[x]))){
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    adj.resize(n+1, vi());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    color.resize(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> color[i];

    int root1 = -1, root2 = -1;
    bool foundDiff = false; //didn't found an edge with diff color
    // if didn't found and edge with diff color, then all are same, thus any vertex can be the answer
    for (int i = 1; i <= n; i++) {
        if (foundDiff) break;
        for (auto node : adj[i]) {
            if (color[i] != color[node]) {
                foundDiff = true;
                //either the i or the node will be the answer
                // int ans = dfs (i, -1, color[i], i, 0);
                // if i is the answer, then all its child must be of same color
                root1 = i;
                root2 = node;
            }
        }
    }

    if (!foundDiff) {
        cout << "YES" << nline << "1" << nline;
        return;
    }

    else    {
        if (check (root1)) cout << "YES" << nline << root1 << nline;
        else if (check(root2)) cout << "YES" << nline << root2 << nline;
        else cout << "NO" << nline;
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
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

/* 
Type of paths here can be :
1) A --> B
2) A --> LCA --> B
*/

vvi adj;
vi depth;

void dfs (int curr, int parent, vi& firstparent) {
    depth[curr] = depth[parent] + 1;
    firstparent[curr] = parent;
    for (auto neighbour : adj[curr]) {
        if (neighbour != parent) dfs(neighbour, curr, firstparent);
    }
}

int findkthparent (int k, int node, vvi& parent) {
    for (int i = 0; i <= 30; i++) {
        if (k  & (1 << i)) { //checking whether ith bit of k is set or not
            node = parent[i][node];
            if (node == -1) return -1;
        }
    }
    return node;
}

int lca (int nodeA, int nodeB, vvi& parent) {
    
    // i want nodeA always higher than nodeB
    if (depth[nodeA] > depth[nodeB]) swap(nodeA, nodeB);

    //  now i want nodeA and nodeB at same level
    if (depth[nodeB] < depth[nodeA]) {
        int diff = depth[nodeB] - depth[nodeA];
        nodeB = findkthparent(diff, nodeB, parent);
    }

    for (int k = 31; k >= 0; k--) {
        int parent_nodeA = parent[k][nodeA];
        int parent_nodeB = parent[k][nodeB];

        if (parent_nodeA != parent_nodeB) {
            nodeA = parent_nodeA;
            nodeB = parent_nodeB;
        }
        if (nodeA == nodeB) return nodeA;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n, vi());
    depth.resize(n, -1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // I need to find the LCA here

    vvi parent (32, vi(n));

    dfs (0, -1, parent[0]); //2^0th parent of all => here in parent[0], 0 means 2^0 = 1st parent

    for (int k = 0; k < 32; k++) {
        for (int i = 0; i < n; i++) {
            // parent[k][n] = parent[k-1][parent[k-1][n]];
            int intermediate = parent[k-1][n];
            parent[k][n] = (intermediate != -1) ? parent[k-1][intermediate] : -1;
        }
    }

    // findkthparent of n -> k , n, parent


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
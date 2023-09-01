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

void dfs (int current, int parent, vi& firstparent) {
    firstparent[current] = parent;
    for (auto neighbour : adj[current]) {
        if(neighbour != parent) {
            dfs(neighbour, current, firstparent);
        }
    }
}

//find kth parent of node x
int findKthparent (int k, int x, vvi& parent) {
    // here we are getting the number of nodes
    int n = parent[0].size(); 

    // iterate over posbl bits (basically, number of bits required to represent n nodes)
    for (int i = 0; i <= log2(n); i++) {

        //now check if the i'th bit is ON in number k
        if (k & (1 << i)) {
            // x was the start point, now x got updated. we jumped.
            // now 2^i'th parent of x is the new x, next if (i+1) bit is ON in k, then
            // 2^(i+1)'th parent of x (new, 2^i'th) is the new x. finally x reaches to the desired parent.
            // for example binary(3) => 00011 so 3rd parent of x, first will be 1st parent of x is the new x
            // then [(i+1) => 2nd] bit is set, so 2nd parent of x (new, 1st parent of x) is the new x. finally x reaches to the desired parent.
            x = parent[i][x];
        }
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

    //parent[k][x] => 2^kth parent of x
    vector<vector<int>> parent (log2(n)+1, vector<int> (n, -1));

    // calling dfs on root, basically, dfs(root, -1, parent[0])
    dfs(0, -1, parent[0]);

    for (int k = 1; k <= log2(n); k++) {
        for (int i = 0; i < n; i++) {

            int intermediate = parent[k-1][i];

            if (intermediate != -1)
                parent[k][i] = parent[k-1][intermediate];
        }
    }
    debug(parent);

    //now find the kth parent

    int q;
    cin >> q;
    while (q--) {
        int k, x;
        cin >> k >> x;
        cout << findKthparent(k, n, parent);
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
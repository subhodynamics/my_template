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

//finding the LCA using binary lifting     [O(Log2(n) * Log2(n))] time complexity 
/* 
step 1: first checkt the level of both the node whose LCA you want to find
if they are at the same level compared to the root, then fine, otherwise bring them to the same level
level A = x, level B = y
(y > x) then, 
(y-x) th parent of b (level) will be same as a's level, bring b to that level
step 2: now they are at the same level, then take a, b to the level where 1st parent of a, b will be the lca
we will use binary search in this case, by using binary search we will find the node whose 1st parents are same for both a, b
this will be done by having a parity function.
*/

vvi adj;
vi level;
int c = 1;

void dfs (int curr, int parent, vi& firstparent) {

    firstparent[curr] = parent;

    if (parent == -1)    level[curr] = 0;
    else    level[curr] = level[parent] + 1;

    for (auto neighbour : adj[curr]) {
        if (neighbour != parent) {
            dfs(neighbour, curr, firstparent);
        }
    }
}

int findKthparent (int k, int node, vvi& parent) {
    int n = sz(parent[0]);

    for (int i = 0; i <= log2(n); i++) {
        if (k & (1 << i)) {
            node = parent[i][node];
        }
        if (node == -1) break;
    }
    return node;
}

//?  BINARY SEARCH

int find_last_false (int lo, int hi, int nodeA, int nodeB, vvi& parent) {
    //mid is the level, and hi, lo are also the levels 

    int ans = nodeA;

    while (lo <= hi) {
        int mid = mid (lo, hi);
        if (findKthparent(mid, nodeA, parent) != findKthparent(mid, nodeB, parent)) { //dono same nhi hai
            lo = mid + 1;
            ans = findKthparent(mid, nodeA, parent);
        } else { //agar dono same hai
            hi = mid - 1;
        }
    }

    return findKthparent(1, ans, parent);
}

void solve() {
    int n;
    cin >> n;

    cout << "Case " << c++ <<":" << nline;

    adj.clear(), level.clear();
    adj.resize(n, vi());
    level.resize(n, 0);

    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int u;
            cin >> u;
            u--;
            adj[i-1].pb(u);
        }
    }

    vvi parent (32, vi(n, -1));

    dfs(0, -1, parent[0]);

    for (int k = 1; k <= log2(n); k++) {
        for (int i = 0; i < n; i++) {
            int intermediate = parent[k-1][i];

            //if intermediate is -1, then further parent will exist, otherwise not;
            parent[k][i] = (intermediate != -1) ? parent[k-1][intermediate] : -1;
        }
    }
    int  q;
    cin >> q;
    while (q--) {
        int nodeA, nodeB; // want to find the LCA of these two nodes
        cin >> nodeA >> nodeB;
        nodeA--, nodeB--;


        //here i tried bringing nodeA and nodeB to the same level, if the aren't
        if (level[nodeA] > level[nodeB]) swap(nodeA, nodeB); //swapped cause i wanted level[nodeA]  < level[nodeB], always, if not same.

        if (level[nodeA] < level[nodeB]) {
            int diff_in_level = level[nodeB] - level[nodeA];
            nodeB = findKthparent(diff_in_level, nodeB, parent);
        }


        if (nodeA == nodeB) {
            cout << nodeA+1 << nline;
            continue;
        }

        int ans = find_last_false (0, level[nodeA], nodeA, nodeB, parent);
        cout << ans + 1 << nline;
    }
    
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
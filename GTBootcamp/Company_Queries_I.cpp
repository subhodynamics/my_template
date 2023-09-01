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

//this is to fill up the first parent
void dfs (int curr, int parent, vvi& edges, vi& firstparent) {
    firstparent[curr] = parent;
    for (auto neighbour : edges[curr]) {
        if (neighbour != parent)
        dfs(neighbour, curr, edges, firstparent);
    }
}

int kthparent(int x, int k, vvi& parent) {

    int n = (int)parent[0].size();
    for (int i = 0; i <= log2(n); i++) {
        if (k & (1 << i)) 
            x = parent[i][x];

        if (x == -2) 
            break; 
    }
    return x;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vvi edges(n, vi());

    //parent[0] = -1
    // basically zero based indexing kr rhe hai to 0 is the root
    // whereas acc to the statement 1 is the root
    
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        // x is the boss of i
        x--;
        edges[x].push_back(i);
    }

    debug(edges);

    vvi parent(log2(n)+1, vector<int>(n, -2)); debug(parent);

    dfs(0, -2, edges, parent[0]);

    for (int k = 1; k <= log2(n); k++) { //this is for the set bits
        for (int i = 0; i < n; i++) { //traversing in every node to fillup the parent table for every node

            int intermediate = parent[k-1][i];
            
            if (intermediate != -2) //this means if intermediate exists
                parent[k][i] = parent[k-1][intermediate];
        }
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        cout << kthparent(x, k, parent) + 1<< nline;
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
//! We can go up or down, either ways I am prepared

//! Hello there! Subhadeep this side.

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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
    int n, m,d;
    cin >> n >> m >> d;

    vector<int> p (n+1);
    vector<int> pos(n+1);
    vector<int> a(m+1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;

    /* int ans = pos[a[i+1]]-pos[a[i]];

    for (int i = 1; i < m; i++) {
        if ((pos[a[i]] >= pos[a[i+1]]) || (pos[a[i+1]] > pos[a[i]] + d)) {
            cout << "0" << nline;
            return;
        } else {
            int dist = ((pos[a[i]] + d) - pos[a[i+1]]);

            //(abs(dist - a[i]) >= 0) || (abs(dist+a[i+1] <= n
            int maybe = (dist < (pos[a[i]] - 1)  )?dist:INT_MAX;
            cout << min(ans, maybe) << nline;
            return;
        }
    } */

    for (int i = 1; i < m; i++) {
        int a1 = a[i], a2 = a[i+1];
        if ((pos[a1] >= pos[a2]) || (pos[a2] > pos[a1]+d)) {
            ans = 0;
            break;
        }
        ans = min (ans, pos[a2]-pos[a1]);
        int dist = pos[a2] - pos[a1]; // (d+a1)......a2......a1
        int swapsNeeded = abs(d - dist + 1);
        int swapsPosbl =  (n - pos[a2]) + (pos[a1] - 1); // n....a2.....a1....1
        if (swapsPosbl>=swapsNeeded) {
            ans =  min(ans, swapsNeeded);
        }
    }
    cout << ans << nline;
  
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
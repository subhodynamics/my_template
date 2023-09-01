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
    ll n, m;
    cin >> n >> m;
    // ll arr[n][m];
    vector<vector<ll>> arr(m,vector<ll> (n,0));
    // memset(arr,0,sizeof(arr));

    for (ll i = 0; i < n; i++) { 
        for (ll j = 0; j < m; j++) {
            ll temp;
            cin >> temp;
            arr[j][i] = temp;
        }
        
    }

    ll ans = 0;
    
    for (ll i = 0; i < m;i++) {
        vector<ll> tempvec = arr[i];
        sort (all(tempvec)); //asc order
        ll sum = 0;
        for (ll j = 0; j < n; j++) {
            sum += tempvec[j];
        }
        // ans += sum;
        ll sizeoftempvec = sz(tempvec);
        for (int j = 0; j < n-1; j++) {
            ans += abs(sum - (tempvec[j] * (sizeoftempvec)));
            sum -= tempvec[j];
            sizeoftempvec--;
        }
    }




    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         cin >> arr[i][j];
    //     }
    // }

    // ll ans = 0;
    // vector<vector<int>> vec (m+1, vector<int> (n+1,0));

    // // TRANSPOSING
    // for (int i = 0; i < m; i++){
    //     for (int j = 0; j < n; j++){ 
    //         vec[i].pb(arr[j][i]);
    //         vec[i][m] += arr[j][i];
    //     }
    // }

    // sort(all(vec));
    
    // for (int i = 0; i < n-1; i++) {
    //     for (int j = i+1; i <= m; j++) {
    //         ans += abs (vec[i][m] - vec[j][m]);
    //     }
    // }
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
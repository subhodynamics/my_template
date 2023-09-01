/* Priyansh Agarwal*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

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
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef Priyansh31dec
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

using ll = long long;
using ull = unsigned long long;
using lld = long double;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

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
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case " << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/
void dfs(int current, vector<vector<int>>& edges, int parent, vector<int>& firstParents){
    firstParents[current] = parent;
    for(auto neighbour: edges[current]){
        if(neighbour != parent)
            dfs(neighbour, edges, current, firstParents);
    }
}
int kthParent(int x, int k, vector<vector<int>>& parents){
    int n = parents[0].size();
    for(int i = 0; i <= log2(n); i++){
        if(k & (1 << i)){
            x = parents[i][x];
            if(x == -2)
                break;
        }
    }
    
    // k = 84  -> 64 + 16 + 4
    // x -4th parent-> y -16th parent-> z -64th parent-> w
    return x;
    
    // (1 << i) = 2^i
    // k = 15 & 8 -> 8
    
    
    // 0000000000001
    // 0000000000010
    // 0000000000100
    // 0000000001000
    
    // 0101010100111
        // AND
    // 0000010000000
    //----------------
    // 0000010000000

    // 0101000100111
        // AND
    // 0000010000000
    //----------------
    // 0000000000000
}
void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> edges(n, vector<int>());
    // parent[0] = -1
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        edges[x].push_back(i);
    }
    vector<vector<int>> parents(log2(n) + 1, vector<int>(n));
    // parents[log2(n) + 1][n]
    // parents[k][i] = 2^kth parent of i
    dfs(0, edges, -2, parents[0]);
    for(int k = 1; k <= log2(n); k++){
        // find out the 2^kth parent of every node
        // parents[k][i] = 2^kth parent of node i
        // parents[k][i] = 2^(k - 1)th parent of [ 2^(k-1)th parent of i ]
        // i -> intermediate -> goal
        // goal = 2^kth parent of i
        // goal = 2^(k - 1)th parent of intermediate
        // intermediate = 2^(k - 1)th parent of i
        for(int i = 0; i < n; i++){
            // parents[k - 1][i] = intermediate
            int intermediate = parents[k - 1][i];
            // parents[k][i] = parents[k - 1][intermediate]
            if(intermediate != -2)
                parents[k][i] = parents[k - 1][intermediate];
            else
                parents[k][i] = -2;
        }
    }
    for(int i = 0; i < q; i++){
        int x, k;
        cin >> x >> k;
        x--;
        cout << kthParent(x, k, parents) + 1 << endl;
    }
    
}

int main() {
#ifdef Priyansh31dec
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Priyansh31dec
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
}
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

struct asst {
    int iTime;
    int balloons;
    int restTime;
};

int n, m;

int countMaxBalloons(int t, int z, int y, int maxTime) {
    int totalBalloons = 0;
    int batchTime = (z*t) + y;
    int batchCount = maxTime/batchTime;
    int remainTime = maxTime%batchTime;
    totalBalloons += batchCount*z; //each batch has z balloons
    if (remainTime != 0) {
        //can we inflate z balloons
        if (remainTime/t >= z) {
            totalBalloons += z;
        } else {
            totalBalloons += remainTime/t;
        }
    }
    return totalBalloons;
}

bool checkBalloons (int t, int z, int y, int midBalloons, int midTime) {
    int batchTime = (z*t) + y; //one batch
    int batches = midBalloons/z;
    int currentTime = 0;
    // return (((batches-1)*batchTime + (z*t)) <= midTime);
    bool last = (midBalloons % z == 0)?1:0;
    if (last) {
        currentTime = ((batches-1)*batchTime) + (z*t);
    }
    else {
        currentTime = (batches * batchTime) + ((batches%z) * t);
    }
    return (currentTime <= midTime);
}

bool checkPosbl (asst * arr, int midtime) { //this time is the midTime
    int totalInflatedBalloons=0;
    for (int i = 0; i < n; i++) {

        int t = arr[i].iTime; //infalte one balloon
        int z = arr[i].balloons; //rest after z balloons
        int y = arr[i].restTime; //rest time

        int lo = 0, hi = 1e9;
        while (lo+1 < hi) {
            int midBalloons = mid(lo, hi);
            //since all can try inflating simultaneously so will find one by one
            //is it poslb for this asst to inflate this midballoons in time;
            if (checkBalloons(t, z, y, midBalloons, midtime)) {
                lo = midBalloons;
            } else {
                hi = midBalloons;
            }
        }
        totalInflatedBalloons += lo;
    }
    return (totalInflatedBalloons >= m);
}

void solve() {
    cin >> m >> n;
    asst arr[n]; //struct asst created to store the values

    for (int i = 0; i < n; i++) {
        cin >> arr[i].iTime >> arr[i].balloons >> arr[i].restTime; //stored the values
    }

    int minTime = -1, maxTime = 1e9; //setting up the binary search

    while (minTime+1 < maxTime) {

        int midTime = mid(minTime, maxTime);
        
        //? [ is it posbl to inflate all the balloons in midTime? ]
        if (checkPosbl(arr, midTime)) { //checking the feasiblity in the check function
            maxTime = midTime;
        } else {
            minTime = midTime;
        }
    }

    cout << maxTime << nline; //time to infalte m balloons
    for (int i = 0; i < n; i++) {
         int t = arr[i].iTime; //infalte one balloon
        int z = arr[i].balloons; //rest after z balloons
        int y = arr[i].restTime; //rest time
        cout << countMaxBalloons(t, z, y, maxTime) <<" ";
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
// find the count of numbers between L and R which have a sum of digit == x;

#include <iostream>

using namespace std;


//recursive solution
int solve (string& num, int n, int x, bool tight) {
    if (x < 0) return 0;
    if (n == 1) {
        if (x >= 0 && x <= 9) return 1;
        else return 0;
    }
    int answer = 0;
    int ub = tight ? (num[(num.length() - n)] - '0') : 9;

    for (int dig = 0; dig <= ub; dig++) {
        answer += solve(num, n-1, x - dig, (tight &(dig == ub)));
    }

    return answer;
}

//bruteforce solution
bool help(int num, int x) {
    int sum = 0;
    while (num) {
        sum += num%10;
        num/=10;
    }
    return (sum == x);
}

int bruteforce (int l, int r, int x) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (help(i,x)) count++;
    }

    return count;
}

int main() {
    string L = "", R = "11235";
    // bruteforce solution
    cout << bruteforce(1, 11235, 5) << endl;
    cout << solve (R, R.length(), 5, 1) << endl;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to calculate Longest Common Subsequence
int LCS(const string &s1, const string &s2) {
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string rev = s;
    reverse(rev.begin(), rev.end());

    int lps = LCS(s, rev); // Longest Palindromic Subsequence

    int minInsertions = s.size() - lps;
    int minDeletions = s.size() - lps;

    cout << "Minimum Insertions to make palindrome: " << minInsertions << endl;
    cout << "Minimum Deletions to make palindrome: " << minDeletions << endl;

    return 0;
}

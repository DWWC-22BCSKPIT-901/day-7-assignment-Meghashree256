/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <vector>
#include <iostream>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustCount(n + 1, 0);
    
    for (const auto& t : trust) {
        trustCount[t[0]]--;  // Person t[0] trusts someone, so decrease their trust score
        trustCount[t[1]]++;  // Person t[1] is trusted by t[0], so increase their trust score
    }
    
    for (int i = 1; i <= n; i++) {
        if (trustCount[i] == n - 1) {
            return i;  // The town judge is the person with trustCount == n-1
        }
    }
    
    return -1;  // No town judge exists
}

int main() {
    vector<vector<int>> trust = {{1, 2}};
    int n = 2;
    cout << findJudge(n, trust) << endl;  // Output: 2
    return 0;
}



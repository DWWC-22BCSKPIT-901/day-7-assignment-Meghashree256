/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> emailToName;

    string find(string email) {
        if (parent[email] != email) {
            parent[email] = find(parent[email]);
        }
        return parent[email];
    }

    void unionSets(string email1, string email2) {
        string root1 = find(email1);
        string root2 = find(email2);
        if (root1 != root2) {
            parent[root2] = root1;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (parent.find(email) == parent.end()) {
                    parent[email] = email;
                }
                emailToName[email] = name;
                if (i > 1) {
                    unionSets(account[i], account[i - 1]);
                }
            }
        }

        unordered_map<string, unordered_set<string>> mergedAccounts;
        for (const auto& entry : parent) {
            string root = find(entry.first);
            mergedAccounts[root].insert(entry.first);
        }

        vector<vector<string>> result;
        for (const auto& entry : mergedAccounts) {
            vector<string> account;
            account.push_back(emailToName[entry.first]);
            for (const string& email : entry.second) {
                account.push_back(email);
            }
            sort(account.begin() + 1, account.end());
            result.push_back(account);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    vector<vector<string>> result = solution.accountsMerge(accounts);
    
    for (const auto& account : result) {
        for (const auto& email : account) {
            cout << email << " ";
        }
        cout << endl;
    }

    return 0;
}

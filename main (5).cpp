/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    void dfs(const string& src, const string& dest, double value, unordered_map<string, bool>& visited, double& result) {
        if (src == dest) {
            result = value;
            return;
        }
        visited[src] = true;
        for (const auto& neighbor : graph[src]) {
            if (!visited[neighbor.first]) {
                dfs(neighbor.first, dest, value * neighbor.second, visited, result);
                if (result != -1) return;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }

        vector<double> result;
        for (const auto& query : queries) {
            unordered_map<string, bool> visited;
            double res = -1;
            dfs(query[0], query[1], 1.0, visited, res);
            result.push_back(res);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> result = solution.calcEquation(equations, values, queries);
    
    for (double res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}


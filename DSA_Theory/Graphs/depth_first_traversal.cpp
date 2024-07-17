#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

template<typename Container>
void printContainer(Container& con) {
    for (auto i: con) {
        cout << i << " ";
    }
    cout << endl;
}
void printGraphList(vector<list<int>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i;
        for (auto j: adjList[i]) {
            cout << " <--> " << j;
        }
        cout << " <--> NULL" << endl;
    }
}

class Solution {
public:
    int time = 0;
    void dfsAtNode(int node, vector<list<int>>& adjList, vector<bool>& visitedArray, vector<int>& res, vector<int>& startTime, vector<int>& finishTime) {
        res.push_back(node);
        startTime[node] = time;
        time++;
        visitedArray[node] = true;
        for (auto adj: adjList[node]) {
            if (visitedArray[adj] == false) {
                dfsAtNode(adj, adjList, visitedArray, res, startTime, finishTime);
            }
        }
        finishTime[node] = time;
        time++;
    }

    vector<int> dfs(vector<vector<int>>& graph) {
        // create the adjacency list
        int V = graph.size();
        if (V == 0) {
            throw runtime_error("graph cannot be empty!");
        }
        vector<list<int>> adjList(V);
        for (int i = 0; i < graph.size(); i++) {
            list<int> adj(graph[i].begin(), graph[i].end());
            adjList[i] = adj;
        }
        // visit all the connected components
        time = 0;
        vector<bool> visitedArray(V, false);
        vector<int> res;
        vector<int> startTime(V, -1);
        vector<int> finishTime(V, -1);
        res.reserve(V);

        for (int i = 0; i < V; i++) {
            if (visitedArray[i] == false) {
                dfsAtNode(i, adjList, visitedArray, res, startTime, finishTime);
            }
        }
        printContainer(res);
        printContainer(startTime);
        printContainer(finishTime);
        return res;
    }
};

int main() {
    // vector<vector<int>> graph = {{1, 2, 3}, {0, 3, 4}, {0, 3}, {0, 1, 4}, {1, 3, 5}, {4}};
    vector<vector<int>> graph = {{1, 2, 4, 5}, {0, 2, 3}, {0, 1}, {1, 4, 5}, {0, 3}, {0, 3}};
    // vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}, {5}, {4}};

    Solution sol = Solution();
    vector<int> res = sol.dfs(graph);

    return 0;
}

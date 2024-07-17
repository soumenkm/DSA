#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void printGraphList(vector<list<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i;
        for (auto j: graph[i]) {
            cout << " <--> " << j;
        }
        cout << " <--> NULL" << endl;
    }
}
void printVector(vector<int> vec) {
    for (auto i: vec) {
        cout << i << " ";
    } 
    cout << endl;
}

vector<list<int>> createGraphList(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<list<int>> adjList;
    for (auto vertex: graph) {
        list<int> adj(vertex.begin(), vertex.end());
        adjList.push_back(adj);
    }
    return adjList;
}

class Solution {
public:
    vector<int> randomTraversal(vector<vector<int>>& graph) {
        // although it is not random, we are actually popping the last element
        // from the bag and pushing its adjacents so it is actually DFS
        if (graph.empty()) {
            throw runtime_error("graph cannot be empty!");
        }
        vector<list<int>> adjList = createGraphList(graph);

        int V = adjList.size();
        vector<bool> isVisited(V, false);
        vector<int> bag = {0};
        vector<int> results;;

        while (!(bag.empty())) {
            int current = bag.back();
            bag.pop_back();
            results.push_back(current);
            isVisited[current] = true;

            vector<int> adj;
            for (int node: adjList[current]) {
                if (isVisited[node] == false) {
                    adj.push_back(node);
                    isVisited[node] = true;
                }
            }
            bag.insert(bag.end(), adj.begin(), adj.end());
        }
        return results;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2, 3}, {0, 3, 4}, {0, 3}, {0, 1, 4}, {1, 3, 5}, {4}};
    Solution sol = Solution();
    vector<int> res = sol.randomTraversal(graph);
    printVector(res);

    return 0;
}
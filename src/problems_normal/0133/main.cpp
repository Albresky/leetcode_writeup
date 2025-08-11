#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   private:
    unordered_map<Node*, Node*> map;

   public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        if (map.find(node) != map.end()) return map[node];

        Node* new_node = new Node(node->val);
        map[node] = new_node;

        for (auto neighbor : node->neighbors) {
            new_node->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return new_node;
    }
};

class SolutionBFS {
   private:
    unordered_map<Node*, Node*> map;

   public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        map[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            auto old = q.front();
            q.pop();
            if (!old) continue;

            for (auto neighbor : old->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    map[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                map[old]->neighbors.emplace_back(map[neighbor]);
            }
        }
        return map[node];
    }
};
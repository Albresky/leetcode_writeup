#pragma once

#include <optional>
#include <queue>
#include <string>
#include <vector>

template <class NodeType, typename T = std::string, typename TV = int>
NodeType* vec2tree(const std::vector<T>& vec) {
    if (vec.empty() || vec[0] == "null") return nullptr;

    NodeType* root = new NodeType(static_cast<TV>(std::stoi(vec[0])));
    std::queue<NodeType*> q;
    q.push(root);

    size_t idx = 1;
    while (idx < vec.size()) {
        NodeType* curr = q.front();
        q.pop();

        // left son
        if (idx < vec.size() && vec[idx] != "null") {
            TV val = static_cast<TV>(std::stoi(vec[idx]));
            curr->left = new NodeType(val);
            q.push(curr->left);
        }
        ++idx;

        // right son
        if (idx < vec.size() && vec[idx] != "null") {
            TV val = static_cast<TV>(std::stoi(vec[idx]));
            curr->right = new NodeType(val);
            q.push(curr->right);
        }
        ++idx;
    }
    return root;
}

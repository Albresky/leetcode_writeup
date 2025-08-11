#include <iostream>
#include <vector>
using namespace std;

class Trie {
   private:
    vector<Trie*> children;
    bool isEnd;

   public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (auto ch : word) {
            ch -= 'a';
            if (!node->children[ch]) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (auto ch : word) {
            ch -= 'a';
            if (!node->children[ch]) return false;
            node = node->children[ch];
        }
        if (node->isEnd) return true;
        return false;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto ch : prefix) {
            ch -= 'a';
            if (!node->children[ch]) return false;
            node = node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
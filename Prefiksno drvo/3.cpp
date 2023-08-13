#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <stack>
#include <utility>
#include <numeric>
#include <cstring>
#include <functional>
#include <cstdlib>
using namespace std;

struct Node {
   string word;
   map<char, Node*> nodes;
};

Node* createNode() {
   Node* node = new Node();
   node->word = "";
   return node;
}

void addWord(Node* root, string word, int i) {
   if (i == word.length()) {
      root->word = word;
      return;
   }
   auto it = root->nodes.find(word[i]);
   if (it == root->nodes.end()) {
      root->nodes[word[i]] = createNode();
   }
   addWord(root->nodes[word[i]], word, i + 1);
}

void lexicographic(Node* root) {
   if (root->word != "") {
      cout << root->word << endl;
   }
   for (auto it : root->nodes) {
      lexicographic(it.second);
   }
}

void freeTree(Node* root) {
   if (root == nullptr) {
      return;
   }
   for(auto &p : root->nodes) {
      freeTree(p.second);
   }
   delete root;
}


int main(int argc, char const *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
    
   vector<string> words = {"cod", "coder", "coding", "codecs"};
   Node* root = createNode();
   for(string &s : words) {
     addWord(root, s, 0);
   }
   lexicographic(root);
   freeTree(root);
    
   return 0;
}

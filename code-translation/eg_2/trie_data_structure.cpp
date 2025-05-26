/*translate this python code to C++: 
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False
class Trie:
    def __init__(self):
        self.root = TrieNode()  
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True  
    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word
    def starts_with(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True
    def delete(self, word):
        def _delete(node, word, depth):
            if not node:
                return False    
            if depth == len(word):
                if node.is_end_of_word:
                    node.is_end_of_word = False
                    return len(node.children) == 0
                return False
            char = word[depth]
            if char in node.children:
                should_delete_child = _delete(node.children[char], word, depth + 1) 
                if should_delete_child:
                    del node.children[char]
                    return len(node.children) == 0 and not node.is_end_of_word
            return False
        _delete(self.root, word, 0)
    def __str__(self):
        def _collect_words(node, prefix, words):
            if node.is_end_of_word:
                words.append(prefix)
            for char, child in node.children.items():
                _collect_words(child, prefix + char, words)
        words = []
        _collect_words(self.root, "", words)
        return ", ".join(words)
# Example usage
if __name__ == "__main__":
    trie = Trie()
    trie.insert("hello")
    trie.insert("world")
    trie.insert("hi")
    print("Trie after inserting words:", trie)
    print("Search for 'hello':", trie.search("hello"))
    print("Search for 'hell':", trie.search("hell"))
    print("Starts with 'he':", trie.starts_with("he"))
    trie.delete("hello")
    print("Trie after deleting 'hello':", trie)
    print("Search for 'hello' after deletion:", trie.search("hello"))
    print("Search for 'hi':", trie.search("hi"))
    print("Starts with 'h':", trie.starts_with("h"))
    print("Starts with 'wo':", trie.starts_with("wo"))
    print("Trie contents:", trie)
    trie.insert("hell")
    print("Trie after inserting 'hell':", trie)
    trie.delete("hi")
    print("Trie after deleting 'hi':", trie)
    print("Search for 'hi' after deletion:", trie.search("hi"))
    print("Trie contents after all operations:", trie)
    print("Starts with 'h':", trie.starts_with("h"))

    Use bits/stdc++.h here
    */
#include <bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {}
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->is_end_of_word = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->is_end_of_word;
    }

    bool starts_with(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

    void delete_word(const string& word) {
        _delete(root, word, 0);
    }

    string to_string() const {
        vector<string> words;
        _collect_words(root, "", words);
        return join(words, ", ");
    }
private:
    bool _delete(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (node->is_end_of_word) {
                node->is_end_of_word = false;
                return node->children.empty();
            }
            return false;
        }

        char ch = word[depth];
        if (node->children.find(ch) != node->children.end()) {
            bool should_delete_child = _delete(node->children[ch], word, depth + 1);
            if (should_delete_child) {
                delete node->children[ch];
                node->children.erase(ch);
                return node->children.empty() && !node->is_end_of_word;
            }
        }
        return false;
    }

    void _collect_words(TrieNode* node, const string& prefix, vector<string>& words) const {
        if (node->is_end_of_word) {
            words.push_back(prefix);
        }
        for (const auto& pair : node->children) {
            _collect_words(pair.second, prefix + pair.first, words);
        }
    }

    string join(const vector<string>& words, const string& delimiter) const {
        ostringstream oss;
        for (size_t i = 0; i < words.size(); ++i) {
            oss << words[i];
            if (i < words.size() - 1) {
                oss << delimiter;
            }
        }
        return oss.str();
    }
};
// Example usage
int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");

    cout << "Trie after inserting words: " << trie.to_string() << endl;
    cout << "Search for 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search for 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'he': " << (trie.starts_with("he") ? "True" : "False") << endl;

    trie.delete_word("hello");
    cout << "Trie after deleting 'hello': " << trie.to_string() << endl;
    cout << "Search for 'hello' after deletion: " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search for 'hi': " << (trie.search("hi") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'h': " << (trie.starts_with("h") ? "True" : "False") << endl;
    cout << "Starts with 'wo': " << (trie.starts_with("wo") ? "True" : "False") << endl;

    cout << "Trie contents: " << trie.to_string() << endl;

    trie.insert("hell");
    cout << "Trie after inserting 'hell': " << trie.to_string() << endl;

    trie.delete_word("hi");
    cout << "Trie after deleting 'hi': " << trie.to_string() << endl;
    cout << "Search for 'hi' after deletion: " << (trie.search("hi") ? "Found" : "Not Found") << endl;

    cout << "Trie contents after all operations: " << trie.to_string() << endl;
    cout << "Starts with 'h': " << (trie.starts_with("h") ? "True" : "False") << endl;

    return 0;
}
// End of the code

#write code to implement a trie data structure
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
    
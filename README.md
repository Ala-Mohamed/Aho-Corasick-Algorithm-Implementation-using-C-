# Aho-Corasick-Algorithm-Implementation-using-C++

This repository contains an implementation of the Aho-Corasick string-searching algorithm in C++. Developed by Alfred V. Aho and Margaret J. Corasick in 1975, this algorithm efficiently searches for multiple patterns simultaneously within a given text. It is widely used in various applications requiring pattern matching, such as motif finding, plagiarism detection, spam filtering, and auto-complete features.

**Overview**
The Aho-Corasick algorithm constructs a finite automaton (a trie with failure links) that allows searching for all patterns in linear time O(n + m + z):
-n: Total length of all patterns
-m: Length of the input text
-z: Total number of pattern occurrences
This implementation is particularly tailored for solving DNA motif-matching problems, making it highly suitable for bioinformatics applications.

**Features**
1-Trie Construction: Insert multiple patterns or motifs efficiently.
2-Prefix Existence Check: Verify if a prefix already exists in the trie.
3-Pattern Search: Check if a motif exists in the trie.
4-Failure Function: Build failure links for efficient pattern matching.
5-Pattern Occurrence Search: Find all occurrences of patterns and record positions.

**Usage**
The main code demonstrates how to use the Trie class:
-Insert patterns such as "ACC", "ATC", "CAT", and "GCG".
-Build the failure links.
-Use search functions to verify the existence of patterns and locate their positions.

**Example**
#include "Trie.h"

int main() {
    Trie trie;

    // Insert patterns
    trie.insert("ACC");
    trie.insert("ATC");
    trie.insert("CAT");
    trie.insert("GCG");

    // Build failure links
    trie.buildFailureLinks();

    // Search for patterns in a text
    std::string text = "GATCCG";
    std::vector<int> occurrences = trie.search(text);

    if (trie.patternExists("ACC")) {
        std::cout << "Pattern 'ACC' found at position(s): " << occurrences.size() << std::endl;
    }

    return 0;
}

**Libraries**
Ensure you include the following standard C++ headers when compiling:
<vector>
<string>
<queue>
<iostream>

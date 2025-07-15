# Aho-Corasick-Algorithm-Implementation-using-C++

Alfred V. Aho and Margaret J. Corasick created the Aho-Corasick algorithm, a string-searching method, in the field of computer science in 1975. This type of algorithm looks for strings inside an input text that belong to a finite set of patterns. It is one of the most efficient algorithms in pattern matching as it can take multiple patterns and search for them in a given sequence in a linear time complexity O(n+m+z) where n is the total length of all patterns, m is the length of the text in which the patterns will be searched, z is the number of occurrences of each pattern.
Usage
It is used in pattern-matching problems such as motif finding, plagiarism checking, and auto-complete search. Our code is implemented in C++ to solve DNA motif-matching problems and you need to include the following libraries to run the code:
<iostream>
<queue> 
<vector> 
Features  : 
This code was implemented based on tries data structure that gives efficient time and space complexity
. For tries implementation, it has the following features: 
Insert: To insert your patterns or motifs.  
PrefixExsist: to check if the prefix already exists. 
seqExsist: to check if the motif is found on the trie or not.
 To search for a sequence: 
Failure function: built the failure links of the tries. 
Search: provide a vector for the occurrence of a specific sequence on the trie.

The main code shows how to use the functions of the code starting with using trie class to insert these sequences  ("ACC", "ATC", "CAT", and "GCG") then building the failure function and using the different functions mentioned above to see if the sequence already in and its position. 


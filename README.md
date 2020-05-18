# Implementation-of-Binary-Search-Tree
Number of functions are implemented in binary search tree implementation.

Implement the following member functions for your binary search tree:

a. A default Constructor which sets the root to nullptr.

b. A copy constructor which uses recursion to deep copy another Binary Search Tree object.

c. A function “inorderPrint” which prints the keys using in-order traversal.
void inorderPrint () const

d. A recursive “insert” function which is passed as parameter int data. It should insert the data while
considering the insertion rules. If the data already exists in the BST, simply return false and true
otherwise.
bool insert(int d)

e. A function “length” which uses recursion to return the count of total nodes in BST.
int length() const

f. A function “search” which is passed as parameter a key. The function then uses recursion to
return pointer to the corresponding node. If the key does not exist, the function returns nullptr.
Node* search(int key)

g. A “deleteKey” function which is passed as parameter a key. The function then uses recursion to
delete the node that contains that key.
void deleteKey(int key)

h. A recursive and iterative (both) functions “LeafNodes” which counts the total Number of leaf
nodes in the BST.
int LeafNodes()

i. A function “Print” which prints the data in sorted order (increasing). Iterative only.
void Print ()

j. A function BST get_BST(int n), which returns a Sub-BST that has n as root node. Deep copy data
in the new sub_BST.
BST get_BST(int n)

k. A function "Update-Key", It will take two keys as input key1 and key2 and finds the node with key1, then changes it
to key2. This may disturb the BST property (of having smaller things to the left and bigger
to the right); this function should make appropriate changes in tree so that it becomes BST
again.
bool UpdateKey(int key1, int key2)

l. A function "FindHeight", It will find the height of tree recursively.

m. A function "PrintSpiral", All the nodes present at level 1 should be printed left to right and all the nodes present at level 2 should be printed right to left. Then all the nodes in the level 3 should be printed left to right and all the nodes in level 4 right to left and so on.

n. Destructor

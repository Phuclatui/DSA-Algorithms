### FINDING COMPONENTS-C++

### PROBLEM:

Given a graph, find the connected component that contains a given source vertex, and print all vertices belonging to that component

### IDEA:

Use Depth First Search (DFS) starting from the source vertex.



DFS explores vertices by going as deep as possible along each branch before backtracking.

All vertices visited during the DFS traversal belong to the same connected component as the source vertex.



### Features:

* Find the components from a source vertex
* Print all the vertices in that component
* Efficient for sparse graphs

### DATA STRUCTURE

* Algorithm: **DFS**
* Graph representation: Adjacency list

### COMPLEXITY ANALYSIS

**Memory**: O(V + E)

**Check Edge**:

* average O(deg(u))
* worst case O(V)

**Add Edge**: O(1)

**Remove Edge**: O(deg(u))

**Best for**: sparse graph




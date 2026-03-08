### BREADTH FIRST SREACH-C++

### PROBLEM:

Given an undirected unweighted graph G(V, E) and a start vertex s,

find the shortest path from s to every other vertex in the graph.



### IDEA:

BFS explores the graph level by level.



Starting from the source vertex:

\- First visit all vertices at distance 1

\- Then all vertices at distance 2

\- Then distance 3, and so on



Because all edges have equal weight, the first time we visit a vertex

is guaranteed to be the shortest path from the source.



## Features:

* Find the shortest path in an undirected weight graph
* Print the shortest path

### DATA STRUCTURE

* Algorithm: **BFS**
* Graph representation: Adjacency list

### COMPLEXITY ANALYSIS

**Memory**: O(V + E)

**Check Edge**:

* average O(deg(u))
* worst case O(V)

**Add Edge**: O(1)

**Remove Edge**: O(deg(u))

**Best for**: sparse graph



Author

Phạm Hoàng Phúc


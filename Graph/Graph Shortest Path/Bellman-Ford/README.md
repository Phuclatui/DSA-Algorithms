### FINDING SHORTEST PATH-C++

### Features:

* Find the shortest path from a single source vertex
* Find Negative cycle
* Get the shortest path distance

### DATA STRUCTURE

* Algorithm: **Bellman-Ford**
* Graph representation: Edge list

### COMPLEXITY ANALYSIS

O((n-1)m) ~ O(nm)

n - 1: the number of iterations

m: the number of edges in one iteration



###### **Description:**

***Negative Cycle***

If a negative cycle exists and is reachable from the start vertex:



* All vertices that belong to the cycle do not have a finite shortest path.



* Any vertex reachable from that cycle also does not have a finite shortest path.



* Vertices that are reachable from the start vertex without passing through a negative cycle still have a valid shortest path.




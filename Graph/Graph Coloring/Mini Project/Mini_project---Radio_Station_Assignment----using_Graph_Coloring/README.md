### Radio Station Assignment-C++

### Features:

The Radio Station Assignment Problem is modeled as a graph coloring problem.

Each radio station is represented as a vertex in the graph, and an edge exists between two vertices if the corresponding stations interfere with each other.

The goal of the problem is to assign frequencies to radio stations such that:

* No two interfering stations share the same frequency.
* The total number of frequencies used is minimized.



This problem is solved by applying a graph coloring algorithm, where each color represents a unique radio frequency.



Một công ty có 8 đài phát thanh A, B, C, D, E, F, G, H có khoảng

cách (km) được cho trong ma trận sau:

|   | A   | B   | C   | D   | E   | F   | G   | H   |

| - | --- | --- | --- | --- | --- | --- | --- | --- |

| A | 0   | 100 | 50  | 30  | 200 | 150 | 40  | 120 |

| B | 0   | 0   | 30  | 80  | 120 | 50  | 200 | 150 |

| C | 0   | 0   | 0   | 120 | 100 | 30  | 80  | 50  |

| D | 0   | 0   | 0   | 0   | 50  | 120 | 150 | 30  |

| E | 0   | 0   | 0   | 0   | 0   | 200 | 120 | 120 |

| F | 0   | 0   | 0   | 0   | 0   | 0   | 180 | 150 |

| G | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 50  |

| H | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |

Do yêu cầu kỹ thuật nên các đài có khoảng cách ≥ 100km không

được dùng chung một trạm phát song. Hãy lắp đặt các trạm phát

sóng sao cho số trạm cần lắp là nhỏ nhất. 


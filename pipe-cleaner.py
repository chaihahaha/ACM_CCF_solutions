from collections import defaultdict


class Graph(object):
    def __init__(self, directed):
        self._graph = defaultdict(set)
        self._directed = directed
    def add(self, node1, node2):
        self._graph[node1].add(node2)
        if not self._directed:
            self._graph[node2].add(node1)

T, S, E = [int(i) for i in input().split()]
for i in range(T):
    g = Graph(True)
    n, m = [int(j) for j in input().split()]
    for k in range(m):
        node1, node2, ntype = [x for x in input().split()]
        # print('node1',node1,'node2',node2,'ntype',ntype)
        g.add(node1,(node2,ntype))
    
              

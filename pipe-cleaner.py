from collections import defaultdict

class Graph(object):
    def __init__(self):
        self._graph = defaultdict(set)
    def add(self, node1, node2):
        self._graph[node1].add(node2)

def search(g, target_edge, available_edge, burger, node, bcost, route):
    # g: graph(directed with pipes)   target_edge: pipes to be cleaned
    # available_edge: pipes can pass through   burger: remaining baozi
    # node: current position   bcost: baozi consume of passing one pipe   route: history route
    if node == '1' and len(target_edge) == 0:
        print(route, "returning")
        return int(burger)
    ans_list = []
    for edge_tup in g._graph[node]:
        if edge_tup in available_edge:
            if edge_tup[2] == 'A':
                ans_list.append(search(g, target_edge - {edge_tup}, available_edge,
                                       burger+bcost, edge_tup[1], bcost, route + edge_tup[1]))
            elif edge_tup[2] == 'B':
                ans_list.append(search(g, target_edge - {edge_tup}, available_edge - {edge_tup},
                                       burger+bcost, edge_tup[1],bcost, route + edge_tup[1]))
            elif edge_tup[2] == 'C':
                ans_list.append(search(g, target_edge, available_edge,
                                       burger+bcost, edge_tup[1],bcost, route+edge_tup[1]))
            elif edge_tup[2] == 'D':
                ans_list.append(search(g, target_edge, available_edge - {edge_tup},
                                       burger+bcost, edge_tup[1],bcost,route+edge_tup[1]))
    ans_list = [i for i in ans_list if i != -1]
    if ans_list != []:
        return min(ans_list)
    else:
        print(route, "search fail")
        return -1
            

T, S, E = [int(i) for i in input().split()]
for i in range(T):
    g = Graph()
    target_edge = set()
    available_edge = set()
    n, m = [int(j) for j in input().split()]
    for k in range(m):
        node1, node2, ntype = [x for x in input().split()]
        if ntype == 'A' or ntype == 'B':
            target_edge.add((node1, node2, ntype))
        available_edge.add((node1, node2, ntype))
        g.add(node1,(node1,node2,ntype))
    # print(g._graph)
    print(search(g, target_edge, available_edge, 0, '1', E,'1'))

# Experiment No. 7: You have a business with several offices; you want to lease phone lines to connect 
# them up with each other; and the phone company charges different amounts of money 
# to connect different pairs of cities. You want a set of lines that connects all 
# your offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.

import heapq

def prim_mst(graph):
    start_node = list(graph.keys())[0]
    visited = {start_node}
    edges = []
    min_spanning_tree = []
    total_cost = 0

    for neighbor, cost in graph[start_node]:
        heapq.heappush(edges, (cost, start_node, neighbor))

    while edges:
        cost, u, v = heapq.heappop(edges)
        if v not in visited:
            visited.add(v)
            min_spanning_tree.append((u, v, cost))
            total_cost += cost

            for neighbor, neighbor_cost in graph[v]:
                if neighbor not in visited:
                    heapq.heappush(edges, (neighbor_cost, v, neighbor))

    return min_spanning_tree, total_cost

# Example Usage
graph = {
    "Office A": [("Office B", 10), ("Office C", 15)],
    "Office B": [("Office A", 10), ("Office C", 20), ("Office D", 5)],
    "Office C": [("Office A", 15), ("Office B", 20), ("Office D", 12)],
    "Office D": [("Office B", 5), ("Office C", 12)],
}

mst, cost = prim_mst(graph)
print("Minimum Spanning Tree:", mst)
print("Total Cost:", cost)

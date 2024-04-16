import sys

def dijkstra(graph, s, t):
    n = len(graph)
    visited = [False] * n
    dist = [sys.maxsize] * n
    dist[s] = 0

    for _ in range(n):
        u = min_distance(dist, visited)
        visited[u] = True

        for v in range(n):
            if not visited[v] and dist[v] > dist[u] + graph[u][v]:
                dist[v] = dist[u] + graph[u][v]

    return dist[t]

def min_distance(dist, visited):
    min_dist = sys.maxsize
    min_index = -1

    for v in range(len(dist)):
        if dist[v] < min_dist and not visited[v]:
            min_dist = dist[v]
            min_index = v

    return min_index

# Matriz de pesos
matriz = [
    [0, 5, 1, 2, float('inf'), float('inf'), float('inf'), float('inf'), float('inf')],
    [5, 0, float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 3],
    [1, float('inf'), 0, float('inf'), 1, float('inf'), float('inf'), float('inf'), float('inf')],
    [2, float('inf'), float('inf'), 0, float('inf'), 1, float('inf'), float('inf'), float('inf')],
    [float('inf'), float('inf'), 1, float('inf'), 0, float('inf'), float('inf'), 1, float('inf')],
    [float('inf'), float('inf'), float('inf'), 1, float('inf'), 0, 1, float('inf'), float('inf')],
    [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 1, 0, 3, 2],
    [float('inf'), 1, float('inf'), float('inf'), float('inf'), 1, float('inf'), 3, 0],
    [float('inf'), 3, float('inf'), float('inf'), float('inf'), float('inf'), 2, float('inf'), 0]
]

source = 0
target = 4
shortest_distance = dijkstra(matriz, source, target)
print(f"A menor distância entre {source} e {target} é: {shortest_distance}")

/*
 * graph.h
 *
 *  Created on: Feb 29, 2020
 *      Author: glcesar
 */

/* A data structure to store adjacency list nodes of the graph */
typedef struct node_s {
        int dest, weight;
        struct node_s* next;
} node_t;

typedef struct {
        int nv;
        node_t **head;
} graph_t;

typedef struct {
        int src, dest, weight;
} edge_t;

graph_t *create_graph(int n);
node_t *create_node(int dest, int weight);
void add_edge(graph_t *graph, edge_t edge);
void destroy_node(node_t* node);
void destroy_list(node_t *node);
void destroy_graph(graph_t *graph);
void print_graph(graph_t *graph);

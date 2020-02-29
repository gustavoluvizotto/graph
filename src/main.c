/*
 ============================================================================
 Name        : main.c
 Author      : glcesar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "../inc/graph.h"

int main(void) {
        int n = 7;

        graph_t *graph = create_graph(n);

        edge_t edge = { 0, 1, 6 };
        add_edge(graph, edge);

        edge.src = 1;
        edge.dest = 2;
        edge.weight = 7;
        add_edge(graph, edge);

        edge.src = 2;
        edge.dest = 0;
        edge.weight = 5;
        add_edge(graph, edge);

        edge.src = 2;
        edge.dest = 1;
        edge.weight = 4;
        add_edge(graph, edge);

        edge.src = 3;
        edge.dest = 2;
        edge.weight = 10;
        add_edge(graph, edge);

        edge.src = 4;
        edge.dest = 5;
        edge.weight = 1;
        add_edge(graph, edge);

        edge.src = 5;
        edge.dest = 4;
        edge.weight = 3;
        add_edge(graph, edge);

        print_graph(graph);

        destroy_graph(graph);

        return 0;
}

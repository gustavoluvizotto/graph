/*
 * graph.c
 *
 *  Created on: Feb 29, 2020
 *      Author: glcesar
 */

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

/*
 * Allocate memory to the graph and allocate memory to adjacency list
 */
graph_t *create_graph(int n) {
        int i;

        graph_t *graph = (graph_t*) malloc(sizeof(graph_t));
        graph->nv = n;

        graph->head = (node_t**) malloc(
                        (long unsigned int) n * sizeof(node_t*));
        for (i = 0; i < n; i++)
                graph->head[i] = NULL;

        return graph;
}

/*
 * Allocate memory and give destination value to a graph node
 */
node_t *create_node(int dest, int weight) {
        node_t *new_node = (node_t*) malloc(sizeof(node_t));

        new_node->dest = dest;
        new_node->weight = weight;
        new_node->next = NULL;

        return new_node;
}

/*
 * Create connection between src and dest nodes
 */
void add_edge(graph_t *graph, edge_t edge) {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        /* allocate new node of Adjacency List from src to dest */
        node_t *new_node = create_node(dest, weight);

        /* point new node to current head */
        new_node->next = graph->head[src];

        /* point head pointer to new node */
        graph->head[src] = new_node;

        /* if graph has to be bidirectional */
        /*
         new_node = create_node(src, weight);
         new_node->next = graph->head[dest];
         graph->head[dest] = new_node;
         */
}

void destroy_node(node_t* node) {
        if (node != NULL) {
                node->next = NULL;
                free(node);
                node = NULL;
        }
        return;
}

void destroy_list(node_t *node) {
        node_t *current = NULL;

        if (node == NULL) {
                printf("Nothing to destroy...\n");
                return;
        }

        current = node;
        while (current != NULL) {
                node = current->next;
                destroy_node(current);
                current = node;
        }
}

void destroy_graph(graph_t *graph) {
        int i;

        for (i = 0; i < graph->nv; i++) {
                if (graph->head[i] != NULL) {
                        destroy_list(graph->head[i]);
                }
        }
        free(graph->head);
        graph->head = NULL;
        free(graph);
        graph = NULL;
        return;
}

/*
 * Print adjacency list representation of the graph
 */
void print_graph(graph_t *graph) {
        int i;

        for (i = 0; i < graph->nv; i++) {
                node_t *ptr = graph->head[i];
                while (ptr != NULL) {
                        printf("%d -> %d (%d)\t", i, ptr->dest, ptr->weight);
                        ptr = ptr->next;
                }
                printf("\n");
        }
}

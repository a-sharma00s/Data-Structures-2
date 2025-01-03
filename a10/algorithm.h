/*
-------------------------------------------------------
File:     algorithm.h
About:    Assignment 10
Author:   Ashish Sharma
Version:  2024-02-24
-------------------------------------------------------
*/

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "edgelist.h"
#include "graph.h"

EDGELIST *mst_prim(GRAPH *g, int start);
EDGELIST *spt_dijkstra(GRAPH *g, int start);
EDGELIST *sp_dijkstra(GRAPH *g, int start, int end);

#endif
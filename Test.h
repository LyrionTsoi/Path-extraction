//
// Created by Tsoi on 2024/3/6.
//

#ifndef INC_6_10_15VIRAL_TEST_H
#define INC_6_10_15VIRAL_TEST_H


#include <iostream>
#include <map>
#include "Graph.h"
#include "Node.h"

namespace Test{
    void read_graph(Graph graph);
    void related_information(Graph graph);
    void coverage(Graph graph);
    void degree(Graph graph);
    void graph_nodeStatus(const Graph & graph);
    void printQueue(std::queue<int> q);
    void printVector(std::vector<int> v);
}



#endif //INC_6_10_15VIRAL_TEST_H

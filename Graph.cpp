//
// Created by Tsoi on 2024/3/6.
//
#include "Graph.h"

void Graph::calculateDegrees() {
    in_degree.resize(nodes.size(), 0);
    out_degree.resize(nodes.size(), 0);

    for (const auto& [nodeId, node] : nodes) {
        out_degree[nodeId] = node.children.size();
        for (int childId : node.children) {
            if (childId < in_degree.size()) {
                in_degree[childId]++;
            }
        }
    }
}
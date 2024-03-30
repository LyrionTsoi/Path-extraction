//
// Created by Tsoi on 2024/3/6.
//

#ifndef INC_6_10_15VIRAL_INIT_H
#define INC_6_10_15VIRAL_INIT_H


#include "Graph.h"
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include "Node.h"

namespace Init{
    std::ifstream open_file(std::string filename);
    std::vector<std::string> split(const std::string &str);
    void read_graph(Graph &g, std::string filename);
    void read_related_information(Graph &g,std::string filename);
    void read_coverage(Graph &g, std::string filename);
    void node_Status(Graph &g);
//    void Statistical_degree(Graph &g);
}


#endif //INC_6_10_15VIRAL_INIT_H

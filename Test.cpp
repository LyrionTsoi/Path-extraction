//
// Created by Tsoi on 2024/3/6.
//

#include <iostream>
#include <map>
#include <queue>
#include "Graph.h"
#include "Node.h"

namespace Test{
    void read_graph(Graph graph){
        // 验证图是否读入正确(test point)
        for(int id = 0; id < graph.nodes.size(); id ++){
            std::cout << id << " " << graph.nodes[id].don << ' ';
            for(int i = 0;i < graph.nodes[id].children.size(); i ++){
                std::cout << graph.nodes[id].children[i] << ' ';
            }
            std::cout << std::endl;
        }
    }

    void related_information(Graph graph){

        for(int i = 0; i < graph.nodes.size(); i ++){
            std::cout << '<' << i << std::endl;
            for(auto j : graph.nodes[i].left_related){
                int value = j.first;
                auto nd = j.second;
                for(auto k : nd){
                    std::cout << k << ' ';
                }
                std::cout<< value << ' ' << std::endl;
            }
            std::cout << "@" << std::endl;
            for(auto j : graph.nodes[i].right_related){
                int value = j.first;
                auto nd = j.second;
                for(auto k : nd){
                    std::cout << k << ' ';
                }
                std::cout<< value << ' ' << std::endl;
            }
        }
    }

    void coverage(Graph graph){
        for(int i = 0; i < graph.nodes.size();i ++){
            std::cout << i ;
            std::cout << " : " << graph.nodes[i].coverage << std::endl;
        }
    }

    void degree(Graph g){
        for(int i = 0; i < g.nodes.size(); i ++){
            std::cout << "id: " << i <<
            " in_degree: " << g.in_degree[i] <<
            " out_degree: " << g.out_degree[i] << std::endl;
        }
    }

    void printQueue(std::queue<int> q) {
        while (!q.empty()) {
            std::cout << q.front() << " ";
            q.pop();
        }
        std::cout << std::endl;
    }

    void graph_nodeStatus(const Graph & g){
        for(int i = 0; i < g.nodeStatus.size(); i ++){
            std::cout << i << ' ' << g.nodeStatus[i] << std::endl;
        }
    }

    void printVector(std::vector<int> v){
        for(auto i : v)
            std::cout << i << ' ';
        puts("");
    }

}


//
// Created by Tsoi on 2024/3/6.
//

#ifndef INC_6_10_15VIRAL_GRAPH_H
#define INC_6_10_15VIRAL_GRAPH_H


#include "Node.h"
#include <map>
#include <cstring>

class  Graph{
public:
        std::map<int,Node> nodes; // 用key值来索引node结点，后面会方便使用的key值来索引结点的丰度以及配对信息
        std::vector<int> in_degree; // 入度
        std::vector<int> out_degree; // 出度
        std::vector<bool> nodeStatus; // 记录每一个节点是否为左端信息缺失的节点 // nodeStatus[i] = true 表示节点i左端点配对信息为空

        Node& operator[](int nodeid) {
            return nodes.at(nodeid);
        }

        void calculateDegrees();

};


#endif //INC_6_10_15VIRAL_GRAPH_H

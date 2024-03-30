//
// Created by Tsoi on 2024/3/6.
//

#ifndef INC_6_10_15VIRAL_NODE_H
#define INC_6_10_15VIRAL_NODE_H

#include <string>
#include <vector>


class Node {
public:
    std::string don;
    std::vector<int> children; // 边的信息隐藏在node节点当中
    int coverage; // 记录丰度
    // 注意这里的pair.first表示是配对信息权值， vector表示的是配对信息的节点
    std::vector<std::pair<int,std::vector<int>>> left_related;
    std::vector<std::pair<int,std::vector<int>>> right_related;
    int cntTraverse;
};


#endif //INC_6_10_15VIRAL_NODE_H

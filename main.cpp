#include <queue>
#include "Node.h"
#include "Graph.h"
#include "Test.h"
#include "Init.h"
#include "Find.h"
#include <fstream>
#include <set>


int main() {
    for(int test_num = 1; test_num > 0; test_num --){
//        std::map<int, Node> initialNodes;
        Graph graph;
        std::vector<std::vector<int>> ALL_PATH;// 保存路径
        std::vector<int> Path; // 沿途路径
        std::queue<int> wait_Path; // 潜在路径

        // input x-graph.fasta
        std::string filename = "6-graph.fasta";
        Init::read_graph(graph,filename);
///        !!!!!!!!!测试用
//        Test::read_graph(graph);

        // input x-related-node.txt
        filename = "6-related-node.txt";
        Init::read_related_information(graph,filename);
///       !!!!!!!!!测试用
//        Test::related_information(graph);

        filename = "6-coverage.txt";
        Init::read_coverage(graph,filename);
//        Test::coverage(graph);

        // 计算出入度，但是我们要判断的是分支点而不是多入度和多出度点
//        graph.calculateDegrees();
//        Test::degree(graph);

        Init::node_Status(graph);
//        Test::graph_nodeStatus(graph);

        for(auto pair : graph.nodes){
            auto node = pair.second;
            node.cntTraverse = 0;
        }

        std::set<int> visited;
        Find::explore_path(ALL_PATH,wait_Path,graph,Path,0,visited);

//        Find::explore_path(ALL_PATH,wait_Path,graph,Path,0);


        std::cout << ALL_PATH.size() << std::endl;
        // 打开一个文件流用于写入
        std::ofstream outFile("output.csv");

        // 检查文件是否成功打开
        if (!outFile.is_open()) {
            std::cerr << "无法打开文件" << std::endl;
            return -1;
        }

        // 遍历二维向量并写入文件
        for (const auto &row : ALL_PATH) {
            for (size_t i = 0; i < row.size(); ++i) {
                outFile << row[i];
                if (i < row.size() - 1) outFile << ","; // 不是最后一个元素，添加逗号
            }
            outFile << "\n"; // 每行结束后换行
        }

        // 关闭文件
        outFile.close();
    }


    return 0;
}

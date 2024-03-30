//
// Created by Tsoi on 2024/3/6.
//

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
#include "Node.h"
#include "Graph.h"


namespace Init{
    // 注意这里返回的是一个string值所以如要要得到一个整数类型的时候还需要进行多一步转换
// 仅做一步分割作用
    std::vector<std::string> split(const std::string &str){// 读入一个string类型的数值
        std::istringstream iss(str);
        std::vector<std::string> tokens;
        std::string token;
        while(iss >> token){
            tokens.push_back(token);
        }
        return tokens;
    }

    std::ifstream open_file(std::string filename){
        std::ifstream file(filename);

        if(!file.is_open()){
            std::cerr << "Uable to open file:" << filename << std::endl;
            std::exit(EXIT_FAILURE);
        }
        return file;
    }

    void read_graph(Graph &g, std::string filename){
        // 打开fasta文件
        std::ifstream file = open_file(filename);

        std::string line; // 按行来读入
        //多行读入
        int p = 1;
        while(std::getline(file,line) && !line.empty()){
//        test point
//        std::cout << "line:" << p << std::endl;
//        p ++;
            std::vector<std::string> tokens = split(line);

            // 类型其实是固定的，比如第一个int 第二个string， 其他都是int类型
            int id;
            try{
                id = std::stoi(tokens[0]);
            }catch (const std::invalid_argument & e){
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            }catch (const std::out_of_range & e){
                std::cerr << "Out of range: " << e.what() << std::endl;
            }

            std::string don = tokens[1];
            g.nodes[id].don = don; // 给'id'号节点赋予其data信息 "don = data of node"

            int child;
            for(int i = 2; i < tokens.size(); i ++ ){
                child = std::stoi(tokens[i]);
                g.nodes[id].children.push_back(child); // 将'id'号结点的孩子结点加入到数组当中
            }
        }
    }

    void read_related_information(Graph &g,std::string filename){
        std::ifstream file = open_file(filename);

        std::string line;
        int id;
        bool flag = false;
        while(std::getline(file,line) && !line.empty()){
            if(line[0] == '@')
            {
                flag = true;
                continue;
            }

            if(line[0] == '>'){
                flag = false;
                // 取出第一个字符
                ///注意这里的substr表示的是line[0]位置
//                std::cout << line << std::endl;
                line = line.substr(1); // line[0] = '>'
//                std::cout << line << std::endl;

                // 数值转换的异常捕捉
                try{
                    id = std::stoi(line);
                }catch (const std::invalid_argument& e){
                    // 如果转换失败（例如，字符串不是有效的整数）
                    std::cerr << "Invalid argument: " << e.what() << std::endl;
                } catch (const std::out_of_range& e) {
                    // 如果转换的数值超出'int'类型的范围
                    std::cerr << "Out of range: " << e.what() << std::endl;
                }
                continue;
            }

            if(flag == 0){
                std::vector<std::string> iss = split(line); // 将line按空格分隔
                int value;std::vector<int> nd;
                for(auto i : iss){
                    if(i[0] == '('){
                        i = i.substr(1);
                        i = i.substr(0,i.size()-1);
//                        std::cout << i << std::endl;
                        try{
                            value = std::stoi(i);
                        }catch (const std::invalid_argument& e){
                            // 如果转换失败（例如，字符串不是有效的整数）
                            std::cerr << "Invalid argument: " << e.what() << std::endl;
                        } catch (const std::out_of_range& e) {
                            // 如果转换的数值超出'int'类型的范围
                            std::cerr << "Out of range: " << e.what() << std::endl;
                        }
                    }else{
                        nd.push_back(std::stoi(i));
                    }
                }

                auto t = std::make_pair(value, nd);
                g.nodes[id].left_related.push_back(t);

                continue;
            }

            if(flag == 1){
                std::vector<std::string> iss = split(line); // 将line按空格分隔
                int value;std::vector<int> nd;
                for(auto i : iss){
                    if(i[0] == '('){
                        i = i.substr(1);
                        i = i.substr(0,i.size()-1);
//                        std::cout << i << std::endl;
                        try{
                            value = std::stoi(i);
                        }catch (const std::invalid_argument& e){
                            // 如果转换失败（例如，字符串不是有效的整数）
                            std::cerr << "Invalid argument: " << e.what() << std::endl;
                        } catch (const std::out_of_range& e) {
                            // 如果转换的数值超出'int'类型的范围
                            std::cerr << "Out of range: " << e.what() << std::endl;
                        }
                    }else{
                        nd.push_back(std::stoi(i));
                    }
                }

                auto t = std::make_pair(value, nd);
                g.nodes[id].right_related.push_back(t);
            }
        }
    }

    void read_coverage(Graph &g, std::string filename){
        std::ifstream file = open_file(filename);

        std::string line;
        while(getline(file,line) && !line.empty()){
            auto t = split(line);
            int id = std::stoi(t[0]);
            int cov = std::stoi(t[2]);
            g.nodes[id].coverage = cov;
        }
    }

    void node_Status(Graph &g){
        g.nodeStatus.assign(g.nodes.size() + 10, false);
        for(auto i: g.nodes){
            auto curNode = i.second;
            auto curNodeId = i.first;
            if(curNode.left_related.empty()){
                g.nodeStatus[curNodeId] = true;
            }else g.nodeStatus[curNodeId] = false;
        }
    }
}
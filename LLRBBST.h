#pragma once
#include <string>
#include <fstream>
using namespace std;

//Node Class
class node{

  private:
    pair<string, char> dataPair;
    int count;
    node * left;
    node * right;

  public:
    node(string data);
    ~node();

    friend class tree;
};

//Tree Class
class tree{

  private:
    ofstream outFile;
    node * root;
    int treeCount = 0;

    //LLRBBST Functions
    node * rightRotation(node * parent);
    node * leftRotation(node * parent);
    void colorSwap(node * parent);
    node * autoBalance(node * start);

    //Core Methods
    node * insertNode(string data, node * parent);
    node * searchNode(string data, node * traversal);
    void destroyTree(node * destroy);

    //DOT File Format
    void DOTFile(node * start, int& i);


  public:
    tree();
    ~tree();

    //Core Methods
    void insertFunc(string data);
    node * searchFunc(string data);

    //DOT File Format Print
    void printDOT();
};
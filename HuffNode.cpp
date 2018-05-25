#include "HuffNode.h"

HuffNode::HuffNode()
{
    //this->symbol = nullptr;
    this->frequency = 0;
    this->left0 = nullptr;
    this->right1 = nullptr;
}

HuffNode::HuffNode(char symbol) {
    this->symbol = symbol;
    this->frequency = 1;
    this->left0 = nullptr;
    this->right1 = nullptr;
}

HuffNode::HuffNode(char symbol, unsigned int frequency) {
    this->symbol = symbol;
    this->frequency = frequency;
    this->left0 = nullptr;
    this->right1 = nullptr;
}

HuffNode::HuffNode(char symbol, unsigned int frequency, HuffNode* left0, HuffNode* right1) {
    this->symbol = symbol;
    this->frequency = frequency;
    this->left0 = left0;
    this->right1 = right1;
}



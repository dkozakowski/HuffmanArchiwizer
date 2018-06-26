#ifndef HUFFNODE_H
#define HUFFNODE_H


class HuffNode
{
    public:
        HuffNode();
        HuffNode(char);
        HuffNode(char, unsigned int);
        HuffNode(char, unsigned int, HuffNode*,  HuffNode*);
        char symbol;
        unsigned int frequency;
        bool child;
        HuffNode* left0;
        HuffNode* right1;
};

#endif // HUFFNODE_H

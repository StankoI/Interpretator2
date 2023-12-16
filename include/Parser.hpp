#include "ExprTree.hpp"
#include <set>
#include <vector>

class Parser
{
    public:
    enum Value_Type{STRING, BOOL, NUM, ARRAY};
    struct Node
    {
        std::string key;
        BaseValue* value;
        Value_Type type;
    };

    std::vector<Node*> arr;

    Parser();

    void readFromFile(std::istream& is);
    
    void setCommandInterp(std::istream &is, char &next);

    void printCommandInterp(std::istream &is, char &next);

    void readCommandInterp(std::istream &is, char &next);

    double RPNeval(std::istream &in);

    Node* find(std::string key);

    void setNum(std::istream &is, char &next, Node* temp);

    void setArray(std::istream &is, char &next, Node* temp);

    void setBool(std::istream &is, char &next, Node* temp);

    void setString(std::istream &is, char &next, Node* temp);

    NumValue* setNumHelper(std::istream &is, char &next);

    StringValue* setStringHelper(std::istream &is, char &next);

    BoolValue* setBoolHelper(std::istream &is, char &next);

    ArrayValue* setArrayHelper(std::istream &is, char &next);

    Expression* parseExpression(std::istream &is);

    Expression* parseExpression(Tokenizer &tokens);

    Expression *parseConst(Tokenizer &tokens);

    Expression *parseIfExpression(Tokenizer &tokens);

    Expression *parseParExpression(Tokenizer &tokens);

    void setExistingNode(Node* existingNode,std::istream &is, char &next);

    //todo Destructor, operator=, copyconstructor 
};

std::string infixToRPN(std::istream &in);
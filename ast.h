#ifndef ast_h  //es igual a pragma once
#define ast_h  

// using namespace std;

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
};


/**
 * int SubNode::multiply() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}
 * */
class BinaryNode : public AST {
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};

class AddNode : public BinaryNode {
 public:
   AddNode(AST* left, AST* right);
   
   int evaluate();
};

class SubNode : public BinaryNode {
 public:
   SubNode(AST* left, AST* right);

   int evaluate();
};

class MulNode : public BinaryNode
{
  public:
  MulNode(AST* left, AST* right);

  int evaluate();
};

class DivNode : public BinaryNode {
 public:
   DivNode(AST* left, AST* right);

   int evaluate();
};

class ModNode : public BinaryNode {
 public:
   ModNode(AST* left, AST* right);

   int evaluate();
};

class PowNode : public BinaryNode {
 public:
   PowNode(AST* left, AST* right);
   
   int evaluate();
};

class NumNode : public AST {
 public:
   NumNode(int n);

   int evaluate();

 private:
   int val;
};


#endif


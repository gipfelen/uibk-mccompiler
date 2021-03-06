#ifndef __BOOL_LITERAL_AST_HPP__
#define __BOOL_LITERAL_AST_HPP__

#include "LiteralAST.hpp"

/**
 * The AST class, which represents a bool literal
 */
namespace MC{
  class BoolLiteralAST: public LiteralAST{
  private:
    bool variable;

  public:

    /**
     * Create a BoolLiteralAST tree, given the value of the litteral
     * @param variable Value of the literal
     * @param lineNumber line number in the code
     */
    BoolLiteralAST(bool variable, int lineNumber);
    ~BoolLiteralAST();

    /**
     * Returns the AST node as a string. This coresponds to the DOT node representation
     * @return the AST subtype as a string
     */
    std::string getAsString() const;

    /**
     * Creates a DOT note representation of the current node, which gets added to the parameter dot
     * @param dot dot tree where the current node should be added to
     */
    void generateDOT(DOTTree_p dot);

    /**
     * Traverses the tree in preOrder and executes function f on each compnent
     * @param f Funtion to call on each component.
     */
    void preOrder(std::function<void(AST*)> f);

    /**
     * Traverses the tree in postOrder and executes function f on each compnent
     * @param f Funtion to call on each component.
     */
    void postOrder(std::function<void(AST*)> f, bool deepTraversal);

    /**
     * Evaluates the type of the expression
     * @param symbolTable symbolTable of the current scope
     */
    void evaluateType(std::ostream& os, SymbolTable &symbolTable);


    /**
     * Generates the ICR for the ast
     * @param os Output stream
     */
      void generateICR(std::ostream&);
  };
}

#endif /* END __BOOL_LITERAL_AST_HPP__ */

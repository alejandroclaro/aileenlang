/**
 * @file SymbolVisitor.h
 *
 * @brief Declaration of parsing visitor for symbol table generation.
 *
 * @author   alejandro.claro
 * @date     May 09, 2017
 *
 * @copyright 2017 Alejandro Claro. All Rights Reserved.
 */

#ifndef AILEEN_SYMBOLVISITOR_H
#define AILEEN_SYMBOLVISITOR_H

/* INCLUDES ***********************************************************************************************************/

#include <AileenBaseVisitor.h>
#include "ParseContext.h"

/* CLASS DECLARATION **************************************************************************************************/

namespace Aileen
{

/**
 * @brief Parsing visitor for symbol table generation.
 */
class SymbolVisitor : public Grammar::AileenBaseVisitor
{
  public:

    /**
     * @brief Visits the parse tree.
     *
     * @param tree The parse tree to visit.
     *
     * @return The parse context information.
     */
    ParseContext visit(antlr4::tree::ParseTree& tree);

    virtual antlrcpp::Any visitModule(Grammar::AileenParser::ModuleContext *ctx) override;

    virtual antlrcpp::Any visitFunctionDefinition(Grammar::AileenParser::FunctionDefinitionContext *ctx) override;

    virtual antlrcpp::Any visitParameters(Grammar::AileenParser::ParametersContext *ctx) override;

    virtual antlrcpp::Any visitParameter(Grammar::AileenParser::ParameterContext *ctx) override;

    virtual antlrcpp::Any visitReturnType(Grammar::AileenParser::ReturnTypeContext *ctx) override;

    virtual antlrcpp::Any visitParameterType(Grammar::AileenParser::ParameterTypeContext *ctx) override;

    virtual antlrcpp::Any visitBlock(Grammar::AileenParser::BlockContext *ctx) override;

    virtual antlrcpp::Any visitBindingDeclarationList(Grammar::AileenParser::BindingDeclarationListContext *ctx);

    virtual antlrcpp::Any visitStatementList(Grammar::AileenParser::StatementListContext *ctx) override;

    virtual antlrcpp::Any visitStatement(Grammar::AileenParser::StatementContext *ctx) override;

    virtual antlrcpp::Any visitReturnStatement(Grammar::AileenParser::ReturnStatementContext *ctx) override;

    virtual antlrcpp::Any visitBindingDeclaration(Grammar::AileenParser::BindingDeclarationContext *ctx) override;

    virtual antlrcpp::Any visitConstantBindingDeclaration(Grammar::AileenParser::ConstantBindingDeclarationContext *ctx) override;

    virtual antlrcpp::Any visitVariableBindingDeclaration(Grammar::AileenParser::VariableBindingDeclarationContext *ctx) override;

    virtual antlrcpp::Any visitExpression(Grammar::AileenParser::ExpressionContext *ctx) override;

    virtual antlrcpp::Any visitLiteral(Grammar::AileenParser::LiteralContext *ctx) override;

    virtual antlrcpp::Any visitPrimitiveType(Grammar::AileenParser::PrimitiveTypeContext *ctx) override;

  private:

    std::string m_indent;
};

} // namespace Aileen

#endif // AILEEN_SYMBOLVISITOR_H

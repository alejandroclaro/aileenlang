/**
 * @file SymbolVisitor.cpp
 *
 * @brief Implementation of parsing visitor for symbol table generation.
 *
 * @author   alejandro.claro
 * @date     May 09, 2017
 *
 * @copyright 2017 Alejandro Claro. All Rights Reserved.
 */

/* INCLUDES ***********************************************************************************************************/

#include "SymbolVisitor.h"

/* USINGS *************************************************************************************************************/

using namespace Grammar;

/* CLASS IMPLEMENTATION ***********************************************************************************************/

namespace Aileen
{

ParseContext
SymbolVisitor::visit(antlr4::tree::ParseTree& tree)
{
  antlrcpp::Any result = AileenBaseVisitor::visit(&tree);

  if (result.is<ParseContext>())
    return result.as<ParseContext>();

  return ParseContext();
}

antlrcpp::Any SymbolVisitor::visitModule(Grammar::AileenParser::ModuleContext *ctx)
{
  std::cout << m_indent << "Visit module" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitModule(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitFunctionDefinition(Grammar::AileenParser::FunctionDefinitionContext *ctx)
{
  std::cout << m_indent << "Visit function" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitFunctionDefinition(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitParameters(Grammar::AileenParser::ParametersContext *ctx)
{
  std::cout << m_indent << "Visit parameter list" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitParameters(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitParameter(Grammar::AileenParser::ParameterContext *ctx)
{
  std::cout << m_indent << "Visit parameter" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitParameter(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitReturnType(Grammar::AileenParser::ReturnTypeContext *ctx)
{
  std::cout << m_indent << "Visit return type" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitReturnType(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitParameterType(Grammar::AileenParser::ParameterTypeContext *ctx)
{
  std::cout << m_indent << "Visit parameter type" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitParameterType(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitBlock(Grammar::AileenParser::BlockContext *ctx)
{
  std::cout << m_indent << "Visit block" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitBlock(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitBindingDeclarationList(Grammar::AileenParser::BindingDeclarationListContext *ctx)
{
  std::cout << m_indent << "Visit binding declaration list" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitBindingDeclarationList(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitStatementList(Grammar::AileenParser::StatementListContext *ctx)
{
  std::cout << m_indent << "Visit statement list" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitStatementList(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitStatement(Grammar::AileenParser::StatementContext *ctx)
{
  std::cout << m_indent << "Visit statement" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitStatement(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitReturnStatement(Grammar::AileenParser::ReturnStatementContext *ctx)
{
  std::cout << m_indent << "Visit return" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitReturnStatement(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitBindingDeclaration(Grammar::AileenParser::BindingDeclarationContext *ctx)
{
  std::cout << m_indent << "Visit binding declaration" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitBindingDeclaration(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any
SymbolVisitor::visitConstantBindingDeclaration(Grammar::AileenParser::ConstantBindingDeclarationContext *ctx)
{
  std::cout << m_indent << "Visit constant declaration" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitConstantBindingDeclaration(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any
SymbolVisitor::visitVariableBindingDeclaration(Grammar::AileenParser::VariableBindingDeclarationContext *ctx)
{
  std::cout << m_indent << "Visit variable declaration" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitVariableBindingDeclaration(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitExpression(Grammar::AileenParser::ExpressionContext *ctx)
{
  std::cout << m_indent << "Visit expression" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitExpression(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitLiteral(Grammar::AileenParser::LiteralContext *ctx)
{
  std::cout << m_indent << "Visit literal" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitLiteral(ctx);
  m_indent.pop_back();

  return result;
}

antlrcpp::Any SymbolVisitor::visitPrimitiveType(Grammar::AileenParser::PrimitiveTypeContext *ctx)
{
  std::cout << m_indent << "Visit primitive type" << std::endl;
  m_indent += " ";
  antlrcpp::Any result = AileenBaseVisitor::visitPrimitiveType(ctx);
  m_indent.pop_back();

  return result;
}

} // namespace Aileen

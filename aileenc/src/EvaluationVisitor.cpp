/**
 * @file EvaluationVisitor.cpp
 *
 * @brief Implementation of parsing visitor for grammar evaluation.
 *
 * @author   alejandro.claro
 * @date     May 09, 2017
 *
 * @copyright 2017 Alejandro Claro. All Rights Reserved.
 */

/* INCLUDES ***********************************************************************************************************/

#include "EvaluationVisitor.h"

/* CLASS IMPLEMENTATION ***********************************************************************************************/

namespace Aileen
{

ParseContext
EvaluationVisitor::visit(antlr4::tree::ParseTree& tree, const ParseContext& context)
{
  antlrcpp::Any result = Grammar::AileenBaseVisitor::visit(&tree);

  if (result.is<ParseContext>())
    return result.as<ParseContext>();

  return ParseContext();
}

} // namespace Aileen

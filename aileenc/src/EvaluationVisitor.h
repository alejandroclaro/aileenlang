/**
 * @file EvaluationVisitor.h
 *
 * @brief Declaration of parsing visitor for grammar evaluation.
 *
 * @author   alejandro.claro
 * @date     May 09, 2017
 *
 * @copyright 2017 Alejandro Claro. All Rights Reserved.
 */

#ifndef AILEEN_EVALUATIONVISITOR_H
#define AILEEN_EVALUATIONVISITOR_H

/* INCLUDES ***********************************************************************************************************/

#include <AileenBaseVisitor.h>
#include "ParseContext.h"

/* CLASS DECLARATION **************************************************************************************************/

namespace Aileen
{

/**
 * @brief Parsing visitor for symbol table generation.
 */
class EvaluationVisitor : public Grammar::AileenBaseVisitor
{
  public:

    /**
     * @brief Visits the AST.
     *
     * @param tree    The parse tree to visit.
     * @param context The input context with symbol table information.
     *
     * @return The parse context information.
     */
    ParseContext visit(antlr4::tree::ParseTree& tree, const ParseContext& context);

  private:

    ParseContext m_symbolContext;
};

} // namespace Aileen

#endif // AILEEN_EVALUATIONVISITOR_H

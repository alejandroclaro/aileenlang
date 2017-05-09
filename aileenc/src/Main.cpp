/**
 * @file Main.cpp
 *
 * @brief Aileen compiler entry point.
 *
 * @author   alejandro.claro
 * @date     May 07, 2017
 *
 * @copyright 2017 Alejandro Claro. All Rights Reserved.
 */

/* INCLUDES ***********************************************************************************************************/

#include <AileenLexer.h>
#include <AileenParser.h>
#include <AileenListener.h>

#include "SymbolVisitor.h"
#include "EvaluationVisitor.h"

#include <antlr4-runtime.h>
#include <fstream>

/* USINGS *************************************************************************************************************/

using namespace Aileen;
using namespace antlr4;
using namespace antlr4::tree;
using namespace Grammar;

/* IMPLEMENTATION *****************************************************************************************************/

/**
 * @brief Application entry point.
 *
 * @param argc The number of arguments.
 * @param argv The arguments collection.
 *
 * @return 0 if successful; otherwise, an error code.
 */
int
main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " file" << std::endl;
    return EXIT_FAILURE;
  }

  std::ifstream     file{argv[1]};
  ANTLRInputStream  input{file};
  AileenLexer       lexer{&input};
  CommonTokenStream tokens{&lexer};
  AileenParser      parser{&tokens};
  ParseTree*        tree{parser.module()};
  SymbolVisitor     symbolVisitor;
  EvaluationVisitor evaluationVisitor;
  ParseContext      context;

  context = symbolVisitor.visit(*tree);
  evaluationVisitor.visit(*tree, context);

  std::cout << tree->toStringTree(&parser) << std::endl;

  return EXIT_SUCCESS;
}
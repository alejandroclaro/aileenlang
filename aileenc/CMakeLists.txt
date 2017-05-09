CMAKE_MINIMUM_REQUIRED (VERSION 3.7)
PROJECT (aileenc CXX)

# Configure CMake.
SET (CMAKE_CXX_STANDARD 14)
SET (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Configure ANTLRv4
SET (ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third-party/antlr/antlr-4.7-complete.jar)
INCLUDE (ExternalAntlr4Cpp)
ANTLR4CPP_PROCESS_GRAMMAR (aileenc Grammar ${PROJECT_SOURCE_DIR}/grammar/Aileen.g4 ${PROJECT_SOURCE_DIR}/grammar/Aileen.g4)

# Include header directories.
INCLUDE_DIRECTORIES (${ANTLR4CPP_INCLUDE_DIRS})
INCLUDE_DIRECTORIES (${ANTLR4CPP_INCLUDE_DIRS_GRAMMAR})

# Include library directories.
LINK_DIRECTORIES (${ANTLR4CPP_LIBS})

# Setup compilation.
SET (SOURCE_FILES src/Main.cpp src/ParseContext.cpp src/ParseContext.h src/SymbolVisitor.cpp src/SymbolVisitor.h src/EvaluationVisitor.cpp src/EvaluationVisitor.h)
ADD_EXECUTABLE (aileenc ${SOURCE_FILES} ${ANTLR4CPP_SRC_FILES_GRAMMAR})

TARGET_LINK_LIBRARIES (aileenc
  antlr4-runtime)

# Setup dependencies.
ADD_DEPENDENCIES (aileenc antlr4cpp ANTLR4CPP_GENERATION_GRAMMAR)

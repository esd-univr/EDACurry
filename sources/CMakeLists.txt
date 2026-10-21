# -----------------------------------------------------------------------------
# @brief  : CmakeFile for building the edacurry library.
# @author : Enrico Fraccaroli, Nicola Dall'Ora, Christian Checchetti
# -----------------------------------------------------------------------------

# Set the minimum CMake version, the project name and default build type.
cmake_minimum_required(VERSION 3.15...3.18)

# Set the project name.
project(edacurry CXX)

# Set the default build type to Debug.
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
endif()
# Add location of cmake modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------------------------------------------------------
# OPTIONS
# -----------------------------------------------------------------------------

option(STRICT_WARNINGS "Enable strict compiler warnings" ON)
option(WARNINGS_AS_ERRORS "Treat all warnings as errors" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

# -----------------------------------------------------------------------------
# ENABLE FETCH CONTENT
# -----------------------------------------------------------------------------

# We need this in order to import external projects.
include(FetchContent)
# Hide fetchcontent variables.
mark_as_advanced(FORCE
        FETCHCONTENT_QUIET
        FETCHCONTENT_BASE_DIR
        FETCHCONTENT_FULLY_DISCONNECTED
        FETCHCONTENT_UPDATES_DISCONNECTED
)

# -----------------------------------------------------------------------------
# DEPENDENCY (SYSTEM LIBRARIES)
# -----------------------------------------------------------------------------

find_package(Python COMPONENTS Interpreter Development)
find_package(Doxygen)
#find_package(ANTLR4 REQUIRED)

# -----------------------------------------------------------------------------
# DIPENDENCIES (REPOSITORIES)
# -----------------------------------------------------------------------------

# =====================================
# PYBIND11
# =====================================
# Retrieve the pybind11.
FetchContent_Declare(pybind11
        GIT_REPOSITORY "https://github.com/pybind/pybind11.git"
        GIT_TAG a2e59f0e7065404b44dfe92a28aca47ba1378dc4 # v2.13.6
)
# Retrieve the properties related to the content.
FetchContent_MakeAvailable(pybind11)
# Hide fetchcontent variables.
mark_as_advanced(FORCE
        FETCHCONTENT_UPDATES_DISCONNECTED_PYBIND11
        FETCHCONTENT_SOURCE_DIR_PYBIND11
)

# =====================================
# PYBIND11-STUBGEN
# =====================================
# Retrieve the stubgen.
FetchContent_Declare(stubgen
        GIT_REPOSITORY "https://github.com/sizmailov/pybind11-stubgen.git"
        GIT_TAG 99f14a1c8486d1ad6a0bdd9ceca81df1531b31c3 # v2.4.2
)
# Retrieve the properties related to the content.
FetchContent_MakeAvailable(stubgen)
# Hide fetchcontent variables.
mark_as_advanced(FORCE
        FETCHCONTENT_UPDATES_DISCONNECTED_STUBGEN
        FETCHCONTENT_SOURCE_DIR_STUBGEN
)

# =====================================
# JSON
# =====================================
# Retrieve the json.
FetchContent_Declare(json
        GIT_REPOSITORY "https://github.com/Galfurian/json.git"
        GIT_TAG d0888ac42fe967ba4a430f3fba860c2ae6140208 # v2.2.3
)
# Retrieve the properties related to the content.
FetchContent_MakeAvailable(json)
# Hide fetchcontent variables.
mark_as_advanced(FORCE
        FETCHCONTENT_UPDATES_DISCONNECTED_JSON
        FETCHCONTENT_SOURCE_DIR_JSON
)

# =====================================
# PUGIXML
# =====================================
# Retrieve the repository.
FetchContent_Declare(pugixml
        GIT_REPOSITORY "https://github.com/zeux/pugixml.git"
        GIT_TAG db78afc2b7d8f043b4bc6b185635d949ea2ed2a8 # v1.14
)
# Retrieve the properties related to the content.
FetchContent_MakeAvailable(pugixml)
# Hide fetchcontent variables.
mark_as_advanced(FORCE
        FETCHCONTENT_UPDATES_DISCONNECTED_PUGIXML
        FETCHCONTENT_SOURCE_DIR_PUGIXML
)

# =====================================
# ANTLR4 RUNTIME (macOS only)
# =====================================
if(APPLE)
    # 1. Douwnload Antlr4 source code
    FetchContent_Declare(
            antlr4_cpp_runtime
            GIT_REPOSITORY https://github.com/antlr/antlr4.git
            GIT_TAG        4.9
            GIT_SUBMODULES ""
    )

    # Ignore warnings
    if(POLICY CMP0169)
        cmake_policy(SET CMP0169 OLD)
    endif()

    FetchContent_GetProperties(antlr4_cpp_runtime)
    if(NOT antlr4_cpp_runtime_POPULATED)
        FetchContent_Populate(antlr4_cpp_runtime)
    endif()

    # 2. Retrieve .cpp runtime files
    file(GLOB_RECURSE ANTLR4_SRC_FILES
            "${antlr4_cpp_runtime_SOURCE_DIR}/runtime/Cpp/runtime/src/*.cpp"
    )

    # 3. Compile
    add_library(antlr4_static STATIC ${ANTLR4_SRC_FILES})
    target_compile_definitions(antlr4_static PUBLIC ANTLR4CPP_STATIC)
    target_include_directories(antlr4_static PUBLIC
            "${antlr4_cpp_runtime_SOURCE_DIR}/runtime/Cpp/runtime/src"
    )

    # 4. Set variables
    set(ANTLR4_INCLUDE_DIRS "${antlr4_cpp_runtime_SOURCE_DIR}/runtime/Cpp/runtime/src")
    set(ANTLR4_STATIC_LIB antlr4_static)
endif()


# =====================================
# DOXYGENAWESOME
# =====================================
if(DOXYGEN_FOUND)
    # Record the options that describe how to populate the specified content.
    FetchContent_Declare(doxygenawesome
            GIT_REPOSITORY https://github.com/jothepro/doxygen-awesome-css
            GIT_TAG df88fe4fdd97714fadfd3ef17de0b4401f804052
    )
    # Retrieve the properties related to the content.
    FetchContent_MakeAvailable(doxygenawesome)
    # Hide fetchcontent variables, otherwise with ccmake it's a mess.
    mark_as_advanced(FORCE
            FETCHCONTENT_UPDATES_DISCONNECTED_DOXYGENAWESOME
            FETCHCONTENT_SOURCE_DIR_DOXYGENAWESOME
    )
endif(DOXYGEN_FOUND)

# -----------------------------------------------------------------------------
# C++ Library with Python wrapping.
# -----------------------------------------------------------------------------
# Add the python wrapped library.
pybind11_add_module(
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/src/edacurry/edacurry.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/enums.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/factory.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/analysis.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/circuit.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/control.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/control_scope.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/node.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/object.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/parameter.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/subckt.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/include.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/library.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/library_def.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/component.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/model.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/identifier.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/function_call.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/expression.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/value_list.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/expression_unary.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/value.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/value_list.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/value_pair.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/number.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/structure/string.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/utility/logging.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/utility/utility.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/utility/visitor_utilities.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/frontend/eldo_frontend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/frontend/json_frontend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/frontend/xml_frontend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/frontend/spectre_frontend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/backend/xml_backend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/backend/json_backend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/backend/eldo_backend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/backend/ngspice_backend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/backend/spectre_backend.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/features/named_object.cpp
        ${PROJECT_SOURCE_DIR}/src/edacurry/features/visitable_object.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/ELDOLexer.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/ELDOParser.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/ELDOParserBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/ELDOParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/ELDOParserListener.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/ELDOParserVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/SPECTRELexer.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/SPECTREParser.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/SPECTREParserBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/SPECTREParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/SPECTREParserListener.cpp
        ${PROJECT_SOURCE_DIR}/src/antlr4parser/SPECTREParserVisitor.cpp
)

# Add a macro inside the C++, so that we can de-activate the python wrapping code.
target_compile_definitions(${PROJECT_NAME} PRIVATE PYTHON_INTERFACE_ENABLED)

# --- Use local ANTLR4 library and headers ---
#set(ANTLR4_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/libraries/include")
#target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${ANTLR4_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/libraries/include/antlr4-runtime)
#set(ANTLR4_LIBRARIES "${PROJECT_SOURCE_DIR}/libraries/libantlr4-runtime.so")

#target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_LIBRARIES})

# --- Set RPATH so the .so finds libraries at runtime ---
#set_target_properties(${PROJECT_NAME} PROPERTIES
#    INSTALL_RPATH "$ORIGIN/libraries"
#    BUILD_WITH_INSTALL_RPATH TRUE
#)

# --- Use local statically compiled ANTLR4 library and headers under Linux systems. Retrieve thre proper macOS version otherwise ---
#set(ANTLR4_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/libraries/include")
#set(ANTLR4_STATIC_LIB "${PROJECT_SOURCE_DIR}/libraries/libantlr4-runtime.a")

#target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${ANTLR4_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/libraries/include/antlr4-runtime)

if(APPLE)
    set(ANTLR4_INCLUDE_DIRS "${antlr4_cpp_runtime_SOURCE_DIR}/runtime/Cpp/runtime/src")
    set(ANTLR4_STATIC_LIB antlr4_static)
else()
    set(ANTLR4_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/libraries/include")
    set(ANTLR4_STATIC_LIB "${PROJECT_SOURCE_DIR}/libraries/libantlr4-runtime.a")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${ANTLR4_INCLUDE_DIRS})
if(NOT APPLE)
    target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/libraries/include/antlr4-runtime)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_STATIC_LIB})

# Include the project headers.
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${pybind11_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${json_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/antlr4parser)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${ANTLR4_INCLUDE_DIRS})

# Link libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE json)
target_link_libraries(${PROJECT_NAME} PRIVATE pugixml-static)

target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

# Static link libstdc++ and libgcc for portability
#target_link_options(${PROJECT_NAME} PRIVATE -static-libstdc++ -static-libgcc)
target_link_options(${PROJECT_NAME} PRIVATE
        $<$<NOT:$<PLATFORM_ID:Darwin>>:-static-libstdc++>
        $<$<NOT:$<PLATFORM_ID:Darwin>>:-static-libgcc>
)


# -----------------------------------------------------------------------------
# COMPILATION FLAGS
# -----------------------------------------------------------------------------

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Disable warnings that suggest using MSVC-specific safe functions
    target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
    if(WARNINGS_AS_ERRORS)
        target_compile_options(${PROJECT_NAME} PRIVATE /WX)
    endif()
    if(STRICT_WARNINGS)
        # Mark system headers as external for MSVC explicitly
        # https://devblogs.microsoft.com/cppblog/broken-warnings-theory
        target_compile_options(${PROJECT_NAME} PRIVATE /experimental:external)
        target_compile_options(${PROJECT_NAME} PRIVATE /external:I ${CMAKE_BINARY_DIR})
        target_compile_options(${PROJECT_NAME} PRIVATE /external:anglebrackets)
        target_compile_options(${PROJECT_NAME} PRIVATE /external:W0)
        target_compile_options(${PROJECT_NAME} PRIVATE /W4)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if(WARNINGS_AS_ERRORS)
        target_compile_options(${PROJECT_NAME} PRIVATE -Werror)
    endif()
    if(STRICT_WARNINGS)
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wconversion -pedantic)
    endif()
endif()

# -----------------------------------------------------------------------------
# Add the target for generating the python interface.
# -----------------------------------------------------------------------------

add_custom_target(
        stubs
        COMMAND ${CMAKE_COMMAND} -E echo "Generating python stubs..."
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${stubgen_SOURCE_DIR}
        ${Python_EXECUTABLE} -m pybind11_stubgen ${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E echo "Generating python stubs... done!"
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM
)

# -----------------------------------------------------------------------------
# DOCUMENTATION
# -----------------------------------------------------------------------------

if(DOXYGEN_FOUND)

    set(DOXYGEN_WARN_FORMAT "$file:$line: $text")
    set(DOXYGEN_PROJECT_NAME "Lumen et Umbra (LeU)")
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${PROJECT_SOURCE_DIR}/README.md)
    set(DOXYGEN_SHOW_INCLUDE_FILES NO)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_HTML_HEADER ${doxygenawesome_SOURCE_DIR}/doxygen-custom/header.html)
    set(DOXYGEN_HTML_EXTRA_STYLESHEET ${doxygenawesome_SOURCE_DIR}/doxygen-awesome.css)
    set(DOXYGEN_HTML_EXTRA_FILES
            ${doxygenawesome_SOURCE_DIR}/doxygen-awesome-fragment-copy-button.js
            ${doxygenawesome_SOURCE_DIR}/doxygen-awesome-paragraph-link.js
            ${doxygenawesome_SOURCE_DIR}/doxygen-awesome-darkmode-toggle.js
    )
    doxygen_add_docs(
            ${PROJECT_NAME}_documentation
            ${PROJECT_SOURCE_DIR}/include/backend/eldo_backend.hpp
            ${PROJECT_SOURCE_DIR}/include/backend/ngspice_backend.hpp
            ${PROJECT_SOURCE_DIR}/include/backend/spectre_backend.hpp
            ${PROJECT_SOURCE_DIR}/include/backend/indented_stream.hpp
            ${PROJECT_SOURCE_DIR}/include/backend/json_backend.hpp
            ${PROJECT_SOURCE_DIR}/include/backend/xml_backend.hpp
            ${PROJECT_SOURCE_DIR}/include/classes.hpp
            ${PROJECT_SOURCE_DIR}/include/enums.hpp
            ${PROJECT_SOURCE_DIR}/include/factory.hpp
            ${PROJECT_SOURCE_DIR}/include/features/named_object.hpp
            ${PROJECT_SOURCE_DIR}/include/features/owned_list.hpp
            ${PROJECT_SOURCE_DIR}/include/features/object_reference.hpp
            ${PROJECT_SOURCE_DIR}/include/features/visitable_object.hpp
            ${PROJECT_SOURCE_DIR}/include/frontend/eldo_frontend.hpp
            ${PROJECT_SOURCE_DIR}/include/frontend/json_frontend.hpp
            ${PROJECT_SOURCE_DIR}/include/frontend/spectre_frontend.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/analysis.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/circuit.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/component.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/control.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/control_scope.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/expression.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/expression_unary.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/function_call.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/identifier.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/include.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/library.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/library_def.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/model.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/node.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/number.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/object.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/parameter.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/string.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/subckt.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/value.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/value_list.hpp
            ${PROJECT_SOURCE_DIR}/include/structure/value_pair.hpp
            ${PROJECT_SOURCE_DIR}/include/utility/logging.hpp
            ${PROJECT_SOURCE_DIR}/include/utility/typename.hpp
            ${PROJECT_SOURCE_DIR}/include/utility/utility.hpp
            README.md
    )

endif(DOXYGEN_FOUND)
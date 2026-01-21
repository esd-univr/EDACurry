/// @file typename_specializations.hpp
/// @author Nicola Dall'Ora (nicola.dallora@univr.it)
/// @brief TypeName specializations for EDACurry structure types.
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// @copyright Copyright (c) 2026 Electronic Systems Design (ESD) Laboratory, University of Verona
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#pragma once

#include "edacurry/utility/typename.hpp"
#include <string>

// Forward declarations to avoid including heavy headers
namespace edacurry
{
namespace structure
{
class Analysis;
class Circuit;
class Component;
class Control;
class ControlScope;
class ExpressionUnary;
class Expression;
class FunctionCall;
class Identifier;
class Include;
class LibraryDef;
class Library;
class Model;
class Node;
class Parameter;
class String;
class Subckt;
class ValueList;
class ValuePair;
class Value;
class Object;
template <typename T>
class Number;
} // namespace structure

namespace features
{
template <typename T>
class OwnedList;
} // namespace features
} // namespace edacurry

namespace edacurry
{

template <typename T>
struct TypeName<edacurry::structure::Number<T>> {
    static std::string get()
    {
        return "Number<" + TypeName<T>::get() + ">";
    }
};

template <>
struct TypeName<edacurry::structure::Analysis> {
    static std::string get()
    {
        return "Analysis";
    }
};

template <>
struct TypeName<edacurry::structure::Circuit> {
    static std::string get()
    {
        return "Circuit";
    }
};

template <>
struct TypeName<edacurry::structure::Component> {
    static std::string get()
    {
        return "Component";
    }
};

template <>
struct TypeName<edacurry::structure::Control> {
    static std::string get()
    {
        return "Control";
    }
};

template <>
struct TypeName<edacurry::structure::ControlScope> {
    static std::string get()
    {
        return "ControlScope";
    }
};

template <>
struct TypeName<edacurry::structure::ExpressionUnary> {
    static std::string get()
    {
        return "UnaryExpression";
    }
};

template <>
struct TypeName<edacurry::structure::Expression> {
    static std::string get()
    {
        return "Expression";
    }
};

template <>
struct TypeName<edacurry::structure::FunctionCall> {
    static std::string get()
    {
        return "FunctionCall";
    }
};

template <>
struct TypeName<edacurry::structure::Identifier> {
    static std::string get()
    {
        return "Identifier";
    }
};

template <>
struct TypeName<edacurry::structure::Include> {
    static std::string get()
    {
        return "Include";
    }
};

template <>
struct TypeName<edacurry::structure::LibraryDef> {
    static std::string get()
    {
        return "LibraryDef";
    }
};

template <>
struct TypeName<edacurry::structure::Library> {
    static std::string get()
    {
        return "Library";
    }
};

template <>
struct TypeName<edacurry::structure::Model> {
    static std::string get()
    {
        return "Model";
    }
};

template <>
struct TypeName<edacurry::structure::Node> {
    static std::string get()
    {
        return "Node";
    }
};

template <>
struct TypeName<edacurry::structure::Parameter> {
    static std::string get()
    {
        return "Parameter";
    }
};

template <>
struct TypeName<edacurry::structure::String> {
    static std::string get()
    {
        return "String";
    }
};

template <>
struct TypeName<edacurry::structure::Subckt> {
    static std::string get()
    {
        return "Subckt";
    }
};

template <>
struct TypeName<edacurry::structure::ValueList> {
    static std::string get()
    {
        return "List";
    }
};

template <>
struct TypeName<edacurry::structure::ValuePair> {
    static std::string get()
    {
        return "Pair";
    }
};

template <typename T>
struct TypeName<edacurry::features::OwnedList<T>> {
    static std::string get()
    {
        return "List<" + TypeName<T>::get() + ">";
    }
};

template <>
struct TypeName<edacurry::structure::Value> {
    static std::string get()
    {
        return "Value";
    }
};

template <>
struct TypeName<edacurry::structure::Object> {
    static std::string get()
    {
        return "Object";
    }
};

} // namespace edacurry

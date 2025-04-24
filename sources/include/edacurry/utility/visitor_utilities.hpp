/// @file visitor_utilities.hpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#pragma once

#include "edacurry/features/visitable_object.hpp"

#include <memory>
#include <string>

namespace edacurry
{

/// @brief A visitor that finds a component by name.
class FindComponentVisitor : public features::BaseVisitor {
public:
    explicit FindComponentVisitor(const std::string &target, bool descend = true);

    int visitComponent(const std::shared_ptr<structure::Component> &e) override;

    int visitSubckt(const std::shared_ptr<structure::Subckt> &e) override;

    int visitModel(const std::shared_ptr<structure::Model> &e) override;

    int visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e) override;

    std::shared_ptr<structure::Component> getResult() const;

private:
    std::string _target;
    bool _descend;
    std::shared_ptr<structure::Component> _result;
};

/// @brief A visitor that finds a parameter by name.
class FindParameterVisitor : public features::BaseVisitor {
public:
    explicit FindParameterVisitor(const std::string &target, bool descend = false);

    int visitParameter(const std::shared_ptr<structure::Parameter> &e) override;

    int visitSubckt(const std::shared_ptr<structure::Subckt> &e) override;

    int visitModel(const std::shared_ptr<structure::Model> &e) override;

    int visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e) override;

    std::shared_ptr<structure::Parameter> getResult() const;

private:
    std::string _target;
    bool _descend;
    std::shared_ptr<structure::Parameter> _result;
};

/// @brief A visitor that renames nodes and identifiers in a structure object.
class FindSubcktVisitor : public features::BaseVisitor {
public:
    explicit FindSubcktVisitor(const std::string &target, bool descend = true);

    int visitSubckt(const std::shared_ptr<structure::Subckt> &e) override;

    std::shared_ptr<structure::Subckt> getResult() const;

private:
    std::string _target;
    bool _descend;
    std::shared_ptr<structure::Subckt> _result;
};

/// @brief A visitor that renames nodes and identifiers in a structure object.
class RenameNodeVisitor : public edacurry::features::BaseVisitor {
public:
    RenameNodeVisitor(const std::string &old_name, const std::string &new_name);

    int visitNode(const std::shared_ptr<structure::Node> &n) override;

    int visitIdentifier(const std::shared_ptr<structure::Identifier> &id) override;

private:
    std::string _old_name;
    std::string _new_name;
};

/// @brief Find a component with a given name inside a structure object.
/// @param root The root structure object to search from.
/// @param name The name of the component to find.
/// @param descend Whether to descend into subcircuits and models.
/// @return A shared pointer to the matching component, or nullptr if not found.
std::shared_ptr<edacurry::structure::Component> find_component(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend = true);

/// @brief Find a parameter with a given name inside a structure object.
/// @param root The root structure object to search from.
/// @param name The name of the parameter to find.
/// @param descend Whether to descend into subcircuits and models.
/// @return A shared pointer to the matching parameter, or nullptr if not found.
std::shared_ptr<edacurry::structure::Parameter> find_parameter(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend = false);

/// @brief Find a subcircuit with a given name inside a structure object.
/// @param root The root structure object to search from.
/// @param name The name of the subcircuit to find.
/// @param descend Whether to descend into subcircuits and models.
/// @return A shared pointer to the matching subcircuit, or nullptr if not found.
std::shared_ptr<structure::Subckt> find_subckt(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend = true);

/// @brief Rename a node in a given scope.
/// @param scope The scope in which to rename the node.
/// @param old_name The current name of the node.
/// @param new_name The new name to assign to the node.
void rename_node(
    const std::shared_ptr<structure::Object> &scope,
    const std::string &old_name,
    const std::string &new_name);

} // namespace edacurry
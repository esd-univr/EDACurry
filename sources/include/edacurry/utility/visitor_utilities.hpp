/// @file visitor_utilities.hpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#pragma once

#include "edacurry/features/visitable_object.hpp"

#include <functional>
#include <memory>
#include <string>

namespace edacurry
{

/// @brief A visitor that finds components based on a hit function.
class FindComponentVisitor : public features::BaseVisitor {
public:
    /// @brief A function type that takes a component and returns a boolean indicating if it is a hit.
    using HitFunction = std::function<bool(const std::shared_ptr<structure::Component> &)>;

    /// @brief Constructor for FindComponentVisitor.
    /// @param hit_function A function that takes a component and returns true if it is a hit.
    /// @param descend Whether to descend into subcircuits and models.
    /// @param terminate_on_hit If true, the visitor will stop searching after the first hit.
    explicit FindComponentVisitor(const HitFunction &hit_function, bool descend = true, bool terminate_on_hit = false);

    int visitComponent(const std::shared_ptr<structure::Component> &e) override;

    int visitSubckt(const std::shared_ptr<structure::Subckt> &e) override;

    int visitModel(const std::shared_ptr<structure::Model> &e) override;

    int visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e) override;

    /// @brief Get the result of the search.
    /// @return A vector of shared pointers to the components that matched the hit function.
    std::vector<std::shared_ptr<structure::Component>> getResult() const;

private:
    /// @brief A function that takes a component and returns true if it is a hit.
    HitFunction _hit_function;
    /// @brief Whether to descend into subcircuits and models.
    bool _descend;
    /// @brief If true, the visitor will stop searching after the first hit.
    bool _terminate_on_hit;
    /// @brief The result of the search.
    std::vector<std::shared_ptr<structure::Component>> _result;
};

/// @brief A visitor that finds a parameter by name.
class FindParameterVisitor : public features::BaseVisitor {
public:
    /// @brief A function type that takes a parameter and returns a boolean indicating if it is a hit.
    using HitFunction = std::function<bool(const std::shared_ptr<structure::Parameter> &)>;

    /// @brief Constructor for FindParameterVisitor.
    /// @param hit_function A function that takes a parameter and returns true if it is a hit.
    /// @param descend Whether to descend into subcircuits and models.
    /// @param terminate_on_hit If true, the visitor will stop searching after the first hit.
    explicit FindParameterVisitor(const HitFunction &hit_function, bool descend = true, bool terminate_on_hit = false);

    int visitParameter(const std::shared_ptr<structure::Parameter> &e) override;

    int visitSubckt(const std::shared_ptr<structure::Subckt> &e) override;

    int visitModel(const std::shared_ptr<structure::Model> &e) override;

    int visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e) override;

    /// @brief Get the result of the search.
    /// @return A vector of shared pointers to the parameters that matched the hit function.
    std::vector<std::shared_ptr<structure::Parameter>> getResult() const;

private:
    /// @brief A function that takes a parameter and returns true if it is a hit.
    HitFunction _hit_function;
    /// @brief Whether to descend into subcircuits and models.
    bool _descend;
    /// @brief If true, the visitor will stop searching after the first hit.
    bool _terminate_on_hit;
    /// @brief The result of the search.
    std::vector<std::shared_ptr<structure::Parameter>> _result;
};

/// @brief A visitor that renames nodes and identifiers in a structure object.
class FindSubcktVisitor : public features::BaseVisitor {
public:
    /// @brief A function type that takes a subcircuit and returns a boolean indicating if it is a hit.
    using HitFunction = std::function<bool(const std::shared_ptr<structure::Subckt> &)>;

    /// @brief Constructor for FindSubcktVisitor.
    /// @param hit_function A function that takes a subcircuit and returns true if it is a hit.
    /// @param descend Whether to descend into subcircuits and models.
    /// @param terminate_on_hit If true, the visitor will stop searching after the first hit.
    explicit FindSubcktVisitor(const HitFunction &hit_function, bool descend = true, bool terminate_on_hit = false);

    int visitSubckt(const std::shared_ptr<structure::Subckt> &e) override;

    int visitModel(const std::shared_ptr<structure::Model> &e) override;

    int visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e) override;

    /// @brief Get the result of the search.
    /// @return A vector of shared pointers to the subcircuits that matched the hit function.
    std::vector<std::shared_ptr<structure::Subckt>> getResult() const;

private:
    /// @brief A function that takes a subcircuit and returns true if it is a hit.
    HitFunction _hit_function;
    /// @brief Whether to descend into subcircuits and models.
    bool _descend;
    /// @brief If true, the visitor will stop searching after the first hit.
    bool _terminate_on_hit;
    /// @brief The result of the search.
    std::vector<std::shared_ptr<structure::Subckt>> _result;
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

/// @brief Find all components with a given master name inside a structure object.
/// @param root The root structure object to search from.
/// @param name The master name of the components to find.
/// @param descend Whether to descend into subcircuits and models.
/// @return A vector of shared pointers to the matching components.
std::vector<std::shared_ptr<edacurry::structure::Component>> find_components_by_master(
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
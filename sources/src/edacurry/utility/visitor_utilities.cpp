/// @file visitor_utilities.cpp
/// @brief
/// @copyright Copyright (c) 2025

#include "edacurry/utility/visitor_utilities.hpp"
#include "edacurry/classes.hpp"

namespace edacurry
{

FindComponentVisitor::FindComponentVisitor(const HitFunction &hit_function, bool descend, bool terminate_on_hit)
    : _hit_function(hit_function), _descend(descend), _terminate_on_hit(terminate_on_hit), _result({})
{
}

int FindComponentVisitor::visitComponent(const std::shared_ptr<structure::Component> &e)
{
    if (_hit_function(e)) {
        _result.push_back(e);
        if (_terminate_on_hit) {
            return 1;
        }
    }
    return 0;
}

int FindComponentVisitor::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitSubckt(e);
}

int FindComponentVisitor::visitModel(const std::shared_ptr<structure::Model> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitModel(e);
}

int FindComponentVisitor::visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitLibraryDef(e);
}

std::vector<std::shared_ptr<structure::Component>> FindComponentVisitor::getResult() const
{
    return _result;
}

FindParameterVisitor::FindParameterVisitor(const HitFunction &hit_function, bool descend, bool terminate_on_hit)
    : _hit_function(hit_function), _descend(descend), _terminate_on_hit(terminate_on_hit), _result({})
{
}

int FindParameterVisitor::visitParameter(const std::shared_ptr<structure::Parameter> &e)
{
    if (_hit_function(e)) {
        _result.push_back(e);
        if (_terminate_on_hit) {
            return 1;
        }
    }
    return 0;
}

int FindParameterVisitor::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitSubckt(e);
}

int FindParameterVisitor::visitModel(const std::shared_ptr<structure::Model> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitModel(e);
}

int FindParameterVisitor::visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitLibraryDef(e);
}

std::vector<std::shared_ptr<structure::Parameter>> FindParameterVisitor::getResult() const
{
    return _result;
}

FindSubcktVisitor::FindSubcktVisitor(const HitFunction &hit_function, bool descend, bool terminate_on_hit)
    : _hit_function(hit_function), _descend(descend), _terminate_on_hit(terminate_on_hit), _result({})
{
}

int FindSubcktVisitor::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    if (_hit_function(e)) {
        _result.push_back(e);
        if (_terminate_on_hit) {
            return 1;
        }
    }
    if (!_descend)
        return 0;
    return BaseVisitor::visitSubckt(e);
}

int FindSubcktVisitor::visitModel(const std::shared_ptr<structure::Model> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitModel(e);
}

int FindSubcktVisitor::visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e)
{
    if (!_descend)
        return 0;
    return BaseVisitor::visitLibraryDef(e);
}

std::vector<std::shared_ptr<structure::Subckt>> FindSubcktVisitor::getResult() const
{
    return _result;
}

RenameNodeVisitor::RenameNodeVisitor(const std::string &old_name, const std::string &new_name)
    : _old_name(old_name), _new_name(new_name)
{
}

int RenameNodeVisitor::visitNode(const std::shared_ptr<structure::Node> &n)
{
    if (n->getName() == _old_name)
        n->setName(_new_name);
    return 0;
}

int RenameNodeVisitor::visitIdentifier(const std::shared_ptr<structure::Identifier> &id)
{
    if (id->getName() == _old_name)
        id->setName(_new_name);
    return 0;
}

std::shared_ptr<edacurry::structure::Component> find_component(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend)
{
    // Create a hit function that checks if the component's name matches the given name.
    auto hit_function = [name](const std::shared_ptr<edacurry::structure::Component> &c) {
        return c->getName() == name;
    };
    // Create the visitor.
    edacurry::FindComponentVisitor visitor(hit_function, descend, true);
    // Visit the root object.
    root->accept(&visitor);
    // Get the result.
    auto result = visitor.getResult();
    // If the result is empty, return nullptr.
    if (result.empty()) {
        return nullptr;
    }
    return result.front();
}

std::vector<std::shared_ptr<edacurry::structure::Component>> find_components_by_master(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend)
{
    // Create a hit function that checks if the component's master name matches the given name.
    auto hit_function = [name](const std::shared_ptr<edacurry::structure::Component> &c) {
        return c->getMaster() == name;
    };
    // Create the visitor.
    edacurry::FindComponentVisitor visitor(hit_function, descend, false);
    // Visit the root object.
    root->accept(&visitor);
    // Return the result.
    return visitor.getResult();
}

std::shared_ptr<edacurry::structure::Parameter> find_parameter(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend)
{
    // Create a hit function that checks if the parameter's name matches the given name.
    auto hit_function = [name](const std::shared_ptr<edacurry::structure::Parameter> &p) {
        // Cast the left hand side to an identifier.
        auto lhs = std::dynamic_pointer_cast<edacurry::structure::Identifier>(p->getLeft());
        // If the left hand side is not an identifier, return false.
        if (!lhs) {
            return false;
        }
        // Check if the identifier's name matches the given name.
        return lhs->getName() == name;
    };
    // Create the visitor.
    edacurry::FindParameterVisitor visitor(hit_function, descend, true);
    // Visit the root object.
    root->accept(&visitor);
    // Get the result.
    auto result = visitor.getResult();
    // If the result is empty, return nullptr.
    if (result.empty()) {
        return nullptr;
    }
    return result.front();
}

std::shared_ptr<structure::Subckt> find_subckt(
    const std::shared_ptr<structure::Object> &root,
    const std::string &name,
    bool descend)
{
    // Create a hit function that checks if the subcircuit's name matches the given name.
    auto hit_function = [name](const std::shared_ptr<structure::Subckt> &s) {
        return s->getName() == name;
    };
    // Create the visitor.
    edacurry::FindSubcktVisitor visitor(hit_function, descend, true);
    // Visit the root object.
    root->accept(&visitor);
    // Get the result.
    auto result = visitor.getResult();
    // If the result is empty, return nullptr.
    if (result.empty()) {
        return nullptr;
    }
    return result.front();
}

void rename_node(
    const std::shared_ptr<structure::Object> &scope,
    const std::string &old_name,
    const std::string &new_name)
{
    edacurry::RenameNodeVisitor visitor(old_name, new_name);
    scope->accept(&visitor);
}

} // namespace edacurry

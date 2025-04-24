/// @file visitor_utilities.cpp
/// @brief
/// @copyright Copyright (c) 2025

#include "edacurry/utility/visitor_utilities.hpp"
#include "edacurry/classes.hpp"

namespace edacurry
{

FindComponentVisitor::FindComponentVisitor(const std::string &target, bool descend)
    : _target(target), _descend(descend), _result(nullptr)
{
}

int FindComponentVisitor::visitComponent(const std::shared_ptr<structure::Component> &e)
{
    if (e->getName() == _target)
        _result = e;
    return 0;
}

int FindComponentVisitor::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    if (!_descend)
        return 0;                       // Stop descent
    return BaseVisitor::visitSubckt(e); // Default recursion
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

std::shared_ptr<structure::Component> FindComponentVisitor::getResult() const
{
    return _result;
}

FindParameterVisitor::FindParameterVisitor(const std::string &target, bool descend)
    : _target(target), _descend(descend), _result(nullptr)
{
}

int FindParameterVisitor::visitParameter(const std::shared_ptr<structure::Parameter> &e)
{
    auto id = std::dynamic_pointer_cast<structure::Identifier>(e->getLeft());
    if (id && id->getName() == _target) {
        _result = e;
        return 1; // Found, stop traversal
    }
    return 0;
}

int FindParameterVisitor::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    if (!_descend)
        return 0;                       // Stop descent
    return BaseVisitor::visitSubckt(e); // Default recursion
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

std::shared_ptr<structure::Parameter> FindParameterVisitor::getResult() const
{
    return _result;
}

FindSubcktVisitor::FindSubcktVisitor(const std::string &target, bool descend)
    : _target(target), _descend(descend), _result(nullptr)
{
}

int FindSubcktVisitor::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    if (e->getName() == _target) {
        _result = e;
        return 1;
    }
    if (_descend)
        return BaseVisitor::visitSubckt(e);
    return 0;
}

std::shared_ptr<structure::Subckt> FindSubcktVisitor::getResult() const
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
    edacurry::FindComponentVisitor visitor(name, descend);
    root->accept(&visitor);
    return visitor.getResult();
}

std::shared_ptr<edacurry::structure::Parameter> find_parameter(
    const std::shared_ptr<edacurry::structure::Object> &root,
    const std::string &name,
    bool descend)
{
    edacurry::FindParameterVisitor visitor(name, descend);
    root->accept(&visitor);
    return visitor.getResult();
}

std::shared_ptr<structure::Subckt> find_subckt(
    const std::shared_ptr<structure::Object> &root,
    const std::string &name,
    bool descend)
{
    edacurry::FindSubcktVisitor visitor(name, descend);
    root->accept(&visitor);
    return visitor.getResult();
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

/// @file   component.cpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#include "edacurry/structure/component.hpp"
#include "edacurry/utility/logging.hpp"
#include "edacurry/utility/utility.hpp"
#include "edacurry/utility/visitor_utilities.hpp"
#include "edacurry/classes.hpp"

namespace edacurry::structure
{
Component::Component(const std::string &name, const std::string &master)
    : Object(),
      features::NamedObject(name),
      nodes(this->weak_from_this()),
      parameters(this->weak_from_this()),
      _master(utility::trim(master))
{
    // Nothing to do.
}

void Component::setMaster(const std::string &master)
{
    _master = utility::trim(master);
}

std::string Component::getMaster() const
{
    return _master;
}

bool Component::matchMaster(const std::string &master) const
{
    return _master == master;
}

std::shared_ptr<Parameter> Component::findParameter(const std::string &name) const
{
    return edacurry::find_parameter(std::const_pointer_cast<Object>(shared_from_this()), name, false);
}

std::shared_ptr<Parameter> Component::setParameter(
    const std::string &name,
    const std::shared_ptr<Value> &right,
    ParameterType type,
    bool hide_name)
{
    // Search for an existing parameter with the same left-hand name.
    for (const auto &param : parameters) {
        auto left = std::dynamic_pointer_cast<Identifier>(param->getLeft());
        if (left && left->getName() == name) {
            param->setRight(right);
            param->setType(type);
            param->setHideName(hide_name);
            return param;
        }
    }
    // Create the left-hand side identifier.
    auto left = std::make_shared<Identifier>(name);
    // Create the new parameter.
    auto param = std::make_shared<Parameter>(left, right, type, hide_name);
    parameters.push_back(param);
    return param;
}

std::string Component::toString() const
{
    std::stringstream ss;
    ss << "(component `" << this->getName() << "` `" << _master << "` " << nodes.toString() << " " << parameters.toString() << ")";
    return ss.str();
}
} // namespace edacurry::structure
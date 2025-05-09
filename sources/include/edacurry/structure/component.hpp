/// @file   component.hpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#pragma once

#include "edacurry/features/named_object.hpp"
#include "parameter.hpp"
#include "object.hpp"
#include "node.hpp"

namespace edacurry::structure
{
/// @brief Represent a component.
class Component : public Object, public features::NamedObject {
public:
    /// The nodes.
    features::OwnedList<Node> nodes;
    /// The parameters.
    features::OwnedList<Parameter> parameters;

    /// @brief Construct a new Component object.
    /// @param name the name of the component.
    /// @param master the master of the component.
    Component(const std::string &name = std::string(), const std::string &master = std::string());

    /// @brief Destroy the Component object.
    ~Component() override = default;

    /// @brief Sets the name.
    /// @param master the master to be set.
    void setMaster(const std::string &master);

    /// @brief Gets the master.
    /// @return The master.
    std::string getMaster() const;

    /// @brief Checks whether given master is equals to this object master.
    /// @param master The master to check.
    /// @return <tt>True</tt> if names are equals.
    bool matchMaster(const std::string &master) const;

    /// @brief Searches for a parameter by name.
    /// @param name The name of the parameter (left-hand side).
    /// @return A shared pointer to the matching parameter, or nullptr if not found.
    std::shared_ptr<Parameter> findParameter(const std::string &name) const;

    /// @brief Adds or updates a parameter by name.
    /// @param name The name of the parameter (left-hand side).
    /// @param right The right-hand value of the parameter.
    /// @param type The type of the parameter.
    /// @param hide_name Whether to hide the name during code generation.
    /// @return The pointer to the parameter (created or updated).
    std::shared_ptr<Parameter> setParameter(
        const std::string &name,
        const std::shared_ptr<Value> &right,
        ParameterType type = ParameterType::param_assign,
        bool hide_name     = false);

    /// @brief Provides a string representation of the object for **debugging** purposes.
    /// @return the string representation.
    std::string toString() const override;

    /// @brief Accepts a visitor.
    /// @param visitor the visitor.
    inline int accept(features::Visitor *visitor) override
    {
        return visitor->visitComponent(std::static_pointer_cast<Component>(this->shared_from_this()));
    }

private:
    /// The name of the master.
    std::string _master;
};

} // namespace edacurry::structure
/// @file   analysis.hpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#pragma once

#include "parameter.hpp"
#include "object.hpp"

namespace edacurry::structure
{
/// @brief Represent a analysis.
class Analysis : public Object, public features::NamedObject {
public:
    /// The parameters of the analysis statement.
    features::OwnedList<Parameter> parameters;

    /// @brief Construct a new analysis object.
    explicit Analysis();

    /// @brief Construct a new analysis object.
    /// @param name   the name (instance name).
    Analysis(const std::string &name);

    /// @brief Construct a new analysis object.
    /// @param name   the name (instance name).
    /// @param type   the analysis type (dc, tran, sp, ac, info, etc.).
    Analysis(const std::string &name, const std::string &type);

    /// @brief Destroy the analysis object.
    ~Analysis() override = default;

    /// @brief Get the analysis type.
    /// @return the analysis type.
    inline const std::string &getType() const { return _type; }

    /// @brief Set the analysis type.
    /// @param type the analysis type.
    inline void setType(const std::string &type) { _type = type; }

    /// @brief Provides a string representation of the object for **debugging** purposes.
    /// @return the string representation.
    std::string toString() const override;

    /// @brief Accepts a visitor.
    /// @param visitor the visitor.
    inline int accept(features::Visitor *visitor) override
    {
        return visitor->visitAnalysis(std::static_pointer_cast<Analysis>(this->shared_from_this()));
    }

private:
    /// The analysis type (dc, tran, sp, ac, info, etc.).
    std::string _type;
};

} // namespace edacurry::structure
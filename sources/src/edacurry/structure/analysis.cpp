/// @file   analysis.cpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// @copyright Copyright (c) 2025 Electronic Systems Design (ESD) Laboratory, University of Verona
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#include "edacurry/structure/analysis.hpp"
#include "edacurry/utility/logging.hpp"
#include "edacurry/utility/utility.hpp"
#include <sstream>

namespace edacurry::structure
{
Analysis::Analysis()
    : Object(),
      features::NamedObject(),
      parameters(this->weak_from_this()),
      content(this->weak_from_this()),
      _type()
{
    // Nothing to do.
}

Analysis::Analysis(const std::string &name)
    : Object(),
      features::NamedObject(name),
      parameters(this->weak_from_this()),
      content(this->weak_from_this()),
      _type()
{
    // Nothing to do.
}

Analysis::Analysis(const std::string &name, const std::string &type)
    : Object(),
      features::NamedObject(name),
      parameters(this->weak_from_this()),
      content(this->weak_from_this()),
      _type(type)
{
    // Nothing to do.
}

std::string Analysis::toString() const
{
    std::stringstream ss;
    ss << "(analysis `" << this->getName() << "` `" << _type << "` " << parameters.toString();
    if (content.size() > 0) {
        ss << " [" << content.size() << " nested]";
    }
    ss << ")";
    return ss.str();
}
} // namespace edacurry::structure
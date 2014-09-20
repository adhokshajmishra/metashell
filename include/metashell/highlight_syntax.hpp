#ifndef METASHELL_HIGHLIGHT_SYNTAX_HPP
#define METASHELL_HIGHLIGHT_SYNTAX_HPP

// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Andras Kucsma (andras.kucsma@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <metashell/token.hpp>
#include <metashell/colored_string.hpp>

namespace metashell {

colored_string::color_t color_of_token(const token& t);

colored_string highlight_syntax(const std::string& s);

void display_syntax_highlighted(const token& t);

}

#endif
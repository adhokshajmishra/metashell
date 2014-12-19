#ifndef METASHELL_LINE_READER_HPP
#define METASHELL_LINE_READER_HPP

// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/command_processor_queue.hpp>
#include <metashell/iface/displayer.hpp>

#include <boost/optional.hpp>

#include <string>
#include <functional>

namespace metashell
{
  typedef
    std::function<boost::optional<std::string>(const std::string&)>
    line_reader;

  void input_loop(
    command_processor_queue& processor_queue_,
    iface::displayer& displayer_,
    const line_reader& line_reader_
  );
}

#endif


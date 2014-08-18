#ifndef METASHELL_PRAGMA_HANDLER_HPP
#define METASHELL_PRAGMA_HANDLER_HPP

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

#include <metashell/pragma_handler_interface.hpp>
#include <metashell/command.hpp>

#include <boost/scoped_ptr.hpp>

namespace metashell
{
  class pragma_handler
  {
  public:
    template <class Impl>
      // requires: Impl publicly inherits from pragma_handler_interface
    pragma_handler(Impl impl_) : _body(new Impl(impl_)) {}

    pragma_handler(const pragma_handler& h_);
    pragma_handler& operator=(pragma_handler h_);

    void swap(pragma_handler& h_);

    std::string arguments() const;
    std::string description() const;

    void run(
      const command::iterator& args_begin_,
      const command::iterator& args_end_
    ) const;
  private:
    boost::scoped_ptr<pragma_handler_interface> _body;
  };
}

#endif


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

#include <metashell/in_memory_displayer.hpp>
#include <metashell/metashell_pragma.hpp>
#include <metashell/pragma_handler.hpp>
#include <metashell/pragma_switch.hpp>

#include <gtest/gtest.h>

using namespace metashell;

namespace
{
  template <bool B>
  bool always()
  {
    return B;
  }

  template <bool ExpectedResult>
  void test_callback_is_called(const std::string& arg_)
  {
    bool was_called = false;
    bool arg = !ExpectedResult;
    in_memory_displayer d;

    pragma_switch p("test", always<true>, [&was_called, &arg](bool value_) {
      was_called = true;
      arg = value_;
    });
    run(p, data::cpp_code(arg_), d);

    ASSERT_TRUE(was_called);
    ASSERT_EQ(ExpectedResult, arg);
  }
}

TEST(pragma_switch, calls_updating_callback)
{
  test_callback_is_called<true>("on");
  test_callback_is_called<true>("1");

  test_callback_is_called<false>("off");
  test_callback_is_called<false>("0");
}

TEST(pragma_switch, displays_error_when_extra_arguments_are_given)
{
  in_memory_displayer d;

  pragma_switch p("test", always<true>, [](bool) {});
  run(p, data::cpp_code("on foo"), d);

  ASSERT_FALSE(d.errors().empty());
}

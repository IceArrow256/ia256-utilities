#pragma once
#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include <array>
#include <cstdio>
#include <exception>
#include <iostream>
#include <memory>
#include <string>

namespace ia256 {
  std::string exec(std::string const &input, bool no_new_line=true, bool is_ret=true);
}

#endif /* !__SYSTEM_HPP__ */

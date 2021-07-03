#include <ia256-utilities/system.hpp>

std::string ia256::exec(std::string const &input, bool no_new_line, bool is_ret) {
  std::array<char, 128> buffer;
  std::string result = "";
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(input.c_str(), "r"),
                                                pclose);
  if (!pipe) {
    throw std::runtime_error("exec popen() failed!");
  }
  if (is_ret) {
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
      result += buffer.data();
    }
  }
  if (no_new_line){
    result.pop_back();
  }
  return result;
}

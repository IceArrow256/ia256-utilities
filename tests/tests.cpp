#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ia256-utilities/system.hpp>

#ifdef __linux__
TEST_CASE("exec - done", "[exec]") { REQUIRE(exec("uname") == "Linux\n"); }
#endif
#ifdef _WIN32
#endif

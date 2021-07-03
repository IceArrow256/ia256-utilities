#include <filesystem>
#define CATCH_CONFIG_MAIN
#include <filesystem>

#include <catch2/catch.hpp>

#include <ia256-utilities/system.hpp>
#include <ia256-utilities/dirs.hpp>

#ifdef __linux__
TEST_CASE("exec - done", "[exec]") { REQUIRE(ia256::exec("uname") == "Linux\n"); }
TEST_CASE("get_home - done", "[get_home]") { REQUIRE(ia256::dirs().get_home() == std::filesystem::path("/home/main")); }
TEST_CASE("get_pictures_dir - done", "[get_pictures_dir]") { REQUIRE(ia256::dirs().get_pictures_dir() == std::filesystem::path("/home/main/Pictures")); }
#endif
#ifdef _WIN32
#endif

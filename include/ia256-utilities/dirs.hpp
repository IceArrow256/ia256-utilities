#pragma once
#ifndef __DIRS_HPP__
#define __DIRS_HPP__

#include <filesystem>
#include <fstream>
#include <map>
#include <string>

namespace ia256 {
class dirs {
public:
  dirs();

  std::filesystem::path get_home();
  std::filesystem::path get_config_dir();
  std::filesystem::path get_desktop_dir();
  std::filesystem::path get_downloads_dir();
  std::filesystem::path get_templates_dir();
  std::filesystem::path get_public_dir();
  std::filesystem::path get_documents_dir();
  std::filesystem::path get_music_dir();
  std::filesystem::path get_pictures_dir();
  std::filesystem::path get_videos_dir();

private:
  std::map<std::string, std::filesystem::path> user_dirs;
};
} // namespace ia256

#endif /* !__DIRS_HPP__ */

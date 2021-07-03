#include <ia256-utilities/dirs.hpp>

ia256::dirs::dirs() {
  std::ifstream user_dirs(this->get_config_dir() / "user-dirs.dirs");
  std::string line;
  while (std::getline(user_dirs, line)) {
    if (line.length() == 0 || line.at(0) == '#' ||
        line.substr(0, 4) != "XDG_") {
      continue;
    }
    std::size_t split_pos = line.find('=');
    std::string key = line.substr(0, split_pos);
    std::string value = line.substr(split_pos + 1 + 7);
    value.pop_back();
    this->user_dirs[key] = this->get_home() / value;
  }
}

std::filesystem::path ia256::dirs::get_home() {
  return std::filesystem::path(std::getenv("HOME"));
}

std::filesystem::path ia256::dirs::get_config_dir() {
  return this->get_home() / ".config";
}

std::filesystem::path ia256::dirs::get_desktop_dir() {
  return this->user_dirs["XDG_DESKTOP_DIR"];
}

std::filesystem::path ia256::dirs::get_downloads_dir() {
  return this->user_dirs["XDG_DOWNLOAD_DIR"];
}

std::filesystem::path ia256::dirs::get_templates_dir() {
  return this->user_dirs["XDG_TEMPLATES_DIR"];
}

std::filesystem::path ia256::dirs::get_public_dir() {
  return this->user_dirs["XDG_PUBLICSHARE_DIR"];
}

std::filesystem::path ia256::dirs::get_documents_dir() {
  return this->user_dirs["XDG_DOCUMENTS_DIR"];
}

std::filesystem::path ia256::dirs::get_music_dir() {
  return this->user_dirs["XDG_MUSIC_DIR"];
}

std::filesystem::path ia256::dirs::get_pictures_dir() {
  return this->user_dirs["XDG_VIDEOS_DIR"];
}

std::filesystem::path ia256::dirs::get_videos_dir() {
  return this->user_dirs["XDG_PICTURES_DIR"];
}

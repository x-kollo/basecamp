#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <mutex>
#include <string>

static int active_threads = 0;
void search(const std::filesystem::path & home_path, const std::string & file);
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Not enough arguments\n";
    return 1;
  }
  const std::string pathFile = argv[2];
  const std::string pattern = argv[1];

  std::ifstream file(pathFile, std::ios::in);

  if (!file.is_open()) {
    std::cout << "File not found\n";
    return 2;
  }

  std::string line;
  while (std::getline(file, line)) {
    // TODO
    // tellg() gets the last buffer of the line
    // make the grep algorithm
  }
  file.close();
  return 0;
}

#include <fstream>
#include <iostream>

bool findPattern(std::string text, std::string pattern) {
  int patternIndex = 0;
  for (int index = 0; index < text.size(); index++) {
    if (text[index] == pattern[patternIndex]) {
      patternIndex++;
    } else {
      patternIndex = 0;
    }

    if (patternIndex == pattern.size() - 1) {
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Not enough arguments\n" << "[PATTERN] [FILE]";
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
  int line_position = 1;
  while (std::getline(file, line)) {
    // TODO
    // tellg() gets the last buffer of the line
    // make the grep algorithm
    if (findPattern(line, pattern)) {
      std::cout << line_position << " " << line << "\n";
    }
    line_position++;
  }
  file.close();
  return 0;
}

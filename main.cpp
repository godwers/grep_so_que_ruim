#include <fstream>
#include <iostream>

#define COOL_COLOR "\033[4;31m"
#define RESET_COLOR "\033[0m"

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

void prettyPrint(std::string text, std::string pattern, int linePosition) {
  std::string prettyText = "";
  const int last = pattern.size() - 1;
  int lastIndex = 0;
  for (int index = 0; index < text.size(); index++) {
    if (text[index] == pattern[0] &&
        text.substr(index, pattern.size()) == pattern) {
      prettyText += COOL_COLOR;
      lastIndex = index;
    }

    prettyText += text[index];
    if (text[index] == pattern[last] &&
        index - lastIndex == pattern.size() - 1) {
      prettyText += RESET_COLOR;
    }
  }
  std::cout << linePosition << " " << prettyText << "\n";
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
    return -1;
  }

  std::string line;
  int line_position = 1;
  while (std::getline(file, line)) {
    if (findPattern(line, pattern)) {
      prettyPrint(line, pattern, line_position);
    }
    line_position++;
  }
  file.close();
  return 0;
}

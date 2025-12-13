#include <fstream>
#include <iostream>

#define COOL_COLOR "\033[4;31m"
#define RESET_COLOR "\e[0m"

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
void prettyPrint(std::string text, std::string highlightChoice,
                 int linePosition) {
  std::string prettyText = "";
  int lastPosition = text.size();
  for (int index = 0; index < text.size(); index++) {
    std::cout << prettyText << "\n";
    int otherIndex = 0;

    if (index == lastPosition) {
      prettyText += RESET_COLOR;
      continue;
    }

    if (text[index] != highlightChoice[0]) {
      prettyText += text[index];
      continue;
    }

    while (otherIndex < highlightChoice.size()) {
      lastPosition = 0;
      if (text[index] != highlightChoice[otherIndex]) {
        printf("quebrou");
        break;
      }
      if (otherIndex == highlightChoice.size() - 1) {
        prettyText += COOL_COLOR;
        prettyText += text[index];
        lastPosition = index + otherIndex;
      }
      otherIndex++;
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

#include <fstream>
#include <iostream>
#include <cstdint>

#define PATTERN_COLOR "\033[4;31m"
#define RESET_COLOR "\033[0m"

bool findPattern(std::string text, std::string pattern) {
  uint32_t patternIndex = 0;
  for (uint32_t index = 0; index < text.size(); index++) {
    if (text[index] == pattern[patternIndex]) {
      patternIndex++;
    } else {
      patternIndex = 0;
    }

    if (patternIndex == pattern.size()) {
      return true;
    }
  }
  return false;
}

void prettyPrint(std::string text, 
		std::string pattern, 
		int linePosition) 
{
  std::string prettyText = "";
  const uint32_t last = pattern.size() - 1;
  uint32_t lastIndex = 0;
  for (uint32_t index = 0; index < text.size(); index++) {
    if (text[index] == pattern[0] &&
        text.substr(index, pattern.size()) == pattern) {
      prettyText.append(PATTERN_COLOR);
      lastIndex = index;
    }

    prettyText += text[index];
    if (text[index] == pattern[last] &&
        index - lastIndex == pattern.size() - 1) {
      prettyText.append(RESET_COLOR);
    }
  }
  std::cout << linePosition << " " << prettyText << "\n";
}

int main(const int argc, const char **argv) {
  if (argc < 3) {
    printf("Not enough arguments\n[PATTERN] [FILE]");
    return 1;
  }
  const char *pathFile = argv[2];
  const std::string pattern = argv[1];

  std::ifstream file(pathFile, std::ios::in);

  if (!file.is_open()) {
	printf("File %s not found\n", pathFile);
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

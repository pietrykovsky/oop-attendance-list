#include "functions.h"

std::string normalize(std::string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word[i] >= 65 && word[i] <= 90)
			word[i] += 32;
	}
	return word;
}
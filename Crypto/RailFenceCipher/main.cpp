#include <iostream>
#include <string_view>

std::string rail_fence_encipher(std::string message, int32_t rails);

int32_t rail_number(int32_t pos, int32_t rails);

int main() {
	std::string message = "we are discovered";
	int32_t key = 3;
	std::string cipher = rail_fence_encipher(message, key);
	std::cout << cipher << '\n';
	return 0;
}

std::string rail_fence_encipher(std::string message, int32_t rails) {
	std::string cipher;
	cipher.reserve(message.length());
	for (int32_t i = 0; i < rails; ++i) {
		for (int32_t j = 0; j < message.length(); ++j)
			if (rail_number(j, rails) == i)
				cipher.push_back(message[j]);
	}
	return cipher;
}

int32_t rail_number(int32_t pos, int32_t rails) {
	/**
	 * Note that the period for a given number of rails is 2*n - 1.
	 * However, since the array indexing starts at 0 we need to compensate for it by
	 * subtracting an extra 1. Mathematically pos = pos mod(period); where period = 2*rails - 1
	 */
	pos = pos % (2 * rails - 2);
	if (pos < rails)
		return pos;
	return (2 * rails) - pos - 2;
}

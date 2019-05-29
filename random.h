#pragma once
#include <random>

namespace astro
{
	inline int random(int min, int max)
	{
		std::random_device random_device;
		std::mt19937 random_engine(random_device());

		std::uniform_int_distribution<int> generator(min, max);

		return generator(random_engine);
	}

	/*inline float random(float min, float max)
	{
		return (rand() / float(RAND_MAX)) *(max - min) + min;
	}*/

	/*inline int random(int min, int max)
	{
		return rand() % max + min;
	}*/
}

#pragma once
namespace Tools {
	template<typename T>
	inline T clamp(T max, T min, T origin) {
		if (origin < min)
			return min;
		if (origin > max)
			return max;
		return origin;
	}
}
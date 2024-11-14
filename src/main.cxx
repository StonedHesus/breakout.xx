#include <iostream>
#include <cmath>
#include <optional>


class Paddle {
	private:
		double x;
		double y;
		double width{20.0};
		double height{5.0};
		std::optional<int> durability{std::nullopt};// By default, the standard paddle never breaks, but fancy ones will
	public:
		Paddle() noexcept = default;
		Paddle(double x, double y) : x{x}, y{y} {}
		~Paddle() = default;

	friend std::ostream& operator<<(std::ostream& os, const Paddle& paddle) {
		os << "Paddle[x=" << paddle.x << ", y=" << paddle.y
			<< ", width=" << paddle.width << ", height=" << paddle.height;
		if (paddle.durability) {
			os << ", durability=" << *paddle.durability;
		} else {
			os << ", standard paddle (unbreakable)";
		}
		os << "]";
		return os;
	}
};

int main(void) {
	auto p = new Paddle(2.4, 3.7);
	std::cout << *p;
	delete p;
	return EXIT_SUCCESS;
}

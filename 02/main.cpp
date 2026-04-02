#include <matplot/matplot.h>

#define E 2.71828182

float func(const float N, const float b, float t) {
    return N * (1 - std::pow(E, - (b * t)));
}

int main() {
    using namespace matplot;

    const float N = 100;
    const float b = 0.1;

    std::vector<double> x = linspace(0, 100);
    std::vector<double> y = transform(x, [=](auto x) { return func(N, b, x); });
    std::vector<size_t> control = {5, 10, 20, 50};

    for (auto num : control) {
        std::cout << func(N, b, num) << "\n";
    }

    plot(x, y, "-o")->marker_indices(control);

    show();

    return 0;
}

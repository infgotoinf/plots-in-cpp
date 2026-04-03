#include <matplot/matplot.h>

#define E 2.71828182

float func(const float lambda, const float b, int repeat) {
    if (repeat > 0)
        return func(lambda * b, b, repeat - 1);
    return lambda;
}

int main() {
    using namespace matplot;

    const float lambda = 0.8;

    const float b1 = 0.8;
    const float b2 = 0.9;

    std::vector<double> x = linspace(0, 100);
    std::vector<double> y1 = transform(x, [=](auto x) { return func(lambda, b1, x); });
    std::vector<double> y2 = transform(x, [=](auto x) { return func(lambda, b2, x); });
    std::vector<double> y3 = transform(x, [=](auto x) { return 0.8; });

    plot(x, y1, x, y2, x, y3);
    // grid(on);
    // gca()->minor_grid(true);

    show();

    return 0;
}

#include <matplot/matplot.h>

float func(const float N, const float b, float n) {
    return b * (N - n);
}

int main() {
    using namespace matplot;

    const float N = 100;
    const float b = 0.1;

    std::vector<double> x = linspace(10, 100, 10);
    std::vector<double> y = transform(x, [=](auto x) { return func(N, b, x); });

    figure();
    stairs(y);

    show();

    return 0;
}

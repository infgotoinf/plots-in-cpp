#include <matplot/matplot.h>

#define E 2.71828182

float func(const float N, const float F, int i) {
    return F * (N - (i - 1));
}

float func2(float N, const float F, int i) {
    if (i > 5) ++N;
    return F * (N - (i - 1));
}

int main() {
    using namespace matplot;

    const float N = 10;

    const float F = 0.2;

    std::array<double, 2> x = {1, 10};
    hold(on);
    fplot([=](auto x) { return func(N, F, x); }
         , x)->line_width(2);

    fplot([=](auto x) { return func2(N, F, x); }
         , x, "--")->line_width(2);
    hold(off);

    ::matplot::legend({"lambda i", "with a new error on step 5"});
    ylabel("Number of fixed bugs");
    xlabel("Intensity of errors");

    // grid(on);
    show();

    return 0;
}

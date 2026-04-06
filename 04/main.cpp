#include <matplot/matplot.h>

#define E 2.71828182

float func(const float N, const float b, double t) {
    return N * (1 - std::pow(E, - (b * t)));
}

int main() {
    using namespace matplot;

    const float N = 150;

    const float b = 0.05;

    std::array<double, 2> x = {0, 100};
    fplot([=](auto x) { return func(N, b, x); }
         , x, "-o")->line_width(2);

    hold(on);
    fplot([=](auto x) { return func(N, b * 2, x); }
         , x, "-o")->line_width(2);

    fplot([=](auto x) { return 135; }
         , x, "-o")->line_width(2);

    hold(off);

    // ::matplot::legend({"b", "2b", "135"});
    ylabel("Nuber of fixed bugs (m)");
    xlabel("Time (t)");

    // auto ax = gca();

    // int font_size = 20;
    // ax->y_axis().label_font_size(font_size);
    // ax->y_axis().label_weight("bold");
    // ax->x_axis().label_font_size(font_size);
    // ax->x_axis().label_weight("bold");

    grid(on);
    show();

    return 0;
}

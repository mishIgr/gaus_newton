#include <iostream>
#include "choleskysolver.hpp"
#include "integrate.hpp"
#include "matrix_csv_file_loader.hpp"
#include "noise.hpp"
#include "param.hpp"
#include "inverse_problem.hpp"

int main() {
    double k1 = 2.0, k2 = 1.0, m1 = 0.6, m2 = 3.0, l1 = 3.0, l2 = 3.0;
    double h = 0.01;
    double x1 = 1, v1 = -20.0, x2 = 10.2, v2 = 20.0;
    double std_dev = 0.1;
    size_t iter_num = 300;

    Matrix state = create_param({x1, v1, x2, v2});
    Matrix param = create_const_param_for_integrate(k1, k2, m1, m2, l1, l2);

    Matrix states(iter_num, 4);

    for (int i = 0; i < iter_num; ++i) {
        states.subscribe_row(i, state);
        state = dormand_prince(std::function<Matrix(const Matrix&, const Matrix&)>(
                                    compute_derivatives
                                ), state, param, h);
    }

    MatrixCSVWriter("plots/csv_data/integrate_data.csv").set_headers({"x1", "v1", "x2", "v2"}) << states;

    generate_noise(states, std_dev);

    MatrixCSVWriter("plots/csv_data/noise_data.csv").set_headers({"x1", "v1", "x2", "v2"}) << states;


    x1 = states(0, 0), v1 = states(0, 1), x2 = states(0, 2), v2 = states(0, 3), m1 = 2.0;
    iter_num = 100000;
    state = create_param({x1, v1, x2, v2, m1});
    param = create_const_param_for_integrate(k1, k2, -1000, m2, l1, l2);
    InverseProblem solver;
    solver.set_data(states).set_W(1 / (std_dev * std_dev)).set_param(param);

    for (int i = 0; i < iter_num; ++i) {
        state = solver.solve(state, h);
        std::cout << state << std::endl;
    }

    return 0;
}

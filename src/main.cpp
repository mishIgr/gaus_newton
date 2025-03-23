#include <iostream>
#include "choleskysolver.hpp"
#include "integrate.hpp"
#include "matrix_csv_file_loader.hpp"

int main() {
    double k1 = 1.0, k2 = 1.0, m1 = 1.0, m2 = 1.0, l1 = 1.0, l2 = 1.0;
    double h = 0.005;

    Matrix state(4, 1);
    state(0, 0) = 0.4; // x1
    state(1, 0) = 0.0; // v1
    state(2, 0) = 2.1; // x2
    state(3, 0) = 0.0; // v2

    Matrix states(10000, 4);

    for (int i = 0; i < 10000; ++i) {
        states.subscribe_row(i, state);
        state = dormandPrince8(state, h, k1, k2, m1, m2, l1, l2);
        // std::cout << "Step " << i << ": \n" << state << std::endl;
    }

    #ifdef PROJECT_SOURCE_DIR
        std::string project_dir = PROJECT_SOURCE_DIR;
        MatrixCSVWriter(project_dir + "/plots/csv_data/tmp.csv").set_headers({"x1", "v1", "x2", "v2"}) << states;
    #else
        #warning "Макрос PROJECT_SOURCE_DIR не определен"
    #endif

    return 0;
}

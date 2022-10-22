#include <iostream>
#include <fstream>
#include <numbers>
#include <vector>
#include <tuple>

using std::vector;

std::tuple<vector<double>, vector<double>> RK4(double start, double end, int steps, double init_x, double init_p)
{
    double k0, k1, k2, k3;
    double l0, l1, l2, l3;
    double h = (end - start)/steps;
    double x_next;
    double y_next;
    std::vector<double> x;
    std::vector<double> y;
    x.push_back(init_x);
    y.push_back(init_p);

    for(long i = 0; i < steps; i++)
    {
        k0 = h * y[i];
        l0 = -1 * h * x[i];

        k1 = h * (y[i] + k0/2);
        l1 = h * (-1) * (x[i] + h/2);

        k2 = h * (y[i] + k1/2);
        l2 = h * (-1) * (x[i] + h/2);

        k3 = h * (y[i] + k2);
        l3 = h * (-1) * (x[i] + h);

        x_next = x[i] + (1.0/6.0 * (k0 + 2*k1 + 2*k2 + k3));
        y_next = y[i] + (1.0/6.0 * (l0 + 2*l1 + 2*l2 + l3));

        x.push_back(x_next);
        y.push_back(y_next);
    }
    
    return std::make_tuple(x, y);
}
int main(void)
{
    int N;
    double start, end;
    double init_x, init_p;
    std::cout << "Enter number of iterations: ";
    std::cin >> N;
    std::cout << "Enter start, stop time(seconds): ";
    std::cin >> start >> end;
    std::cout << "Enter init conditions(x,p): ";
    std::cin >> init_x >> init_p;
    std::tuple<vector<double>, vector<double>> result = RK4(start, 2 * std::numbers::pi * end, N, init_x, init_p );
    std::cout << "Results found! Writing to CSV";
    std::ofstream outfile;
    outfile.open("results.csv");

    vector<double> x = std::move(std::get<0>(result));
    vector<double> y = std::move(std::get<1>(result));
    outfile << "position,momentum" <<std::endl;
    for(long i = 0; i < x.size(); i++)
    {
        outfile << x[i] << "," << y[i] << std::endl;
    }
    outfile.close();
    return 0;
}
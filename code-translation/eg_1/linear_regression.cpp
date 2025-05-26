/*translate the following python implementation to c++:
#write a python numpy code to perform linear regression on a dataset
import numpy as np
import matplotlib.pyplot as plt
def linear_regression(X, y):
    # Add a bias term (intercept) to the input features
    X_b = np.c_[np.ones((X.shape[0], 1)), X]
    # Calculate the optimal parameters using the Normal Equation
    theta_best = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)
    return theta_best
def predict(X, theta):
    # Add a bias term to the input features
    X_b = np.c_[np.ones((X.shape[0], 1)), X]
    return X_b.dot(theta)

# Example usage
if __name__ == "__main__":
    # Generate some synthetic data
    np.random.seed(42)
    X = 2 * np.random.rand(100, 1)
    y = 4 + 3 * X + np.random.randn(100, 1)
    # Perform linear regression
    theta_best = linear_regression(X, y)
    print("Optimal parameters (theta):", theta_best)
    # Make predictions
    X_new = np.array([[0], [2]])
    y_predict = predict(X_new, theta_best)
    print("Predictions:", y_predict)
    # Plot the results
    plt.plot(X, y, "b.")
    plt.plot(X_new, y_predict, "r-")
    plt.xlabel("X")
    plt.ylabel("y")
    plt.title("Linear Regression using Numpy")
    plt.axis([0, 2, 0, 15])
    plt.show()
# This code performs linear regression using numpy and visualizes the results.
# It generates synthetic data, computes the optimal parameters using the Normal Equation,
# makes predictions, and plots the original data along with the regression line.
# The output will show the optimal parameters and the predictions for new input values.
# The plot will display the data points and the fitted line.
*/
#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <random>
#include <matplotlibcpp.h>
namespace plt = matplotlibcpp;
using namespace Eigen;
// Function to perform linear regression
VectorXd linear_regression(const MatrixXd& X, const VectorXd& y) {
    // Add a bias term (intercept) to the input features
    MatrixXd X_b(X.rows(), X.cols() + 1);
    X_b << VectorXd::Ones(X.rows()), X;
    // Calculate the optimal parameters using the Normal Equation
    VectorXd theta_best = (X_b.transpose() * X_b).inverse() * X_b.transpose() * y;
    return theta_best;
}
// Function to make predictions
VectorXd predict(const MatrixXd& X, const VectorXd& theta) {
    // Add a bias term to the input features
    MatrixXd X_b(X.rows(), X.cols() + 1);
    X_b << VectorXd::Ones(X.rows()), X;
    return X_b * theta;
}
// Main function to demonstrate linear regression
int main() {
    // Generate some synthetic data
    std::mt19937 gen(42); // Random number generator with a fixed seed
    std::uniform_real_distribution<double> dist(0, 2);
    MatrixXd X(100, 1);
    VectorXd y(100);
    
    for (int i = 0; i < 100; ++i) {
        X(i, 0) = dist(gen);
        y(i) = 4 + 3 * X(i, 0) + std::normal_distribution<double>(0, 1)(gen);
    }

    // Perform linear regression
    VectorXd theta_best = linear_regression(X, y);
    std::cout << "Optimal parameters (theta):\n" << theta_best << std::endl;

    // Make predictions
    MatrixXd X_new(2, 1);
    X_new << 0, 2;
    VectorXd y_predict = predict(X_new, theta_best);
    std::cout << "Predictions:\n" << y_predict << std::endl;

    // Plot the results
    plt::scatter(X.col(0), y);
    plt::plot(X_new.col(0), y_predict, "r-");
    plt::xlabel("X");
    plt::ylabel("y");
    plt::title("Linear Regression using Eigen");
    plt::axis({0, 2, 0, 15});
    plt::show();

    return 0;
}
// This C++ code performs linear regression using the Eigen library for matrix operations
// and matplotlibcpp for plotting. It generates synthetic data, computes the optimal parameters
// using the Normal Equation, makes predictions, and visualizes the results.
// The output will show the optimal parameters and the predictions for new input values.
// The plot will display the data points and the fitted line.
// Make sure to link against the Eigen library and matplotlibcpp when compiling this code.
// To compile this code, you need to have the Eigen library and matplotlibcpp installed.
// You can compile it using a command like:
// g++ linear_regression.cpp -o linear_regression -I /path/to/eigen -I /path/to/matplotlibcpp
// Make sure to replace /path/to/eigen and /path/to/matplotlibcpp with the actual paths to the libraries.
// This code requires the Eigen library for matrix operations and matplotlibcpp for plotting.
// Ensure you have the necessary libraries installed and linked correctly.
// The Eigen library can be downloaded from http://eigen.tuxfamily.org/.

// The matplotlibcpp can be found at      
/*include the download link for matplotlibcpp*/
//     
          
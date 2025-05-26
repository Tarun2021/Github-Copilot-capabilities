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

    Use bits/stdc++.h as the header file */
#include <bits/stdc++.h>
using namespace std;
// Function to perform linear regression
vector<double> linear_regression(const vector<vector<double>>& X, const vector<double>& y) {
    int m = X.size(); // number of samples
    int n = X[0].size(); // number of features

    // Add a bias term (intercept) to the input features
    vector<vector<double>> X_b(m, vector<double>(n + 1, 1.0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            X_b[i][j + 1] = X[i][j];
        }
    }

    // Calculate the optimal parameters using the Normal Equation
    vector<vector<double>> Xt(n + 1, vector<double>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            Xt[j][i] = X_b[i][j];
        }
    }

    vector<vector<double>> XtX(n + 1, vector<double>(n + 1, 0.0));
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            for (int k = 0; k < m; ++k) {
                XtX[i][j] += Xt[i][k] * X_b[k][j];
            }
        }
    }

    vector<double> XtY(n + 1, 0.0);
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            XtY[i] += Xt[i][j] * y[j];
        }
    }

    // Solve the linear system using Gaussian elimination
    vector<double> theta(n + 1, 0.0);
    for (int i = 0; i < n + 1; ++i) {
        double pivot = XtX[i][i];
        for (int j = i + 1; j < n + 1; ++j) {
            double factor = XtX[j][i] / pivot;
            for (int k = i; k < n
    + 1; ++k) {
                    XtX[j][k] -= factor * XtX[i][k];
                }
            XtY[j] -= factor * XtY[i];
        }
        theta[i] = XtY[i] / pivot;
    }
    for (int i = n; i >= 0; --i) {
        for (int j = i + 1; j < n + 1; ++j) {
            theta[i] -= XtX[i][j] * theta[j];
        }
    }
    return theta;
}
// Function to make predictions
vector<double> predict(const vector<vector<double>>& X, const vector<double>& theta) {
    int m = X.size(); // number of samples
    int n = X[0].size(); // number of features

    // Add a bias term to the input features
    vector<vector<double>> X_b(m, vector<double>(n + 1, 1.0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            X_b[i][j + 1] = X[i][j];
        }
    }

    vector<double> predictions(m, 0.0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            predictions[i] += X_b[i][j] * theta[j];
        }
    }
    return predictions;
}
// Example usage
int main() {
    // Generate some synthetic data
    srand(42); // Seed for reproducibility
    int m = 100; // number of samples
    vector<vector<double>> X(m, vector<double>(1));
    vector<double> y(m);
    for (int i = 0; i < m; ++i) {
        X[i][0] = 2 * ((double)rand() / RAND_MAX); // Random values between 0 and 2
        y[i] = 4 + 3 * X[i][0] + ((double)rand() / RAND_MAX - 0.5); // Adding noise
    }

    // Perform linear regression
    vector<double> theta_best = linear_regression(X, y);
    cout << "Optimal parameters (theta): ";
    for (const auto& t : theta_best) {
        cout << t << " ";
    }
    cout << endl;

    // Make predictions
    vector<vector<double>> X_new = {{0}, {2}};
    vector<double> y_predict = predict(X_new, theta_best);
    cout << "Predictions: ";
    for (const auto& pred : y_predict) {
        cout << pred << " ";
    }
    cout << endl;

    return 0;
}
// Note: The plotting part is omitted in this C++ implementation as it requires additional libraries like matplotlibcpp or similar.
// To visualize the results, you can use libraries like matplotlibcpp or gnuplot in C++.
// Alternatively, you can export the results to a file and plot them using Python or another tool.

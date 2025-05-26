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
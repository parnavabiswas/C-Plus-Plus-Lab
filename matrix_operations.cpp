#include <iostream>
#include <vector>
using namespace std;

// Function to read matrix from user
void readMatrix(vector<vector<int>>& matrix, int rows, int cols, int matrixNumber) {
    cout << "\nEnter elements of Matrix " << matrixNumber << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix
void displayMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << "\n" << name << ":" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();
    
    vector<vector<int>> result(rows_A, vector<int>(cols_B, 0));
    
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            for (int k = 0; k < cols_A; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;
    int choice;
    
    cout << "========== MATRIX OPERATIONS PROGRAM ==========" << endl;
    
    // Read dimensions of first matrix
    cout << "\nEnter dimensions of Matrix 1:" << endl;
    cout << "Number of rows: ";
    cin >> rows1;
    cout << "Number of columns: ";
    cin >> cols1;
    
    // Initialize matrices
    vector<vector<int>> matrix1(rows1, vector<int>(cols1));
    
    // Read first matrix
    readMatrix(matrix1, rows1, cols1, 1);
    
    cout << "\n========== OPERATION MENU ==========" << endl;
    cout << "1. Addition (A + B)" << endl;
    cout << "2. Subtraction (A - B)" << endl;
    cout << "3. Multiplication (A * B)" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            // Addition: Both matrices must have same dimensions
            if (rows2 != rows1 || cols2 != cols1) {
                cout << "\nFor addition, both matrices must have same dimensions!" << endl;
                cout << "Enter dimensions of Matrix 2:" << endl;
                cout << "Number of rows (must be " << rows1 << "): ";
                cin >> rows2;
                cout << "Number of columns (must be " << cols1 << "): ";
                cin >> cols2;
            }
            
            if (rows2 == rows1 && cols2 == cols1) {
                vector<vector<int>> matrix2(rows2, vector<int>(cols2));
                readMatrix(matrix2, rows2, cols2, 2);
                
                vector<vector<int>> result = addMatrices(matrix1, matrix2);
                
                displayMatrix(matrix1, "Matrix 1");
                displayMatrix(matrix2, "Matrix 2");
                displayMatrix(result, "Result (A + B)");
            } else {
                cout << "\nError: Matrices must have same dimensions for addition!" << endl;
            }
            break;
        }
        
        case 2: {
            // Subtraction: Both matrices must have same dimensions
            if (rows2 != rows1 || cols2 != cols1) {
                cout << "\nFor subtraction, both matrices must have same dimensions!" << endl;
                cout << "Enter dimensions of Matrix 2:" << endl;
                cout << "Number of rows (must be " << rows1 << "): ";
                cin >> rows2;
                cout << "Number of columns (must be " << cols1 << "): ";
                cin >> cols2;
            }
            
            if (rows2 == rows1 && cols2 == cols1) {
                vector<vector<int>> matrix2(rows2, vector<int>(cols2));
                readMatrix(matrix2, rows2, cols2, 2);
                
                vector<vector<int>> result = subtractMatrices(matrix1, matrix2);
                
                displayMatrix(matrix1, "Matrix 1");
                displayMatrix(matrix2, "Matrix 2");
                displayMatrix(result, "Result (A - B)");
            } else {
                cout << "\nError: Matrices must have same dimensions for subtraction!" << endl;
            }
            break;
        }
        
        case 3: {
            // Multiplication: cols of A must equal rows of B
            cout << "\nFor multiplication, columns of Matrix 1 must equal rows of Matrix 2!" << endl;
            cout << "Enter dimensions of Matrix 2:" << endl;
            cout << "Number of rows (must be " << cols1 << "): ";
            cin >> rows2;
            cout << "Number of columns: ";
            cin >> cols2;
            
            if (rows2 == cols1) {
                vector<vector<int>> matrix2(rows2, vector<int>(cols2));
                readMatrix(matrix2, rows2, cols2, 2);
                
                vector<vector<int>> result = multiplyMatrices(matrix1, matrix2);
                
                displayMatrix(matrix1, "Matrix 1");
                displayMatrix(matrix2, "Matrix 2");
                displayMatrix(result, "Result (A * B)");
            } else {
                cout << "\nError: Columns of Matrix 1 must equal rows of Matrix 2 for multiplication!" << endl;
            }
            break;
        }
        
        case 4: {
            cout << "\nThank you for using Matrix Operations Program!" << endl;
            break;
        }
        
        default: {
            cout << "\nInvalid choice! Please enter a valid option (1-4)." << endl;
            break;
        }
    }
    
    return 0;
}

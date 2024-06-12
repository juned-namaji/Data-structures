#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> bruteForce(const vector<vector<int>> &m1, const vector<vector<int>> &m2)
{
    int n = m1.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return ans;
}

vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();

    if (n == 1)
    {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));

    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    vector<vector<int>> P1(newSize, vector<int>(newSize));
    vector<vector<int>> P2(newSize, vector<int>(newSize));
    vector<vector<int>> P3(newSize, vector<int>(newSize));
    vector<vector<int>> P4(newSize, vector<int>(newSize));
    vector<vector<int>> P5(newSize, vector<int>(newSize));
    vector<vector<int>> P6(newSize, vector<int>(newSize));
    vector<vector<int>> P7(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; ++i)
    {
        for (int j = 0; j < newSize; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    P1 = strassenMultiply(A11, subtractMatrix(B12, B22));
    P2 = strassenMultiply(addMatrix(A11, A12), B22);
    P3 = strassenMultiply(addMatrix(A21, A22), B11);
    P4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    P5 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    P6 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));
    P7 = strassenMultiply(subtractMatrix(A11, A21), addMatrix(B11, B12));

    // Compute the submatrices of C
    vector<vector<int>> C11_temp = subtractMatrix(addMatrix(P5, P4), P2);
    vector<vector<int>> C12_temp = addMatrix(P1, P2);
    vector<vector<int>> C21_temp = addMatrix(P3, P4);
    vector<vector<int>> C22_temp = subtractMatrix(addMatrix(P5, P1), P3);

    // Combine the submatrices into the final result
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < newSize; ++i)
    {
        for (int j = 0; j < newSize; ++j)
        {
            C[i][j] = C11_temp[i][j];
            C[i][j + newSize] = C12_temp[i][j];
            C[i + newSize][j] = C21_temp[i][j];
            C[i + newSize][j + newSize] = C22_temp[i][j];
        }
    }

    return C;
}
int main()
{
    int n; // Size of the matrices (assumed to be a power of 2)
    cout << "Enter the size of the matrices (power of 2): ";
    cin >> n;

    // Initialize matrices A, B, and C
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Input matrices A and B
    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> B

                       [i][j];
        }
    }

    // Perform matrix multiplication using Strassen's algorithm
    C = strassenMultiply(A, B);

    // Display the result matrix C
    cout << "Resultant matrix C:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
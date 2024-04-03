#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


VectorXd solveSystemPALU(const MatrixXd& A, const VectorXd& b){
    VectorXd sol= A.fullPivLu().solve(b);
    return sol;
}
double calcErrRel(const VectorXd& x, const VectorXd& exact) {
    double err= (exact - x).norm() / exact.norm();
    return err;
}

VectorXd solveSystemQR(const MatrixXd& A, const VectorXd& b) {
    VectorXd sol= A.colPivHouseholderQr().solve(b);
    return sol;
}

int main()
{
    Matrix2d A1, A2, A3;
    Vector2d b1, b2, b3;

    A1 << 5.547001962252291e-01, -3.770900990025203e-02,8.320502943378437e-01, -9.992887623566787e-01;
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;

    A2 << 5.547001962252291e-01, -5.540607316466765e-01,8.320502943378437e-01, -8.324762492991313e-01;
    b2 <<-6.394645785530173e-04, 4.259549612877223e-04;

    A3 << 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01, -8.320502947645361e-01;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;

    Vector2d x1p = solveSystemPALU(A1, b1);
    Vector2d x2p = solveSystemPALU(A2, b2);
    Vector2d x3p = solveSystemPALU(A3, b3);

    Vector2d x1q = solveSystemQR(A1, b1);
    Vector2d x2q = solveSystemQR(A2, b2);
    Vector2d x3q = solveSystemQR(A3, b3);


    Vector2d exactSolution(-1.0, -1.0);
    double relErr1p = calcErrRel(x1p, exactSolution);
    double relErr2p = calcErrRel(x2p, exactSolution);
    double relErr3p = calcErrRel(x3p, exactSolution);

    double relErr1q = calcErrRel(x1q, exactSolution);
    double relErr2q = calcErrRel(x2q, exactSolution);
    double relErr3q = calcErrRel(x3q, exactSolution);

    cout << "1.Errore Relativo con decomposizione PALU: " << relErr1p << endl;
    cout << "2.Errore Relativo con decomposizione PALU: " << relErr2p << endl;
    cout << "3.Errore Relativo con decomposizione PALU: " << relErr3p << endl;

    cout << "1.Errore Relativo con decomposizione QR: " << relErr1q << endl;
    cout << "2.Errore Relativo con decomposizione QR: " << relErr2q << endl;
    cout << "3.Errore Relativo con decomposizione QR: " << relErr3q << endl;


  return 0;
}

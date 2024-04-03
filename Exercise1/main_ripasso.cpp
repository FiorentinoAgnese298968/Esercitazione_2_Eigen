#include <iostream>
#include "Eigen/Eigen"
using namespace std;
using namespace Eigen;

//int foo(const int &c, int &d){ //lo definisco come referenza e visto che non volevo che fosse modificato lo definisco come const
  //  c++;
 //   return c;
//}
// se faccio una funzione void non restituisce nulla
int main()
{
    //int a=0;
    //int c=a; //una variabile si può inizializzzare a partire da un'altra: COPIA
    //a++;
    //cout<< "c: " << c <<endl;

    //const int i=1; //una volta definita non può essere più modificata
    //double d=5.5;
    //int ii=d;
    //cout << "ii:" <<ii<< endl;

    //REFERENZA
    //const int &ref= ii; //creazione referenza deve essere dello stesso tipo della variabile che si va ad inserire(se l'oggetto di partenza è di tipo const anche la referenza deve esserlo)
    //una referenza costante può essere inizializzata con un literal
    //se inizializzo la ref intera con un double è particolare:
    //double d=5.5;
    //const int &ref=d;
    //Equivale a:
    //double d=5.5;
    //int temp=d;
    //const int &ref=temp; //diventa un alias per d, se io modifico d non modifica la referenza e viceversa
    //per l'alias devo mettere &

    //a++;
   // cout <<"ref: "<< ref << endl;


   // int jj=0;
    //int ii=0;
    //int b= foo(jj, ii);
   // cout << jj <<endl;



    //Step 1: int &c= jj;  è un alias, lavorare su c e lavorare su jj è la stessa cosa
    //Step 2: eseguire il corpo{}
    //Step 3: return ->int b=valueReturn




    //LIBRERIA EIGEN (vedere documentazione) https://eigen.tuxfamily.org/dox/GettingStarted.html

    //vettori e matrici
    srand(5);
    RowVector4d v= Vector4d::Constant(4.0); // 4 è la dimensione, d è il tipo
    cout << v.cwiseAbs() <<endl; //componente a componente valore assoluto
    Matrix4d A= Matrix4d::Zero(); //creazione matrice, non posso più modificare la dimensione
    MatrixXd B= MatrixXd::Ones(3,4); //matrice con dim  generica X, posso anche scrivere ...Zero(3,4)


    B.conservativeResize(2,4); //per ridimensionare e mantenere gli uni
    cout << B<<endl;


    int n=5;
    MatrixXd C=MatrixXd::Zero(n,n);
    VectorXd w= VectorXd::LinSpaced(n*n,1,n*n);
    cout <<w<<endl;
   // for (unsigned int i=0; i<n; i++){
     //   C.row(i)= w.segment(i*n, n);
    // }
    //C=w.reshaped(n,n); //risultato del vettore preso, tagliato e distribuito in modo tale da darmi una matrice nxn
    //eigen lavora per colonna, quindi se la voglio per righe posso limitarmi a trasporla
    //ma questa cosa si può cambiare
    C=w.reshaped<RowMajor>(n,n); //così lavora per riga
    cout<< C<<endl;




    //MATRICE DI HILBERT
    // for (unsigned int i=0; i<n; i++){
    //   C.col(i)= VectorXd::LinSpaced(n, i+1, n+1);
    // C=C.cwiseInverse();
    // }

    //JacobiSVD<MatrixXd> svd(C); decomposizione a valori singolari
    //VectorXd v1=svd.singularValues();


    return 0;
}

#include <iostream>
#include <math.h>

int det_matr(double m, double a, double b, double c, double *detm);

int main(int argc, char* argv[]){
    double detm;

    if(argc < 5){
        std::cout << "No arguments" << "\n";
        return 1;
    }

    double m, a, b, c;

    try{
        m = std :: stod(argv[1]);
        a = std :: stod(argv[2]);
        b = std :: stod(argv[3]);
        c = std :: stod(argv[4]);
    }
    catch(...)
    {
       std::cout << "Not able to parse arguments" << "\n";
       return 1;
    }

    if(det_matr(m, a, b, c, &detm) != 0)return 2;

    std::cout << detm << "\n";

    return 0;
}

int det_matr(double m, double a, double b, double c, double *detm){
    if(b*b - 4*a*c < 0)return 1;

    double lambda_1;
    double lambda_2;

    lambda_1 = b + sqrt(b*b - 4*a*c);
    lambda_2 = b - sqrt(b*b - 4*a*c);

    if(lambda_1 - lambda_2 < 1e-16)return 2;

    double c1, c2;

    c1 = (b*lambda_2 - b*b + a*c)/(lambda_1*(lambda_2 - lambda_1));
    c2 = (b*lambda_1 - b*b + a*c)/(lambda_2*(lambda_1 - lambda_2));

    *detm = c1*pow(lambda_1, m) + c2*pow(lambda_2, m);
    return 0;
}


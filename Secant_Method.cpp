#include <bits/stdc++.h>

using namespace std;

class Secant {

    private:
        const double err = 0.001;

         double function(double x) {
             return x*x - 3;

         }

        double secant(double a, double b) {
           return (b-(((b-a)*function(b))/(function(b)-function(a))));
        }
    public:

        void solve() {

            double a, b;
            srand(time(0));
            while(true) {
                a = rand()%100 - 50;
                b = rand()%100;
                if(function(a) * function(b) < 0.0) {
                    break;
                }
            }

            double new_root = secant(a, b);
            double root;

            while(true) {
                cout << "\na = " << a << "   b = " << b << "   root = " << new_root << endl;
                if(function(new_root) == 0.0) {
                    root = new_root;
                    break;
                }

                if(abs(new_root - secant(new_root, a)) < err) {
                    root = new_root;
                    break;
                }

                b = a;
                a = new_root;
                new_root = secant(a, b);
            }
            root = secant(root, a);
            cout << "\n\nThe root is : " << root << endl;
        }
};

int main() {

    Secant secant;

    secant.solve();

    return 0;

}

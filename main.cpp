#include <iostream>
#include <cmath>
#include <stdio.h>
//#include <iomanip>
#include <bitset>
//#include <ios>
//#include <boost/tr1/tr1/utility>
// #include <boost/tr1/utility.hpp>
#include <boost/multi_array.hpp>
//#include <boost/math/
#include <boost/math_fwd.hpp>
//#include <boost/multiprecision/mpfr.hpp>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define countof(x) (sizeof(x)/sizeof(*x))

long pow2(int a, int p)
{
	while(p>1)
		a << 1, --p;
	return a;
}


typedef boost::multiprecision::cpp_int int_t;
typedef boost::multiprecision::cpp_dec_float_100 fp_t;
//typedef boost::math::ef::e_float e_float_t;


void outhexdigits(std::ostream& out, fp_t d, int max_chars=160)
{
    while(d > 0. && max_chars)
    {
        while(d < 1. && max_chars){
            out << '0';
            --max_chars;
            d*=16;
        }

        if (d>=1. && max_chars) {
            int i = 0;
            while (d>=1.)
                ++i, --d;
            out << std::hex << i;
            --max_chars;
        }
    }
}


int main(int argc, char **argv) {

    using namespace std;
    using namespace boost::multiprecision;

    cout << std::endl;

    fp_t sixteenth = 1;
    fp_t eights = 0;
    fp_t fours = 0;
    fp_t pi = 0;
    fp_t pi_4 = 0;

    cout << "===================17:" << std::hexfloat << 17.0625 << endl;
    outhexdigits(std::cout, 17.0625);
    cout << "17:" << std::hexfloat << 17.0625;

    for (int i = 0; i<16; ++i)
    {
        fp_t  n = 2/(eights+1) + 2/(fours+2) +1/(fours+3) - .5/(fours+5) - .5/(fours+6) - .25/(fours+7);
                //4/(eights+1) - 2/(eights+4) - 1/(eights+5) - 1/(eights+6); // accumulative part of pi
        fp_t  n_pi_4 = 8/(eights+1) + 8/(eights+2) + 4/(eights+3) - 2/(eights+5) - 2/(eights+6) - 1/(eights+7); // sixteenth part of pi/4

        pi += sixteenth * n;
        pi_4 += sixteenth * n_pi_4;

        for(int t=i; t--; )
            cout<<' ';
        outhexdigits(std::cout, n, 160-i);

        std::cout
                << " * (16^-" << dec << i << ')' << std::endl
//                << pi << ' '
//                << std::hexfloat << std::setprecision(1000) << n << ' '
                << std::hexfloat << std::setprecision(1000) << pi << std::endl
                ;

        for(int t=i; t--; )
            cout<<' ';
        outhexdigits(std::cout, n_pi_4, 160-i);

        std::cout
                << " * (16^-" << dec << i << ')' << std::endl
//                << pi << ' '
//                << std::hex << std::setprecision(1000) << n << ' '
                << "hexfloat: " << std::hexfloat << pi << std::endl
                ;

        outhexdigits(cout, pi);
        std::cout<< std::endl  ;
        sixteenth /= 16;
        eights += 8;
        fours +=4;
    }

    outhexdigits(cout, pi/4);
            std::cout<< std::endl  ;
    outhexdigits(cout, pi_4);
            std::cout<< std::endl  ;
    outhexdigits(cout, pi);

/*	static const double pi = M_PI;
    std::bitset<sizeof(pi)*8> bits;
	std::cout << "11." << bits << std::endl;

    const double p[] = {4, 0,0,-2,-1,-1,0, 0};
    int i = 0;
	
	while(i < 10)
	{
        ++i;
        //std::cout << p[i%countof(p)] * i / pow2(16, i >> 3) << std::endl;
        std::cout << p[int(i)%countof(p)] * i / pow(16, i/8) << std::endl;
	}
    */
    return 0;
}

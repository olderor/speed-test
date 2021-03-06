#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>


using namespace std;

typedef unsigned long long ull;

int foo_vector(vector<int> v) {
    return 0;
}

int foo_int(ull v) {
    return 0;
}

int foo_address_vector(vector<int> &v) {
    return 0;
}

int foo_address_int(ull &v) {
    return 0;
}

int foo_const_int(const ull v) {
    return 0;
}

int foo_const_address_int(const ull &v) {
    return 0;
}

int foo_const_vector(const vector<int> v) {
    return 0;
}

int foo_const_address_vector(const vector<int> &v) {
    return 0;
}



int get_time_of_func(void(*f)(ull), ull parameter) {

    clock_t begin = clock();

    f(parameter);

    clock_t end = clock();

    return end - begin;
}






void test_vector(ull test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_vector(v);
}

void test_int(ull test_size) {

    for (ull i = 0; i < test_size; ++i) {
        foo_int(i);
    }
}

void test_address_vector(ull test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_address_vector(v);
}

void test_address_int(ull test_size) {

    for (ull i = 0; i < test_size; ++i) {
        foo_address_int(i);
    }
}

void test_const_int(ull test_size) {

    for (ull i = 0; i < test_size; ++i) {
        foo_const_int(i);
    }
}

void test_const_address_int(ull test_size) {

    for (ull i = 0; i < test_size; ++i) {
        foo_const_address_int(i);
    }
}

void test_const_vector(ull test_size) {
    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_const_vector(v);
}

void test_const_address_vector(ull test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_const_address_vector(v);
}

void make_test1(std::ostream &_Istr, ull size, int test_index) {

    double vector_time = get_time_of_func(test_vector, size);
    double int_time = get_time_of_func(test_int, size);

    double vector_address_time = get_time_of_func(test_address_vector, size);
    double int_address_time = get_time_of_func(test_address_int, size);

    _Istr << "test #" << test_index << " with size " << size << ":" << endl;
    _Istr << "vector test was elapsed within " << (int)vector_time << " milliseconds." << endl;
    _Istr << "int test was elapsed within " << (int)int_time << " milliseconds." << endl;
    _Istr << "vector address test was elapsed within " << (int)vector_address_time << " milliseconds." << endl;
    _Istr << "int address test was elapsed within " << (int)int_address_time << " milliseconds." << endl;
    _Istr << "int " << 100 - (int)(int_time / vector_time * 100.0) << "% faster than vector" << endl;
    _Istr << "vector address " << 100 - (int)(vector_address_time / vector_time * 100.0) << "% faster than vector" << endl;
    _Istr << "int address " << 100 - (int)(int_address_time / int_time * 100.0) << "% faster than int" << endl;
    _Istr << endl;

}

void make_test2(std::ostream &_Istr, ull size, int test_index) {

    double int_time = get_time_of_func(test_int, size);
    double int_address_time = get_time_of_func(test_address_int, size);
    double int_const_time = get_time_of_func(test_const_int, size);
    double int_const_address_time = get_time_of_func(test_const_address_int, size);

    _Istr << "test #" << test_index << "  with size " << size << ":" << endl;
    _Istr << "int test was elapsed within " << (int)int_time << " milliseconds." << endl;
    _Istr << "int address test was elapsed within " << (int)int_address_time << " milliseconds." << endl;
    _Istr << "int const test was elapsed within " << (int)int_const_time << " milliseconds." << endl;
    _Istr << "int const address test was elapsed within " << (int)int_const_address_time << " milliseconds." << endl;
    _Istr << "int address " << 100 - (int)(int_address_time / int_time * 100.0) << "% faster than int" << endl;
    _Istr << "int const address " << 100 - (int)(int_const_address_time / int_const_time * 100.0) << "% faster than const int" << endl;
    _Istr << "int const " << 100 - (int)(int_const_time / int_time * 100.0) << "% faster than int" << endl;
    _Istr << "int const address " << 100 - (int)(int_const_address_time / int_address_time * 100.0) << "% faster than int address" << endl;
    _Istr << endl;

}

void make_test3(std::ostream &_Istr, ull size, int test_index) {

    double vector_time = get_time_of_func(test_vector, size);
    double vector_const_time = get_time_of_func(test_const_vector, size);

    double vector_address_time = get_time_of_func(test_address_vector, size);
    double vector_const_address_time = get_time_of_func(test_const_address_vector, size);

    _Istr << "test #" << test_index << " with size " << size << ":" << endl;
    _Istr << "vector test was elapsed within " << (int)vector_time << " milliseconds." << endl;
    _Istr << "vector address test was elapsed within " << (int)vector_address_time << " milliseconds." << endl;
    _Istr << "vector const test was elapsed within " << (int)vector_const_time << " milliseconds." << endl;
    _Istr << "vector const address test was elapsed within " << (int)vector_const_address_time << " milliseconds." << endl;
    _Istr << "vector address " << 100 - (int)(vector_address_time / vector_time * 100.0) << "% faster than vector" << endl;
    _Istr << "vector const " << 100 - (int)(vector_const_time / vector_time * 100.0) << "% faster than vector" << endl;
    _Istr << "vector const address " << 100 - (int)(vector_const_address_time / vector_address_time * 100.0) << "% faster than vector address" << endl;
    _Istr << "vector const address " << 100 - (int)(vector_const_address_time / vector_const_time * 100.0) << "% faster than vector const" << endl;
    _Istr << endl;

}

int main() {

    ofstream fout("log.txt", ios::app);

    cout << "Starting testing 10^8 tests..." << endl;
    /*
    ull size = 10000;

    for (int test = 4; test <= 8; ++test) {

        cout << "Testing for size " << size << " (test " << test << ")..." << endl;
        make_test1(fout, size, test);
        cout << "Complete." << endl;

        size *= 10;
    }

    for (int test = 9; test <= 10; ++test) {

        cout << "Testing for size " << size << " (test " << test << ")..." << endl;
        make_test2(fout, size, test);
        cout << "Complete." << endl;

        size *= 10;
    }*/

    int test = 6;
    ull size = 1000000;
    for (int i = 0; i < 100; ++i) {

        cout << "Test #" << i << " for size " << size << " (test " << test << ")..." << endl;
        make_test3(fout, size, test);
    }

    ++test;
    size *= 10;


    for (int i = 0; i < 10; ++i) {
        cout << "Test #" << i << " for size " << size << " (test " << test << ")..." << endl;
        make_test3(fout, size, test);
    }

    fout.close();

    cout << "Done." << endl;

    cin.get();

    return 0;
}

#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>


using namespace std;


int foo_vector(vector<int> v) {
    return 0;
}

int foo_int(int v) {
    return 0;
}

int foo_address_vector(vector<int> &v) {
    return 0;
}

int foo_address_int(int &v) {
    return 0;
}


int get_time_of_func(void(*f)(int), int parameter) {

    clock_t begin = clock();

    f(parameter);

    clock_t end = clock();

    return end - begin;
}


void test_vector(int test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_vector(v);
}

void test_int(int test_size) {

    for (int i = 0; i < test_size; ++i) {
        foo_int(i);
    }
}

void test_address_vector(int test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_address_vector(v);
}

void test_address_int(int test_size) {

    for (int i = 0; i < test_size; ++i) {
        foo_address_int(i);
    }
}

void make_test(std::ostream &_Istr, int size) {

    double vector_time = get_time_of_func(test_vector, size);
    double int_time = get_time_of_func(test_int, size);

    double vector_address_time = get_time_of_func(test_address_vector, size);
    double int_address_time = get_time_of_func(test_address_int, size);

    _Istr << "testing with size " << size << ":" << endl;
    _Istr << "vector test was elapsed within " << (int)vector_time << " milliseconds." << endl;
    _Istr << "int test was elapsed within " << (int)int_time << " milliseconds." << endl;
    _Istr << "vector address test was elapsed within " << (int)vector_address_time << " milliseconds." << endl;
    _Istr << "int address test was elapsed within " << (int)int_address_time << " milliseconds." << endl;
    _Istr << "int " << 100 - (int)(int_time / vector_time * 100.0) << "% faster than vector" << endl;
    _Istr << "vector address " << 100 - (int)(vector_address_time / vector_time * 100.0) << "% faster than vector" << endl;
    _Istr << "int address " << 100 - (int)(int_address_time / int_time * 100.0) << "% faster than int" << endl;
    _Istr << endl;

}

int main() {

    ofstream fout("log.txt");

    cout << "Starting testing 10^8 tests..." << endl;

    int size = 1;

    for (int test = 0; test <= 8; ++test) {

        cout << "Testing for size " << size << " (test " << test << ")..." << endl;
        make_test(fout, size);
        cout << "Complete." << endl;

        size *= 10;
    }

    fout.close();

    cout << "Done." << endl;

    cin.get();

    return 0;
}

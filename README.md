# speed-test
test results: https://github.com/olderor/speed-test/blob/master/temp/log.txt
conclusion:
- use addressing when you need to pass a vector as a parameter
- use addresing when you need to pass an int as a parameter. it gives you a slight advantage in time efficiency when you have a lot of function calls. (also should work for all other types of a parameter)
- if you can make your parameter constant, just do this. but do not make an int address constant, it will slow your program down. note, that passing a constant int value is better than passing an address of int.
- but if you use some large data structures such as vectors, it is better to pass a constant address of a data as a parameter.

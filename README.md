    ----------------------------------------------------------------- 


Hi there! Welcome to Polynomial calculator!
Here I will tell some algorithm that we use in the project.

First, save two numbers like 510012, 3102 in two files --f1.txt, f2,txt.

Second, I will tell you the meaning of some functions.
    int num_first(int i) to get the first number of 510012, it means the highest power and use to create the expn array.
    void inttoarr(int i,int arr[]) and void change(int array[],int n) use to change the int number saved in the file to array. 
        The function "change" use to abandon the first number of 510012. These two functions will create the coef array.
    
Third, after create these two arrays, use the function "createpoly" to create the linked list of two polynomial.

Fourth, use the function "addpoly" to plus two polynomials, then create a new linked list. The create method is linked the list of polynomial 2 to follow the list of polynomial 1.
Then, use the function "Poly::SortList()" to sort the new linked list. Because we need to conbine the term which has same coef, so we need to sort the new linked list.

Fifth, void Poly::mulpoly(Poly &po1,Term *p2) used to do the multiple of two polynomials.

At last, use void change() to convert the array to int. Then display, the result is 510114(add) or 71021224(multiple).

How to use it:

firstly, we should wirte two number in 'f1.txt' and 'f2.txt' to represent two polynomial(eg 510012 and 3102)

secondly, write "g++ project.cpp" in the bash field;

thirdly, write "./a.out" in the bash field, after that , it will print the two number which has been write down, what you have to do is choose if you want to add or multi(1=add and 2=multi) and then Enter;

then you can get answer, if you to do it again, write'./a.out' and do it again.

## Support & Documentation


 
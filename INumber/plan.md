the plan is here to create a class called INumber which allows to store infinitely large numbers
to do that, we use a map<int, Billion*> which stores pointers to Billion objects, each with a unique index int.

e.g
123456789.0 would be
billion(123456789, 0)

our billion class has two private values
int _index;
unsigned int _value

Getters are getIndex and getValue

----

how it works in reality

INumber nb; // generates an empty INumber object which has sign true (+) by default
nb.addBillion(123412341, 0);
adds that value

now for adding another INumber
INumber nb2(nb); //copy constructor

nb + nb2 = 246824682, 0

-----

I truly need to be able to read numbers from files and also save them
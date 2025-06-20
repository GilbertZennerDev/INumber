the task is to define my own datatype INumber, which is an infinite float
I am going to use a vector to store all of the digits

I need to figure out the logic for adding with overflow
it is working fine for addition without overflow

  5 5

  5 5

1 1 0

we gain one digit, so we need to push at the front

I need a deque
I have switched now to the deque

if i == 0 and rest > 0, then push_front(rest) and do rest = 0

let us verbalize the flow
we start at size - 1:

rest = 0;

result = 5 + 5 + rest = 10 + 0 = 10
if (result > 9) //true
{
    result -= 10; // 0
    rest += 1; // 1
}
else
{
    result += rest;
    rest = 0;
    if (result > 9) //true
    {
        result -= 10;
        rest += 1;
    }
}

// if I switch to char instead of int, then I save 75% of size, which is huge for an infinite sized deque

/*

IDEA 1: Class that stores very large numbers as deque<char>

IDEA 2: Class that stores very large number as its primes

IDEA 3: Create a library where you map bit chunks of more than 1 Byte to a 1 Byte Char.
Ideally then you could speed up transfers dramatically
*/
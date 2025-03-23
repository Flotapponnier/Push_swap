#Push_swap 

Push_swap is a sorting algorithm project developed as part of the 42 School curriculum. This implementation follows the Mechanical Turk approach and is optimized for efficiency, achieving approximately:
around 5290 moves for 500 numbers
around 600 moves for 100 numbers
The sorting algorithm used in this project is explained in detail [here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).


## Features
-Efficient sorting algorithm based on the Mechanical Turk method
-Handles any valid integer input within the int range
-Optimized for minimal operations
-Robust error handling and input validation
-Memory-leak free and stable performance


## Compilation and Usage
Build
Run the following command to compile the program:

```sh
make
```
__Running Push_swap__
Execute the program with a list of numbers:

```sh
./push_swap "list of numbers"
```

Example:
```sh
./push_swap 4 67 3 87 23
```

__Checking the Move Count__
To check the number of moves used:

```sh
./push_swap 4 67 3 87 23 | wc -l
```


## How It Works
-Parsing and Validation – Checks for duplicate numbers, non-numeric inputs, and integer overflows.

-Algorithm Execution – Implements a Mechanical Turk-based sorting method.

-Move Optimization – Minimizes the number of operations required.

-Stack Manipulation – Utilizes two stacks (a and b) with operations such as sa, sb, pa, pb, ra, and rb.

## Why Choose This Implementation?
Optimized for performance (~5290 moves for 500 numbers, ~600 for 100 numbers)
Fully tested and verified
Handles all edge cases, including duplicates, overflows, and invalid input
Memory-leak free and stable implementation

## Conclusion
Push_swap is an excellent project for developing a strong understanding of sorting algorithms and data structures. 
By implementing an efficient sorting solution, you gain in-depth experience with linked lists, stack-based operations, and algorithmic optimization.
The project challenges you to think critically about different sorting approaches while maintaining performance constraints, making it a valuable learning experience.


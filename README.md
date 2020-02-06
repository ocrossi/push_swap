# push_swap

To compile the code you will need GNU Make and gcc installed. 
you can execute the scripts in the script folder with bash installed too

Usage:

Clone the the repo, enter the directory cloned 
1. make
2. ./scripts/complexity (1st arg pile size 2nd number of test)
3. ./scripts/test.sh (1st number 2nd number)

I did not code those scripts.

Subject is in the code session. 

Compiling and executing the code is explained in the readme file

This subject is about coding a sorting algorithm with a limit set of instructions. It introduces the concept of complexity in algorithmics.

My algorithm is divided in 2 parts. 

For the low level piles (20 or lower) i apply the sorting algorithm adapted to push swap instructions. It consists in storing on b the numbers by decrescent number the inputs, quick sort A pile when it's 3 elements long and then push on a the numbers stored on b.

The bigger level of this algorithm is a divide and conquer strategy.

Divide input in pockets of numbers according to the median of the pile, adapted each iteration of divide groups. Repeat until it comes to the low level case.

Apply low level case

keep splitting median groups if needed 

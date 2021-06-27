# crep

A grep-esque program in c. Enter a search string and file name as command line arguments
and crep will return all the lines in which the search string appears, with line numbers.

To compile:

$ gcc crep.c -o crep

To run:

$ ./crep "search string" "file.txt"

For example:

$ .\crep fire troubles_braids.txt

![example_fire](example_fire.jpg?raw=true "Trouble's Braids")

And crepping crep with crep:

$ ./crep crep crep.c

![example_crep](example_crep.jpg?raw=true "Crep Itself")

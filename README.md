# File Processing Homework 3
MakeFile is available in every directory. To compile each '.c' file, just run ` $ make`
- To run box: ` $ ./box < box.in`
- To run btree: ` $ ./btree`
- To run det: ` $ ./det < det.in`
- To run mergesort: ` $ ./mergesort < test.in`
- To run queue: ` $ ./queue`

To check for memory leak, we can use `valgrind`
Here is an example to check memory leak for box program,
```sh
$ valgrind --tool=memcheck --leak-check=full ./box < test.in
```

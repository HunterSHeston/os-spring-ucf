To run the char device do the following:

1. open terminal
2. cd to the ebbchar dir
3. type make in the terminal
4. type "sudo insmod ebbchar.c" in the terminal
5. type "sudo su" in the terminal
6. use "cat" and "echo" to read and write to the device
   -examples
    a. echo "hello!" > /dev/ebbchar
    b. cat /dev/ebbchar

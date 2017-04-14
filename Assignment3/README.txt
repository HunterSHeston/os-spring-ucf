To compile:

1) in this directory type "make" in terminal (not in the ReadEbbChar or WriteEbbChar dirs even though they have make files too)

----------------------------------------------------

To add the modules to the kernel:

1) type "sudo insmod WriteEbbChar/writeEbbchar.ko" in terminal

2) type "sudo insmod ReadEbbChar/readEbbchar.ko" in terminal

----------------------------------------------------

To test first become super user by typing "sudo su" in terminal
   
1) To write to the writeEbbchar module type "echo 'some message' > /dev/writeEbbchar"

2) To read from the readEbbchar module type "cat /dev/readEbbchar"



# merges the two .o files into the executable mini5
mini5: mini5main.o mini5phone.o
	gcc mini5main.o mini5phone.o -o mini5

# Compiles mini5main.c if it has been updated since the last compile
mini5main.o: mini5main.c
	gcc -c mini5main.c 

# Compiles mini5phone.c if it has been updated since the last compile
mini5phone.o: mini5phone.c
	gcc -c mini5phone.c 

# To remove the .o files from the directory
clean: 
	rm *.o 

# Run the command <make> in the shell to compile the programs
# Run the command <clean> in the shell to remove all .o files 

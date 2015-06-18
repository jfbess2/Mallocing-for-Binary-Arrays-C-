# Mallocing-for-Binary-Arrays-C-

Jacob Besse
Documentation

Desciption:
	The file parameters are opened and format file is parsed to find out the size and name
	of each variable.  After this array pointers are filled with the binary data appropiate
	for each name variable.  The size of bytes allocated for each array is the array size
	times the byte size corresponding with that data type.  The array's are then sent
	to the man_data function which manipulates the data.  It checks for types of the single
	datum to be manipulated or both types.  Then it processes what the user wants done with
	the data and manipulates it that way and then outputs it to the screen.

TO QUIT PROGRAM: enter 'q'

Limitation:When naming binary data to a variable names, I assumed it had to be in
	alphabetical order (this is how the example is given) 'a' to 'z'.

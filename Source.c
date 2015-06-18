#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG_FORMAT 0
#define MAXLINE 40

#define CHAR_type   0
#define USHORT_type 1
#define UINT_type   2
#define ULONG_type  3

FILE *format_file;
FILE *binary_file;



// Get a line from the format file.  Space should have been allocated for the
// parameters before calling this file and the file should have been opened.
// (note: name should be a 2 character array so we can treat it like a string)
//
// get_format_line returns 0 on success and -1 on end of file or error

int get_format_line(FILE *format_file, int *type, int *array_size, char *name, int *bit_size) {
    char line[MAXLINE];
    char *var_type;
    // Read a line from the file -- this assumes it has already been opened
    if (fgets(line, MAXLINE, format_file) != NULL) {

        // find the type
        var_type = strtok(line, " ");
        if (!strcmp(var_type, "char")){ *type = 0; *bit_size = 1;}
        else if (!strcmp(var_type, "ushort")){ *type = 1; *bit_size = 2;}
        else if (!strcmp(var_type, "uint")){ *type = 2; *bit_size = 4;}
        else if (!strcmp(var_type, "ulong")){ *type = 3; *bit_size = 4;}

        // find the size
        *array_size = atoi(strtok(NULL, " "));

        // find the name
        strcpy(name,strtok(NULL, " "));

        if (DEBUG_FORMAT)
            printf("  Debug Format Line: type=%d, size=%d, name=%c\n",
                                         *type, *array_size, name[0]);
	return(1);
    }
    else return(0); // to indicate end of file
}


int man_data(char * c, short * s, int * i, long * l, int * t_a_o){
	char manip[40];
	fgets(manip, 40, stdin);
	char *a =&(manip[3]);

	int as_int = (int)(manip[2]);
	int type =t_a_o[(as_int-97)];
	int num = atoi(a);

	char *b = &( manip[6]);
	int as_int2 = (int)(manip[5]);
	int type2 = 0;
	type2 = t_a_o[(as_int2 - 97)];
	int num2 = atoi(b);

	if(type ==0){
		if(manip[0] == '='){
		printf("-----> %c",  c[num]);
		}
		else if((manip[0])== '!'){
		printf("-----> %c", ~(c[num]));}} 

	else if(type ==1){
		if(manip[0] == '='){
			printf("-----> 0x%hX", s[num]);}

		else if((manip[0])== '!'){
			printf("-----> 0x%hX", ~(s[num]));}

		else if((manip[0])== '|')
			{if(type2 == 2){printf("-----> 0x%X", (s[num] | i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (s[num] | l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%hX", (s[num] | s[num2]));}}
		else if((manip[0])== '&')
			{if(type2 == 2){printf("-----> 0x%X", (s[num] & i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (s[num] & l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%hX", (s[num] & s[num2]));}}
		else if((manip[0])== '^')
			{if(type2 == 2){printf("-----> 0x%X", (s[num] ^ i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (s[num] ^ l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%hX", (s[num] ^ s[num2]));}}
		else if((manip[0])== '>')
			{if(type2 == 2){printf("-----> 0x%hX", (s[num] >> i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%hX", (s[num] >> l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%hX", (s[num] >> s[num2]));}}
		else if((manip[0])== '<')
			{if(type2 == 2) {printf("-----> 0x%hX", (s[num] << i[num2]));}
			else if((type2 == 3)) {printf("-----> 0x%hX", (s[num] << l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%hX", (s[num] << s[num2]));}
			}
		
		}



	else if(type ==2){
		if(manip[0] == '='){printf("-----> 0x%X", i[num]);}

		else if((manip[0])== '!'){printf("-----> 0x%X", ~(i[num]));}

		else if((manip[0])== '|')
			{if(type2 == 2){printf("-----> 0x%X", (i[num] | i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (i[num] | l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%X", (i[num] | s[num2]));}}
		else if((manip[0])== '&')
			{if(type2 == 2){printf("-----> 0x%X", (i[num] & i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (i[num] & l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%X", (i[num] & s[num2]));}}
		else if((manip[0])== '^')
			{if(type2 == 2){printf("-----> 0x%X", (i[num] ^ i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (i[num] ^ l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%X", (i[num] ^ s[num2]));}}
		else if((manip[0])== '>')
			{if(type2 == 2){printf("-----> 0x%X", (i[num] >> i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%X", (i[num] >> l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%X", (i[num] >> s[num2]));}}
		else if((manip[0])== '<')
			{if(type2 == 2) {printf("-----> 0x%X", (i[num] << i[num2]));}
			else if((type2 == 3)) {printf("-----> 0x%X", (i[num] << l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%X", (i[num] << s[num2]));}
			}
	}

	else if(type ==3){
		if(manip[0] == '='){printf("-----> 0x%lX", l[num]);}
		else if((manip[0])== '!'){printf("-----> 0x%lX", ~(l[num]));}

		else if((manip[0])== '|')
			{if(type2 == 2){printf("-----> 0x%lX", (l[num] | i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (l[num] | l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%lX", (l[num] | s[num2]));}}
		else if((manip[0])== '&')
			{if(type2 == 2){printf("-----> 0x%lX", (l[num] & i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (l[num] & l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%lX", (l[num] & s[num2]));}}
		else if((manip[0])== '^')
			{if(type2 == 2){printf("-----> 0x%lX", (l[num] ^ i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (l[num] ^ l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%lX", (l[num] ^ s[num2]));}}
		else if((manip[0])== '>')
			{if(type2 == 2){printf("-----> 0x%lX", (l[num] >> i[num2]));}
			else if((type2 == 3)){printf("-----> 0x%lX", (l[num] >> l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%lX", (l[num] >> s[num2]));}}
		else if((manip[0])== '<')
			{if(type2 == 2) {printf("-----> 0x%lX", (l[num] << i[num2]));}
			else if((type2 == 3)) {printf("-----> 0x%lX", (l[num] << l[num2]));}
			else if((type2 == 1)){printf("-----> 0x%lX", (l[num] << s[num2]));}
		}}

	
	else if(manip[0]=='q')
		return(0);
	printf("\n");
	return(1);
}


int main(){

	int type = 0;
	int array_size=0;
	char name[2];
	int bit_size = 0;

	char * c;
	int * ui;
	short * s;
	long * l;

	int t_a_o[100];
	int increment=0;
	
///////////////////////////
///////////////////////////
///////////////////////////
///////////////////////////  LIMITATION1
	format_file = fopen("myfile.format", "r");
	binary_file = fopen("myfile.data", "rb");


	while(get_format_line(format_file, &type, &array_size, name, &bit_size)){
		if(type == 0){
			c = (char*)malloc(bit_size*array_size);
			fread(c, bit_size, array_size, binary_file);
			for (int i=0; i< array_size; i++){
			printf("%c%d = %c\n", name[0], i, c[i]);}}
		else if(type == 1){
			s = (short*) malloc (bit_size*array_size);
			fread(s, bit_size, array_size, binary_file);
			for (int i=0; i< array_size; i++){
			printf("%c%d = 0x%hu\n",name[0], i, s[i]);}}
		else if(type == 2){
			ui = (int*) malloc(bit_size*array_size);
			fread(ui, bit_size, array_size, binary_file);
			for (int i=0; i< array_size; i++){
			printf("%c%d = 0x%X\n",name[0], i, ui[i]);}}
		else if(type == 3){
			l = (long*) malloc(bit_size*array_size);
			fread(l, bit_size, array_size, binary_file);
			for (int i=0; i< array_size; i++){
			printf("%c%d = 0x%lX\n", name[0], i, l[i]);
			}
		}
		t_a_o[increment]=type;
		increment++;
	}

	printf("\n");
	while(man_data(c, s, ui, l, t_a_o)==1)
	{ 
		int i = 0;}
	return 0;
}

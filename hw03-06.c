//Libraries
  #include <stdio.h>
  #include <stdlib.h>
  #include <sys/stat.h>
  #include <string.h>

//Prototypes
  char convertBit01(int octalEntry);
  char convertBit02(int octalEntry);
  char convertBit03(int octalEntry);

//Main function
  int main(int argc, char *argv[])
    {//Start main
       //Variables
	 struct stat fileinfo;
	 int i, j, k;
       //If there aren't 2 arguments, error out
         if(argc !=2)
	   {//Start of if
             printf("Usage:   statfile filename\n");
             exit(0);
	   }//End of if
       //Get the info of the file
         i=stat(argv[1], &fileinfo);
         if(i==-1)
	   {//Start of if
             printf("Unable to stat %s\n",argv[1]);
             exit(0); 
           }//End of if
       //Print the permission bits
	   int modeDigit = fileinfo.st_mode;
       //Convert to octal
         //Variables
           int octalCount = 8;
           int modeOctal = 0;
	   int remainder = 0;
	   int offset = 1;
           int increment = 10;
           i = offset;
	 //Through through the tokens to convert
           while(fileinfo.st_mode != 0)
             {//Start of while
               remainder = fileinfo.st_mode % octalCount;
               fileinfo.st_mode = fileinfo.st_mode / octalCount;
               modeOctal += (i * remainder);
               i *= increment;
             }//End of while
       //Convert to binary
         //Variables
	   char octal[100];
	   char binary[100];
         //Convert int modeOctal to string octal
	   sprintf(octal, "%d", modeOctal);
         //Convert the octal to the 3-bit sets
	   binary[0] = octal[2];
           binary[1] = convertBit01(octal[3]);
           binary[2] = convertBit02(octal[3]);
           binary[3] = convertBit03(octal[3]);
           binary[4] = convertBit01(octal[4]);
           binary[5] = convertBit02(octal[4]);
           binary[6] = convertBit03(octal[4]);
           binary[7] = convertBit01(octal[5]);
           binary[8] = convertBit02(octal[5]);
           binary[9] = convertBit03(octal[5]);
           binary[10] = '\0';
       //Print the values
	 printf("**************hw03-06.c**************\n");
         printf("Permissions(digit format): %d\n", modeDigit);
	 printf("Permissions(octal format): %d\n", modeOctal);
	 printf("Permissions(10-bit format): %s\n", binary);
    }//End of main

//Convert 1st char
  char convertBit01(int octalEntry)
    {//Start of convertBit01
      switch(octalEntry)
        {//Start of switch
	  case '0': return '0';
	  case '1': return '0';
	  case '2': return '0';
	  case '3': return '0';
	  case '4': return '1';
	  case '5': return '1';
	  case '6': return '1';
	  case '7': return '1';
	  default: break;
        }//End of switch
    }//Start of convertBit01

//Convert 2nd char
  char convertBit02(int octalEntry)
    {//Start of convertBit02
      switch(octalEntry)
        {//Start of switch
	  case '0': return '0';
	  case '1': return '0';
	  case '2': return '1';
	  case '3': return '1';
	  case '4': return '0';
	  case '5': return '0';
	  case '6': return '1';
	  case '7': return '1';
	  default: break;
        }//End of switch
    }//Start of convertBit02

//Convert 3rd char
  char convertBit03(int octalEntry)
    {//Start of convertBit03
      switch(octalEntry)
        {//Start of switch
	  case '0': return '0';
	  case '1': return '1';
	  case '2': return '0';
	  case '3': return '1';
	  case '4': return '0';
	  case '5': return '1';
	  case '6': return '0';
	  case '7': return '1';
	  default: break;
        }//End of switch
    }//End of convertBit03

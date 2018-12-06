#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
int kmain()
{
       clearScreen();
	   
       print("Welcome to MuinOS!\n\nUser login\n");
	   string username = "muin";
	   string password = "1234";
	   string inp = 0;
	sessionStart:
	   
	   while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("\nusername: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("\npassword: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("\nLogin successful!\n");
			   break;
		   }
		   print("\nWrong info. Try again\n");
	   }
  
       while (1)
       {
			print("\nmuinOS> ");
			inp = readStr();
			if(strEql(inp,"cmd"))
			{
				print("You are already in cmd\n");
			}
			else if(strEql(inp,"clrscr"))
			{
				clearScreen();
			}
			else if(strEql(inp,"substr"))
			{
				print("Enter string: ");
				inp = readStr();
				screen_substr(inp);
			}
			else if(strEql(inp, "strlen"))
			{
				print("Enter string: ");
				inp = readStr();
				print("String length: ");
				printnum(strlength(inp));
			}
			else if(strEql(inp, "clrln"))
			{    
				string start, end;
				uint8 startl, endl;                       		
				print("Enter line number(from): "); 
				start=readStr();
     				startl=atoi(start);
				print("Enter line number(to): "); 
				end=readStr();
				endl=atoi(end);
                       		clearLine(startl,endl);
				print("\n");                   
                	}
			else if(strEql(inp,"prnt"))
                	{      
				int i;				
				print("Enter line to print: ");
                       		inp=readStr();
                       		print(inp);
				print("\n");
                       	
                	}	
			else if(strEql(inp, "upcur"))
			{
				updateCursor();
			}
			else if(strEql(inp,"shut"))
			{
				print("Shutting down MuinOS!\n");
				break;
			}
			else if(strEql(inp,"help"))
			{
				print("\nAvailable commands:\n1.cmd\n2.clrscr\n3.substr\n4.strlen\n5.clrln\n6.prnt\n7.upcur\n8.shut\n9.logout\n10.help\n");
			}
			else if(strEql(inp, "logout"))
			{
				print("\nUser session terminated!\n");
				print("Login to continue");				
				goto sessionStart;
			}			
			else if(strEql(inp,"shut"))
			{
				print("Shutting down MuinOS!\n");
				break;
			}
			else
			{
				print("Bad command!\n");
			}
       }
	return 0;
}

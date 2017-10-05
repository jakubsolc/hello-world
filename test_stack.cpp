
#include <stdio.h>
#include "stack.cpp"

void help()
{
  
  printf("========\n  Help:\n========\n\n");
  printf("  d  ... Stack debug\n");
  printf("  ic ... Stack push c\n");
  printf("  o  ... Stack pop\n");
  printf("  >c ... LIFO push c\n");
  printf("  <  ... LIFO pop\n");
  printf("  D  ... LIFO debug c\n");
  printf("  L  ... LIFO explicitni konstruktor [todo]\n");
  printf("  h  ... help\n");
  printf("  x  ... exit\n");
}  

void test1()
{
  char c;
  Tstack S = Tstack(20);

  S.push('x');
  S.push('y');
  c = S.pop();
  printf("Znak: %c\n", c);
  S.push('z');
  S.debug();
  
}

void test2()
{
  char c;
  char cm[20];
  Tstack S = Tstack(6);
  Tlifo L = Tlifo(6);
  int konec=0;
 
  printf("Help: h\n");
  
  while(1)
  {
    if (fgets(cm,20,stdin) == NULL) break;
    
    switch(cm[0])
    {
      case 'x':
	konec = 1;
	break;
      case 'h':
	help();
	break;
      case 'i':
	S.push(cm[1]);  // defakto muze byt i \n nebo \0, zde zatim OK
	break;
      case'o':
	c = S.pop();
        if (c) printf("Pop: %c\n", c); else printf("Pop: Empty\n"); 
	break;
      case 'd':
	S.debug();
	break;
      case 'L':
	L.debug();
//	L.Tlifo(4);
	L.debug();
	break;

      case '>':
	L.push(cm[1]);  // defakto muze byt i \n nebo \0, zde zatim OK
L.debug();
	break;
      case'<':
	c = L.pop();
        if (c) printf("Pop: %c\n", c); else printf("Pop: Empty\n"); 
L.debug();
	break;
      case 'D':
	L.debug();
	break;
      default:
        printf("Neznamy prikaz: '%c'\n", cm[0]);
    }
    if (konec==1) break;
	
  }
  printf("Koncim.\n");
  
}




int main()
{
  
  
  test2();
  
  return 0;
  
}


#include <stdio.h>


class Tstack
{
  public:
  char *pole;
  unsigned int n;
  unsigned int alloc;
  
  Tstack(unsigned int maxalloc);
  
  void push(char c);
  char pop();
  bool isempty();
  void debug();   
  
};


Tstack::Tstack(unsigned int maxalloc)
{
  n=0;
  pole = new char[maxalloc];
  alloc = maxalloc;
  printf("Alokuji: %d.\n",alloc);
  
}

void Tstack::push(char c)
{
  //todo> test
  if (n<alloc)  pole[n++] = c;
  else printf ("Stack full!\n");
}

char Tstack::pop()
{
  
  return (n>0)?pole[--n]:'\0';
}

bool Tstack::isempty()
{
  
  return (n==0);
}

  
void Tstack::debug()
{
  
  printf("Allocated mem:   %d.\n", alloc);
  printf("Length of stack: %d.\n", n);
  for (int k=0; k<alloc; k++)
  {
    if (k==n) printf("---------------\n");
    printf("%3d: %c\n", k, pole[k]);
  }
}


class Tlifo
{
  
  Tstack *SI=NULL, *SO=NULL;
  
  void presyp();

public:
  Tlifo(unsigned int maxalloc);
  
  void push(char c);
  char pop();
  bool isempty();
  void debug();   
  unsigned length();
  
};

Tlifo::Tlifo(unsigned int maxalloc)
{
  printf("Alokuji LIFO: %d.\n",maxalloc);
  SI = new Tstack(maxalloc);
  SO = new Tstack(maxalloc);
}

void Tlifo::push(char c)
{
  SI->push(c);
}

char Tlifo::pop()
{
  if (SO->isempty()) presyp();  
  return SO->pop();   // empty: vraci '\0'
}

bool Tlifo::isempty()
{
  return (SI->n+SO->n >0);
}

unsigned int Tlifo::length()
{
  return (SI->n + SO->n);
}


void Tlifo::debug()
{
  printf("LIFO Size: %d\n", length());
  if (SI) {
    printf("======\n  ST 1   \n======\n");
    SI->debug();
  }
  else
    printf("Stack 1 UNALLOCATED\n");
  if (SO) {
    printf("======\n  ST 2   \n======\n");
    SO->debug();
  }
  else
    printf("Stack 2 UNALLOCATED\n");
}

void Tlifo::presyp()
{
  int k = SI->n;
  while(k--)
  {
    SO->push(SI->pop());
  }
}


  

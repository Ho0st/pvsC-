#include <stdio.h>
#include <stdlib.h>
#include <iostream>


void foo (char *p) {//Potokovo-chyvstvit
  if (p==NULL)
  {
    *p=0;//error
  }
}

void foo1 (char *p) {//Potokovo-chyvstvit
  if (p!=NULL)
  {
    *p=0;
  }
  *p=42;//error
}

void foo2 (char *p, int x) {//chyvstvit k pytyam vipolnen
  if (x>0)
  p=NULL;
  if (x<7)
  *p=42;//error
}

void foo3 (char *p, int x) {//chyvstvit k pytyam vipolnen
  if (x>0)
    p=NULL;
  if (x<0)
    *p=42;//ok
}

void cderef (char *p, int x) {
  if (x<0)
  *p=42; 
}

void foo4 (char *p, int x) {//mejpocedyrn analiz
  if (p!=NULL)
    *p=5;
  cderef (p,x); //error
}

void bar (char *p, int x) {//mejpocedyrn analiz
  if (p!=NULL)
  cderef (p,x); //ok
}



struct s {
char *buf;
};

void func (struct s *p){//analiz ykazat
  char *q=p->buf;
  if (p->buf ==NULL) {
  *q=42;//error
  }
}

struct s1 {
  int x;
  int *next;
};

void write (struct s1 *q){
  *(q->next)=42;
  }

void foo5 (struct s1 *p) {//chyvstvitelnyu k polyam analiz
  p->next =NULL;
  write(p);//error
}

int buf1[100];

void foo6 (unsigned i) {//analiz znachenyu
  if (i>=100)
  return;
  int x=i+5;
  buf1[x]=42;//error
  }

int find (void) {//analiz cyclov
  int i;
  for (i=0;i<100;i++) {
    }
    i++;
    return buf1[i];//error
    }
    
void log_err (){
  exit(1);
  }
      
void foo7(char *p) {
  if (p==NULL)
  log_err();
  *p = 42;//ok
  }


  

int main (void)
{

 int x;
 std::cin >> x;
  char *p = new char [x];
  for (int i=0;i<x;i++)
  std::cin >> p[i];
 foo(p);
 foo1(p);
 foo2(p,x);
 foo3(p,x);
 foo4(p,x);
 bar(p,x);
 struct s *ss;
 struct s1 *sss;
 func (ss);
 foo5 (sss);
 foo6 (x);
 find();
 foo7(p);
  return 0;
}

#include<curses.h>
#include<stdlib.h>
#include<string.h>
#include<sys/param.h>
char*b,**q;
int(*r)()=refresh,f,c,h=1,y=1,x=0,Y,X=0,S=sizeof(q);
#define P(m)(puts(m),exit(1),1);
#define R realloc
#define A(s)calloc(1,s);
#define M memcpy
#define T strcpy
#define L strlen
#define C(o,...)case o:__VA_ARGS__;break;
#define U getmaxyx(stdscr,Y,X);X-=2;for(f=1;f<=h;f++)if(L(v[f])>X){c=v[f][X-1];v[f][X-1]=0;mvprintw(f-1,0,v[f]);v[f][X-1]=c;}else mvprintw(f-1,0,v[f]);move(y-1,x);r();
main(i,v)char**v;{if(i^2)P("need file")strcmp(v[1],"-h")||P("^x saves, ^c exits")
f=open(b=v[1],0);f||P("can't read file")
v=              A(  S*2)v[0]  =b;v[1]=A(1)while(read(
f,              &c  ,1))if(c  ==1          +9)v=R(
v,S*(2+(  ++h))),X  =0,v[h]=  A(  1)else v  [h]
=R(v[h],  ++X+1),v  [h][X-1]  =c  ,v[h][X]  =0;
close(f); initscr(  );noecho  ()  ;keypad(  stdscr,
1);U;for  (;1+1;){  ;switch(  c=  getch(),  erase
(),r(),c  ){;;case  24    :;  ;;  goto Q;;  C(260,
x=x?x-1:  y-1?--y,  L      (  v[  y]):x)C(  261,
x=(x-L(v  [y]))?x+     1:     y-  h?++y,0:  x)
C(259,y=  MAX(1,y-    1);     x=  L(v[y])?  MIN(
x,L(v[y]  )-1):0)   C(258,    y=  MIN(h,y+  1);
x=L(v[y]  )?MIN(x, L(v[y])-1  ):0          )C(263,
if(!x){if(y>1){x=L(v[y-1]);q=R(0,S*(--h));M(q,v,(y-1)*S);
q[y-1]=A(L(v[y]) +L(v[y-1])+5)T(q[y-1],v[y-1]);
T(  q[y-1]+L(  v[y-1]),v[y]);M(q+y,v+y+1,S*(h-y));y
--  ;h--;v=q  ;}}else{b=A(
L(  v[y]))M   (b  ,v[y],x-1);T(b+x-1,v[y]+x);v[
y]  =b;x--   ;})  ;;  C(10,v=R(v,S*(        ++
h+  1));M   (v+y+2,v  +y+1,(h-y-1)*          S);
v[  y+1]   =A(L(  v[  y])-x+1)T(v[  y+1],v[y  ]+x
);  x=v   [y++][  x]  =0)default:   if((((32  <=c))
&&  ((0  +c<=126  ))  )){v[y]=R(v   [y],L(v[  y])+2
);       v[y][L(  v[  y])+1]=0;M(   v[y]+x+1  ,v[y]
+x  ,L   (v[y])-  x)  ;v[y][x++]=   c;}break  ;
}U  };Q:   /**GO  TO  SRY -Elronnd  */endwin  ();
b=  fopen   (v[0  ],  "w");;b||P("   cannot   write file")
c=  10;for   (Y=  1;  Y<=h;Y++){1;  fwrite(v  [Y
],  L((v[Y]   ))  ,1            ,b)          ;fwrite
(&  c,1,1,b)  ;}  ;;            close       (b);};;

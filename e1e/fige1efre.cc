#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define DB double
#define DO(x,y) for(x=0;x<y;x++)
using namespace std;
#include <complex>
typedef complex<double> z_type;
#define Re(x) x.real()
#define Im(x) x.imag()
#define I z_type(0.,1.)
#include "e1etf.cin"
#include "e1egf.cin"

#include "ado.cin"
#define M(x,y) fprintf(o,"%6.3f %6.3f M\n",0.+x,0.+y);
#define L(x,y) fprintf(o,"%6.3f %6.3f L\n",0.+x,0.+y);
main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d;
FILE *o;o=fopen("fige1efre.eps","w");ado(o,312,192);
fprintf(o,"101 51 translate\n 10 10 scale\n");

for(m=-10;m<21;m++){if(m!=0){M(m,-5)L(m,10)}} 
for(n= -5;n<11;n++){if(n!=0){M(-10,n)L(20,n)}}
fprintf(o,".006 W 0 0 0 RGB S\n");
M(-10,0)L(21,0)
M(0, -5)L(0,11)
fprintf(o,".03 W 0 0 0 RGB S\n");
M(-10,M_E)L(20,M_E)
fprintf(o,".02 W 0 .7 0 RGB S\n");

fprintf(o,"1 setlinejoin 1 setlinecap\n");

DO(m,300){x=-10+.1*m; y=Re(E1EGF(x)); if(m==0) M(x,y) else L(x,y) } 
fprintf(o,".05 W 0 0 1 RGB S\n");

DO(m,220){x=-1.9+.1*m; y=Re(E1ETF(x)); if(m==0) M(x,y) else L(x,y) } 
fprintf(o,".05 W 1 0 0 RGB S\n");
 

//fprintf(o,"0 setlinecap\n"); M(-2,0)L(-8,0) fprintf(o,".08 W 1 1 1 RGB S\n");
//DO(m,16){M(-2-.4*(m),0)L(-2-.4*(m+.5),0)} fprintf(o,".09 W 0 0 0 RGB S\n");
//M(-2,0)L(-10,0) fprintf(o,".04 W 0 0 0 RGB [.1 .1] 1 setdash  S\n");
fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(    "open fige1efre.eps"); //mac
	system("epstopdf fige1efre.eps");
	system(    "xpdf fige1efre.pdf"); // linux

q=1.e-14;
for(n=-10;n<11;n++){z=q*n; y=Re(E1EGF(z)); printf("E1EGF(%20.17f)=%20.17f\n",q*n,y);}

//getchar(); system("killall Preview");// mac
}

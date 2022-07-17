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
//#include "superlo.cin"
#include "fslog.cin"
#include "conto.cin"
main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;
//z_type Zo=z_type(.31813150520476413, 1.3372357014306895);
//z_type Zc=z_type(.31813150520476413,-1.3372357014306895);

  int M=400,M1=M+1;
  int N=364,N1=N+1;
DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
char v[M1*N1]; // v is working array
FILE *o;o=fopen("figvladi02b.eps","w");ado(o,202,122);
fprintf(o,"101 61 translate\n 10 10 scale\n");

z_type L=z_type(.31813150520476413, 1.3372357014306895);
p=Re(L); q=Im(L); DB R=abs(L); DB A=arg(L);
fprintf(o,"0 0 %9.6f %9.6f %9.6f arc C .5 1 0 RGB F\n",R,-180/M_PI*A,180/M_PI*A);

  DB sx=8./sinh(.01*M);
  DO(m,M1) X[m]=sx*sinh(.02*(m-M/2));
 for(n=0;n<N1;n++){y =-5.  +.03*(n-.5); if(y>-Im(L)) break; Y[n]=y;}
  m=n; y=-Im(L)-.001; Y[m]=y;
  m++; y=-Im(L)+.001; Y[m]=y;
for(n=m+1;n<N1;n++){y =-5. +.03*(n-2-.5); if(y>Im(L)) break; Y[n]=y;}
  m=n; y=Im(L)-.001; Y[m]=y;
  m++; y=Im(L)+.001; Y[m]=y;
for(n=m+1;n<N1;n++){y =-5. +.03*(n-4-.5);  Y[n]=y;}

for(m=-8;m<9;m++) {	if(m==0){M(m,-5.2)L(m,5.2)}
			else	{M(m,-5)L(m,5)}			}
for(n=-5;n<6;n++) {M(  -8,n)L(8,n)} fprintf(o,".006 W 0 0 0 RGB S\n");

DO(m,M1)DO(n,N1){	g[m*N1+n]=9999;
			f[m*N1+n]=9999;	}
z_type F[M1*N1];
DO(m,M1){x=X[m]; printf("50 run at x=%6.3f\n",x);
DO(n,N1){y=Y[n]; z=z_type(x,y);
	 c=FSLOG(z);	p=Re(c); q=Im(c);
	if(p>-999 && p<999 && fabs(p)> 1.e-8 && fabs(p-1.)>1.e-8) 	g[m*N1+n]=p;
	if(q>-999 && q<999 && fabs(q)> 1.e-8) 				f[m*N1+n]=q;
	}}

p=1;q=.5;
#include"plofu.cin"
M(Re(L), Im(L)) L(-10, Im(L)) 
M(Re(L),-Im(L)) L(-10,-Im(L)) fprintf(o,".1 W 1 1 1 RGB  S\n");

DO(m,17){ M(Re(L)-.5*m, Im(L))  L(Re(L)-.5*(m+.5), Im(L))}
DO(m,17){ M(Re(L)-.5*m,-Im(L))  L(Re(L)-.5*(m+.5),-Im(L))}
fprintf(o,".1 W 0 0 0 RGB S\n");

// fprintf(o,".1 W 0 0 0 RGB [.12 .14] 1 setdash  S\n");
fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(    "open figvladi02b.eps");//macintosh
	system("epstopdf figvladi02b.eps");
	system(    "xpdf figvladi02b.pdf");//linux
//getchar(); system("killall Preview");//macintosh
}

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

//#include "tetration.cin"
//#include "superex.cin"
//#include "superlo.cin"
#include "fsexp.cin"
#include "fslog.cin"
#include "conto.cin"
main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;
//z_type Zo=z_type(.31813150520476413, 1.3372357014306895);
//z_type Zc=z_type(.31813150520476413,-1.3372357014306895);

  int M=400,M1=M+1;
  int N=201,N1=N+1;
DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
char v[M1*N1]; // v is working array
FILE *o;o=fopen("figvladi02a.eps","w");ado(o,202,122);
fprintf(o,"101 61 translate\n 10 10 scale\n");

DO(m,M1) X[m]=-8.+.04*(m-.5);

DB sy=5./sinh(.01*N);
DO(n,N1) Y[n]=sy*sinh(.02*(n-(N-1)/2-.5));

for(m=-20;m<21;m++){ z=z_type(Re(Zo),Im(Zo)*m/20.009); c=FSLOG(z); x=Re(c);  y=Im(c); if(m==-20)M(x,y)else L(x,y) }
for(m=20;m>-21;m--){ z=z_type(Re(Zo),Im(Zo)*m/20.009); c=FSLOG(z); x=Re(c)+1;y=Im(c);                      L(x,y) }
fprintf(o,".6 1 0 RGB F\n");

for(m=-8;m<9;m++) {	if(m==0){M(m,-5.2)L(m,5.2)} else	{M(m,-5)L(m,5)}			}
for(n=-5;n<6;n++) {	M(  -8,n)L(8,n)}
fprintf(o,".006 W 0 0 0 RGB S\n");

DO(m,M1)DO(n,N1){g[m*N1+n]=9999; f[m*N1+n]=9999;}

DO(m,M1){x=X[m]; printf("run at x=%6.3f\n",x);
DO(n,N1){y=Y[n]; z=z_type(x,y);
	if(x>5.99 && fabs(y)<1.)goto reducesize;//reduce size of the picture
	 c=FSEXP(z);	p=Re(c); q=Im(c);
	if(p>-8.5 && p<8.5 && fabs(p)> 1.e-6 && fabs(p-1.)>1.e-6 &&
	  q >-8.5 && q<8.5 && fabs(q)> 1.e-6) { g[m*N1+n]=p; f[m*N1+n]=q; }
	reducesize:; 
	}}

p=1;q=.5;
	conto(o,g,w,v,X,Y,M,N, ( Re(Zo) ),-q,q); fprintf(o,".1 W 1 .5 1 RGB S\n");
	conto(o,f,w,v,X,Y,M,N, ( Im(Zo) ),-q,q); fprintf(o,".1 W .2 1 .4 RGB S\n");
	conto(o,f,w,v,X,Y,M,N, (-Im(Zo) ),-q,q); fprintf(o,".1 W .4 1 .2 RGB S\n");

fprintf(o,"1 setlinejoin 1 setlinecap\n");

#include"plofu.cin"
fprintf(o,"0 setlinecap\n");
M(-2,0)L(-8,0) fprintf(o,".08 W 1 1 1 RGB S\n");
DO(m,16){M(-2-.4*(m),0)L(-2-.4*(m+.5),0)} fprintf(o,".09 W 0 0 0 RGB S\n");
//M(-2,0)L(-10,0) fprintf(o,".04 W 0 0 0 RGB [.1 .1] 1 setdash  S\n");
fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(    "open figvladi02a.eps"); //mac
	system("epstopdf figvladi02a.eps");
	system(    "xpdf figvladi02a.pdf"); // linux
//getchar(); system("killall Preview");// mac
}

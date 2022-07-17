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
#include "e1eti.cin"
#include "conto.cin"
main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d;
 int M=201,M1=M+1;
 int N=201,N1=N+1;
DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
char v[M1*N1]; // v is working array
FILE *o;o=fopen("fige1etfi.eps","w");ado(o,202,202);
fprintf(o,"101 101 translate\n 10 10 scale\n");
DO(m,M1) X[m]=-10.+.1*(m-.5);
DO(n,N1) Y[n]=-10.+.1*(n-.5);
for(m=-10;m<11;m++){ if(m==0){M(m,-10.2)L(m,10.2)} else {M(m,-10)L(m,10)}			}
for(n=-10;n<11;n++){ M(-10,n)L(10,n)}
fprintf(o,".006 W 0 0 0 RGB S\n");
DO(m,M1)DO(n,N1){g[m*N1+n]=9999; f[m*N1+n]=9999;}
DO(m,M1){x=X[m]; printf("run at x=%6.3f\n",x);
DO(n,N1){y=Y[n]; z=z_type(x,y);
	c=E1ETI(z);
	c=E1ETF(c);
	d=z;
	p=abs(c-d)/abs(c+d); p=-log(p)/log(10.);	
//	p=Re(c); q=Im(c);
	if(p>-85 && p<85)  g[m*N1+n]=p;
//	if(p>-33 && p<33 && fabs(p)> 1.e-9 && fabs(p-1.)>1.e-9 &&
//	  q >-33 && q<33 && fabs(q)> 1.e-9) { g[m*N1+n]=p; f[m*N1+n]=q; }
	}}

fprintf(o,"1 setlinejoin 1 setlinecap\n");
p=1.;q=.5;
#include"plodi.cin"

/*
fprintf(o,"0 setlinecap\n");
M(-2,0)L(-8,0) fprintf(o,".08 W 1 1 1 RGB S\n");
DO(m,16){M(-2-.4*(m),0)L(-2-.4*(m+.5),0)} fprintf(o,".09 W 0 0 0 RGB S\n");
*/
fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(    "open fige1etfi.eps"); //mac
	system("epstopdf fige1etfi.eps");
	system(    "xpdf fige1etfi.pdf"); // linux
//getchar(); system("killall Preview");// mac
}

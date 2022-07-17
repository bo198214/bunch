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
 #include "conto.cin"
DB T22=-8.5715740896774235522;
DB T42= 9.6180745210214273558;
#include "f43L.cin"
/////////////////////////////////////
 main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;
 int M=201,M1=M+1;
 int N=201,N1=N+1;
 DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
 char v[M1*N1]; // v is working array
 FILE *o;o=fopen("f43L.eps","w");  ado(o,214,212);
 fprintf(o,"112 110 translate\n 10 10 scale\n");
  DO(m,M1) X[m]=-10.+.1*(m-.5);
  DO(n,N1) Y[n]=-10.+.1*(n-.5);
 for(m=-10;m<11;m++) {M(m,-10)L(m,10)}
 for(n=-10;n<11;n++) {M(  -10,n)L(10,n)} fprintf(o,".006 W 0 0 0 RGB S\n");
 fprintf(o,"/adobe-Roman findfont 1 scalefont setfont\n");
 for(m=-8;m<0;m+=2) {M(-11.0,m-.3) fprintf(o,"(%1d)s\n",m);}
 for(m= 0;m<9;m+=2) {M(-10.7,m-.3) fprintf(o,"(%1d)s\n",m);}
 for(m=-8;m<0;m+=4) {M(m-.6,-10.8) fprintf(o,"(%1d)s\n",m);}
 for(m= 0;m<9;m+=4) {M(m-.3,-10.8) fprintf(o,"(%1d)s\n",m);}
 fprintf(o,"/Times-Italic findfont 1 scalefont setfont\n");
 //fprintf(o,"/adobe-italic findfont 1 scalefont setfont\n");
 M(-10.7,  9.5) fprintf(o,"(y)s\n");
 M(  9.6,-10.8) fprintf(o,"(x)s\n");
// M(-11,0)L(10.1,0) M(0,-11)L(0,10.1) fprintf(o,".01 W 1 0 1 RGB S\n");
 //z_type tm,tp,F[M1*N1];; 
 DO(m,M1)DO(n,N1){	g[m*N1+n]=9999;
 			f[m*N1+n]=9999;}
DB b=sqrt(2);
 DO(m,M1){x=X[m]; 
 DO(n,N1){y=Y[n]; z=z_type(x,y);	
	c=F43L(z); 
	p=Re(c); q=Im(c);
	if(p>-11 && 11 && q>-11 && q<11 && fabs(q)>1.e-14)  
		{g[m*N1+n]=p;f[m*N1+n]=q;}
 	}}
p=2; q=1.1;
#include "plofue.cin"

M(2, 0)L(-11.,0)	M(4,0)L(10.1,0)	fprintf(o,".04 W 1 1 1 RGB S\n");
DO(n,40){M(2-.3*n, 0)L(2-.3*(n+.5),0)}
DO(n,20){M(4+.3*n, 0)L(4+.3*(n+.5),0)}
 					fprintf(o,".1 W 0 0 0 RGB S\n");

 fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(      "gv f43L.eps &"); //for UNIX
// 	system(    "open f43L.eps"); //for macintosh
 	system("epstopdf f43L.eps"); 
 	system(    "xpdf f43L.pdf"); // for LINUX 
// 	getchar(); system("killall Preview"); // For macintosh
}

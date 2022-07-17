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
// #include "uq2e.cin"
#include "f45E.cin"
/*
z_type f45E(z_type z){int n; z_type e,s;
DB coeu[21]={1.,
 0.44858743119526122890, .19037224679780675668, 
 0.77829576536968278770e-1, 0.30935860305707997953e-1, 
 0.12022125769065893274e-1, 0.45849888965617461424e-2,
 0.17207423310577291102e-2, 0.63681090387985537364e-3,
 0.23276960030302567773e-3, 0.84145511838119915857e-4,
 0.30115646493706434120e-4, 0.10680745813035087964e-4,
 0.37565713615564248453e-5, 0.13111367785052622794e-5,
 0.45437916254218158081e-6, 0.15642984632975371803e-6,
 0.53523276400816416929e-7, 0.18207786280204973113e-7,  
 0.61604764947389226744e-8, 0.2e-8};
// 	e=exp(.32663425997828098238*(z-1.1152072451316117));	
 	e=exp(.32663425997828098238*(z-1.11520724513161));	
 	s=coeu[20]; for(n=19;n>=0;n--) { s*=e; s+=coeu[n]; } 
 	return 4.+s*e;}
 z_type F45E(z_type z){ DB b=sqrt(2.);
			if(Re(z)<-1.) return f45E(z);
  			return exp(F45E(z-1.)*log(b));
		}
*/
 main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;
 p=1.e-15;
for(n=-10;n<11;n+=2) {q=p*n; z=z_type(q,0.); printf("%19.15f %19.16f\n",q,  Re(F45E(z))  ); }
//getchar();
 int M=201,M1=M+1;
 int N=201,N1=N+1;
 DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
 char v[M1*N1]; // v is working array
FILE *o;o=fopen("f45E.eps","w");  ado(o,214,212);
 fprintf(o,"112 110 translate\n 10 10 scale\n");
// DB sy=10.1/sinh(N/2./200.);
 DO(m,M1) X[m]=-10+.1*(m-.5);
 DO(n,N1) Y[n]=-10+.1*(n-.5);
// DO(n,N1) Y[n]=sy*sinh((n-N/2.+.5)/200.);
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
 z_type tm,tp,F[M1*N1];; 
 DO(m,M1)DO(n,N1){	g[m*N1+n]=9999;
 			f[m*N1+n]=9999;}
 DO(m,M1){x=X[m]; int m1;
 DO(n,N1){y=Y[n]; z=z_type(x,y);	
 	c=F45E(z);
 	p=Re(c); q=Im(c);
 	if(p>-12 && p<12 && q>-12 && q<12 && fabs(q)>1.e-13 ){g[m*N1+n]=p;f[m*N1+n]=q;}
 	}}
p=2; q=1.1;
 #include "plofue.cin"

//M(-10,0)L(-2,0)fprintf(o,".04 W 1 0 1 RGB S\n");
//M(4,0)L(-10.1,0)fprintf(o,".12 W 0 0 0 RGB [.2 .2] 0 setdash S\n");
 fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
 //	system(    "open f45E.eps"); //for macintosh
 	system("epstopdf f45E.eps"); 
 	system(    "xpdf f45E.pdf"); // for LINUX 
//	getchar(); system("killall Preview"); // For macintosh
}

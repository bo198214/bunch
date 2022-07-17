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
#include "f23E.cin"
/*
// z_type tq2e3(z_type z){int n; z_type e,s;  DB coefd[24];
 z_type f23E(z_type z){int n; z_type e,s;  DB coefd[24];
 DB coef[24]= {			-1.,                           // 0 (first power coeff)
 0.56472283831773236365,	-0.33817758685118329988,       // 2
 0.21033130213862776975,	-0.13445487905210979672,       // 4
 0.087784388601219137357,	-0.058288093083094691542,      // 6
 0.039240711783727838328,	-0.026723286034298143846,      // 8
 0.018376520597637595915,	-0.012742089846776647861,      //10
 0.0088986329515697318595,	-0.0062531995639748853846,     //12
 0.0044181328624396520598,	-0.0031365295362695967035,     //14
 0.0022361213774486947923,	-0.0016001999145218074082,     //16
 0.0011489818761273047343,	-0.00082749213843167597835,    //18
 0.00059758321720686253893,	-0.00043261919624398863166,    //20
	 0.0003158,		-0.00023  , .00017     //last 2 are doubtful.
 };
 e=exp(-0.36651292058166432701*(z-2.131917787095039));
 s=coef[23];
 for(n=22;n>=0;n--) { s*=e; s+=coef[n]; }
 return 2.-s*e;
 }

// z_type TQ2E3(z_type z){ if(Re(z)>5.) return tq2e3(z);
//                         return log(TQ2E3(z+1.))/log(sqrt(2.));  }
 z_type F23E(z_type z){ if(Re(z)>5.) return f23E(z);
                         return log(F23E(z+1.))/log(sqrt(2.));  }

	//	(0,3) superfunction of exp_{sqrt{2}}
//////////////////////////////////////////////////////////
*/
 main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;
 int M=201,M1=M+1;
 int N=401,N1=N+1;
 DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
 char v[M1*N1]; // v is working array
 FILE *o;o=fopen("f23E.eps","w");  ado(o,214,212);
 fprintf(o,"112 110 translate\n 10 10 scale\n");
  DO(m,M1) X[m]=-10.+.1*(m-.5);
  DO(n,N1) Y[n]=-10.+.05*(n-.3);
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
	//c=TQ2L3(z); 
	c=F23E(z);
	p=Re(c); q=Im(c);
	if(p>-11 && p<11 & q>-11 && q<11 && fabs(q)>1.e-14){g[m*N1+n]=p;f[m*N1+n]=q;}
 	}}
p=2.; q=1; 
#include "plofue.cin"

  y=M_PI/log(log(2));

	M(1.33, y)L(-10.2, y)
	M(1.33,-y)L(-10.2,-y) fprintf(o,".09 W 1 1 1 RGB S\n");
DO(n,38){M(1.33-.3*n, y)L(1.33-.3*(n+.5), y)}
DO(n,38){M(1.33-.3*n,-y)L(1.33-.3*(n+.5),-y)}
				fprintf(o,".11 W 0 0 0 RGB S\n");

 fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
// 	system(    "open f23E.eps"); //for macintosh
 	system("epstopdf f23E.eps"); 
 	system(    "xpdf f23E.pdf"); // for LINUX 
//	getchar(); system("killall Preview"); // For macintosh
}

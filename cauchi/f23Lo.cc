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
 //#include "tq2e3.cin"
//#include "tq2L3.cin"
//z_type tq2L3(z_type z){ int n; z_type e,s,k;
z_type f23L(z_type z){ int n; z_type e,s,k;
DB TcL[23]={1.,   //coeff. of expansion of exp(-q(z+1.2 ...) by powers of (2-F).
 -.56472283831773236365,	0.29964618138408807683, 
 -.15593239048925425850,	0.8035187974815443609e-1,
 -0.411584960662439279e-1,	0.2099852095441203541e-1,
 -0.1068258032026355653e-1,	0.542288102231591005e-2,
 -0.2748252661868267e-2,	0.13909151872677962e-2,
 -0.703181586212482131e-3,	0.35517006776480e-3,
 -0.1792537427481520668e-3,	0.9040887657183e-4,
 -0.45572543028501136e-4,	0.2296022632181e-4,
 -0.1156277075032e-4,		0.5820169657e-5,
	-0.291e-5,		0.144e-5, -.71e-6 };
z=2.-z;  s=TcL[22]; for(n=21; n>=0; n--){ s*=z; s+=TcL[n]; }
//return -log(s*z)/0.36651292058166432701 -1.251551478822190;};
  return -log(-s*z)/0.36651292058166432701+2.131917787095039;};
		//.32663425997828098238; 

//z_type TQ2L3(z_type z){ DB b=sqrt(2.);	 if(abs(z-2.)>9999.) return 9999.;
z_type F23L(z_type z){ DB b=sqrt(2.);	 if(abs(z-2.)>9999.) return 9999.;
			if(abs(z-2.)>.4) return F23L(exp(z*log(b)))-1. ;
			 return f23L(z);	}
/////////////////////////////////////
 main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;
 int M=201,M1=M+1;
 int N=201,N1=N+1;
 DB X[M1],Y[N1], g[M1*N1],f[M1*N1], w[M1*N1]; // w is working array.
 char v[M1*N1]; // v is working array
 FILE *o;o=fopen("f23Lo.eps","w");  ado(o,214,212);
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
	c=F23L(z); 
	p=Re(c); q=Im(c);
	if(p>-11 && p<11 && q>-11 && q<11 && fabs(q)>1.e-14){g[m*N1+n]=p;f[m*N1+n]=q;}
 	}}
p=2; q=1.1;
	conto(o,f,w,v,X,Y,M,N, ( 8.5   ), -2,2); fprintf(o,".02 W 0 .3 0.2 RGB S\n");
	conto(o,f,w,v,X,Y,M,N, ( 8.55  ), -2,2); fprintf(o,".02 W 0 .3 0.2 RGB S\n");
//	conto(o,f,w,v,X,Y,M,N, ( 8.57  ), -2,2); fprintf(o,".02 W 0 .3 0.2 RGB S\n");
	conto(o,f,w,v,X,Y,M,N, (-8.5   ), -2,2); fprintf(o,".02 W 0.2 .3 0 RGB S\n");
	conto(o,f,w,v,X,Y,M,N, (-8.55  ), -2,2); fprintf(o,".02 W 0.2 .3 0 RGB S\n");
//	conto(o,f,w,v,X,Y,M,N, (-8.57  ), -2,2); fprintf(o,".02 W 0.2 .3 0 RGB S\n");
#include "plofue.cin"

// p=1.e-15;
// for(n=-10;n<11;n++) {q=p*n; z=z_type(q,0.); printf("%19.15f %19.15f\n",q,  Re(TQ2E(z))  ); }

 
//y=2*M_PI/log(2.);
y=9.064720284;
	M(-10.1, y)L(10.1, y)
	M(-10.1,-y)L(10.1,-y)
//M(1.5, T22)L(-10.1, T22)
//M(1.5,-T22)L(-10.1,-T22)
//M(4, 0)L(10.1, 0)  M(2, 0)L(-10.1, 0) 
M(2, 0)L(-11.,0)	M(4,0)L(10.1,0)	fprintf(o,".08 W 1 1 1 RGB S\n");
DO(n,40){M(2-.3*n, 0)L(2-.3*(n+.5),0)}
DO(n,20){M(4+.3*n, 0)L(4+.3*(n+.5),0)}

DO(n,67){M(-10.1+.3*n, y)L(-10.1+.3*(n+.5),y)}
DO(n,67){M(-10.1+.3*n, -y)L(-10.1+.3*(n+.5),-y)}
 					fprintf(o,".11 W 0 0 0 RGB S\n");

//M(2, 0)L(-11.,0)M(4,0)L(10.1,0)fprintf(o,".1 W 0 0 0 RGB [.14 .14] 0 setdash S\n");

//M(-10,0)L(-2,0)fprintf(o,".04 W 1 0 1 RGB S\n");
 fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(      "gv f23Lo.eps &"); //for UNIX
// 	system(    "open f23Lo.eps"); //for macintosh
 	system("epstopdf f23Lo.eps"); 
 	system(    "xpdf f23Lo.pdf");// for linux 
 	getchar(); system("killall Preview"); // For macintosh
}

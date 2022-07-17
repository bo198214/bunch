#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define DB double
using namespace std;
#include <complex>
typedef complex<double> z_type;
#define Re(x) x.real()
#define Im(x) x.imag()
z_type Zo=z_type(.31813150520476413, 1.3372357014306895);
#include"ado.cin"
/*
void ado(FILE *O, int X, int Y)
{	fprintf(O,"%c!PS-Adobe-2.0 EPSF-2.0\n",'%');
	fprintf(O,"%c%cBoundingBox: 0 0 %d %d\n",'%','%',X,Y);
	fprintf(O,"/M {moveto} bind def\n");
	fprintf(O,"/L {lineto} bind def\n");
	fprintf(O,"/S {stroke} bind def\n");
	fprintf(O,"/s {show newpath} bind def\n");
	fprintf(O,"/C {closepath} bind def\n");
	fprintf(O,"/F {fill} bind def\n");
	fprintf(O,"/o {.8 0 360 arc C F} bind def\n");
	fprintf(O,"/times-Roman findfont 6 scalefont setfont\n");
	fprintf(O,"/W {setlinewidth} bind def\n");
	fprintf(O,"/RGB {setrgbcolor} bind def\n");}
*/
z_type lob(DB LB)
	{	int n; z_type s0,s1;
	 	s0=z_type(1.,1.); s1=s0;
		for(n=0;n<800;n++)
		{ //if( fabs(s0-s1) < 1.e-14) break;
		  s0=s1; s1=log(s1)/LB;
	}
//	printf("lob, %6.3f :  %6.3f +i* %6.3f\n",LB,Re(s1),Im(s1) );
	return s1;
	}
		
main(){ FILE *o; o=fopen("fig02a.eps","w"); ado(o,230,100);
	fprintf(o,"/o {.8 0 360 arc C F} bind def\n");
	fprintf(o,"/times-Roman findfont 6 scalefont setfont\n");
fprintf(o,"10 20 translate\n");
#define M(x,y) fprintf(o,"%5.2f %5.2f M\n",100.*(x),10.*(y));
#define L(x,y) fprintf(o,"%5.2f %5.2f L\n",100.*(x),10.*(y));
#define o(x,y) fprintf(o,"%5.2f %5.2f o\n",100.*(x),10.*(y));
M(0,-.5)L(0,7) M(0,0)L(2.1,0) fprintf(o,".2 W S\n");
int n; DB x,y;
M(-.06,M_E)L(2,M_E)
for(n=0;n<7;n++){M(0,n)L(2,n)}  fprintf(o,".1 W S\n");
for(n=0;n<7;n++){M(-.04,n-.18) fprintf(o,"(%1d)s\n",n);}
M(-.09,M_E-.16) fprintf(o,"(e)s\n");

M(log(2.)/2,-1)L(log(2.)/2,6) 
M(1./M_E,   -1.6)L(1./M_E,  6) 
M(log(2.),   -.9)L(log(2.),  6) 
for(n=0;n<21;n++){x=.1*n;M(x,0)L(x,6)}
fprintf(o,".2 W S\n"); 
for(n=2;n<21;n+=2){x=.1*n;M(x-.04,-.6) fprintf(o,"(%3.1f)s\n",x);}
M(log(2.)/2 -.17,-1.2)	fprintf(o,"(ln[2]/2)s\n");
M(1./M_E  -.03  , -1.8) 	fprintf(o,"(1/e)s\n");
M(log(2.)  -.05  , -1.) 	fprintf(o,"(ln[2])s\n");

DB L; z_type LB;  M(0,1);
for(n=11;n<70;n++){y=.1*n; x=log(y)/y; L(x,y)}
fprintf(o,"1 setlinecap 1 setlinejoin 1 W  0 0 0 RGB S\n");

M(1/M_E,M_E)
for(n=2;n<170;n+=2) {x=1./M_E+0.01*n;  z_type Lb;  Lb=lob(x);
 	printf("lob(%6.3f)=  %6.3f +i* %6.3f\n",x,Re(Lb),Im(Lb) );
	 y=Re(Lb); // if(n/4*4==n)  M(x,y) else 
	L(x,y) 	}
fprintf(o,".3 W 0 0 1 RGB S\n");

fprintf(o,"0 setlinecap\n");

//M(1./M_E,M_E)
for(n=88;n>0;n-=1) {x=1./M_E+0.001*n*n/(1+.04*n);  z_type Lb;  Lb=lob(x);
 	printf("lob(%6.3f)=  %6.3f +i* %6.3f\n",x,Re(Lb),Im(Lb) );
	 y=Im(Lb); 
	if(n/2*2==n)M(x,y) else L(x,y) }
fprintf(o,"1 0 0 RGB 0.8 W S\n");

M(1./M_E,.1)
L(1./M_E,-.1)
for(n=1;n<89;n+=1) {x=1./M_E+0.001*n*n/(1+.04*n);  z_type Lb;  Lb=lob(x);
 	printf("lob(%6.3f)=  %6.3f +i* %6.3f\n",x,Re(Lb),Im(Lb) );
	 y=Im(-Lb);  if(n/2*2==n)L(x,y) else M(x,y)   	}
fprintf(o,"1 0 0 RGB S\n");

for(n=0;n<20;n++){x=.05/M_E*n; if(n/2*2==n)M(x,0) else L(x,0)}

fprintf(o,"1 0 0 RGB S\n");


/* does not work 
M(2,0) fprintf(o,"0 0 0 RGB (ln[  ])s\n");
//fprintf(o,"/Adobe-Italics findfont 6 scalefont setfont\n");
fprintf(o,"/Adobe-Slant  findfont 6 scalefont setfont\n");
M(2,0) fprintf(o,"(   b )s\n");
*/
fprintf(o,"showpage\n");
fprintf(o,"%cTrailer\n",'%');
fclose(o);
//	system(    "open fig02a.eps");// for macintosh
	system("epstopdf fig02a.eps");
	system(    "xpdf fig02a.pdf");// for linux
//	getchar(); system("killall Preview");// for macintosh
}

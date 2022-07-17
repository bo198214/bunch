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
#include "f4binary.cin"
void ado(FILE *O, int X, int Y)
{	fprintf(O,"%c!PS-Adobe-2.0 EPSF-2.0\n",'%');
	fprintf(O,"%c%cBoundingBox: 0 0 %d %d\n",'%','%',X,Y);
	fprintf(O,"/M {moveto} bind def\n");
	fprintf(O,"/L {lineto} bind def\n");
	fprintf(O,"/S {stroke} bind def\n");
	fprintf(O,"/s {show newpath} bind def\n");
	fprintf(O,"/C {closepath} bind def\n");
	fprintf(O,"/F {fill} bind def\n");
	fprintf(O,"/o {.1 0 360 arc C S} bind def\n");
	fprintf(O,"/times-Roman findfont .4 scalefont setfont\n");
	fprintf(O,"/W {setlinewidth} bind def\n");
	fprintf(O,"/RGB {setrgbcolor} bind def\n");}
main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;

//DO(j,20){ x=-1.6+.2*j; z=x; c=F4binary(z); printf("%5.2f %8.3f %8.4f\n",x, Re(c),Im(c));}
 printf("Output  fig01b.eps\n");
FILE *o;o=fopen("fig01b.eps","w");ado(o,45,65);
fprintf(o,"22 21 translate 10 10 scale\n");
#define M(x,y) fprintf(o,"%6.3f %7.4f M\n",1.*x,1.*y);
#define L(x,y) fprintf(o,"%6.3f %7.4f L\n",1.*x,1.*y);

for(n=-2;n<3;n++){ if(n!=0){ M(n,-2)L(n,4)}}
for(n=-2;n<5;n++){ if(n!=0){ M(-2,n)L(2,n)}}
fprintf(o,".003 W S\n");

//fprintf(o,"1 setlinejoin\n 1 setlinecap\n");
M(-2.1,   0) L(2.2, 0  )
M(   0,-2.1) L(0,  4.2)
fprintf(o,".01 W S\n");
for(n=-2;n< 3;n++){ if(n!=0){ M( n-.2,-.3) fprintf(o,"(%2d)s\n",n);} }
for(n=-2;n< 5;n++){ if(n!=0){ M(  -.4, n-.11) fprintf(o,"(%2d)s\n",n);} }

//M(-.5,-.5) L(.5,-.5) L(.6,-.6)
//fprintf(o,"1 setlinejoin 1 setlinecap .1 W 0 0 1 RGB S\n");

DO(j,79){ x=-1.8+.05*j; z=x; c=F4binary(z); y=Re(c);
	   printf("%5.2f %8.3f %8.4f\n",x, y,Im(c));
 	if(j/2*2==j) M(x,y) else L(x,y)
	}
//fprintf(o,"1 setlinejoin 1 setlinecap .1 W 0 0 .8 RGB S\n");
fprintf(o,".014 W 0 0 .8 RGB S\n");

fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(      "gv fig01b.eps"); // for unix
//	system(    "open fig01b.eps"); for macintosh
	system("epstopdf fig01b.eps");
	system(    "xpdf fig01b.pdf"); // for LINUX
//getchar(); system("killall Preview");//for macontosh
}

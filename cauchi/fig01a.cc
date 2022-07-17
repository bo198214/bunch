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
z_type F4q(z_type z)
//{ if(Re(z)>10) return 2.-exp(-0.36651292058166432701*z-.452);
{ if(Re(z)>10) return 2.-exp(-0.36651292058166432701*z-.451);
  return log(F4q(z+1.))/log(sqrt(2.));
}
z_type F4ee(z_type z)
{
//  if(Re(z)>20) return M_E-2*M_E/(z+3.78);
//  if(Re(z)>20) return M_E-2*M_E/(z+3.87);
    if(Re(z)>100) return M_E-2*M_E/(z+4.33);
  return M_E*log(F4ee(z+1.));
}
void ado(FILE *O, int X, int Y)
{	fprintf(O,"%c!PS-Adobe-2.0 EPSF-2.0\n",'%');
	fprintf(O,"%c%cBoundingBox: 0 0 %d %d\n",'%','%',X,Y);
	fprintf(O,"/M {moveto} bind def\n");
	fprintf(O,"/L {lineto} bind def\n");
	fprintf(O,"/S {stroke} bind def\n");
	fprintf(O,"/s {show newpath} bind def\n");
	fprintf(O,"/C {closepath} bind def\n");
	fprintf(O,"/F {fill} bind def\n");
	fprintf(O,"/o {.016 0 360 arc C F} bind def\n");
	fprintf(O,"/times-Roman findfont .4 scalefont setfont\n");
	fprintf(O,"/W {setlinewidth} bind def\n");
	fprintf(O,"/RGB {setrgbcolor} bind def\n");}
main(){ int j,k,m,n; DB x,y, p,q, t; z_type z,c,d, cu,cd;

//DO(j,20){ x=-1.6+.2*j; z=x; c=F4(z); printf("%5.2f %8.3f %8.4f\n",x, Re(c),Im(c));}
 printf("Output  fig01a.eps\n");
FILE *o;o=fopen("fig01a.eps","w");ado(o,70,65);
fprintf(o,"22 21 translate 10 10 scale\n");
#define M(x,y) fprintf(o,"%6.3f %7.4f M\n",1.*x,1.*y);
#define L(x,y) fprintf(o,"%6.3f %7.4f L\n",1.*x,1.*y);
#define o(x,y) fprintf(o,"%6.3f %7.4f o\n",1.*x,1.*y);

for(n=-2;n<5;n++){ if(n!=0){ M(n,-2)L(n,4)}}
for(n=-2;n<5;n++){ if(n!=0){ M(-2,n)L(4,n)}}
fprintf(o,".003 W S\n");

//fprintf(o,"1 setlinejoin\n 1 setlinecap\n");
M(-2.1,   0) L(4.2, 0  )
M(   0,-2.1) L(0,  4.2)
fprintf(o,".01 W S\n");
for(n=-2;n< 5;n++){ if(n!=0){ M( n-.2,-.3) fprintf(o,"(%2d)s\n",n);} }
for(n=-2;n< 5;n++){ if(n!=0){ M(  -.4, n-.11) fprintf(o,"(%2d)s\n",n);} }

//M(-.5,-.5) L(.5,-.5) L(.6,-.6)
//fprintf(o,"1 setlinejoin 1 setlinecap .1 W 0 0 1 RGB S\n");

fprintf(o,".01 W 1 0 0 RGB S\n");
DB xq=0;
//DO(j,10){ xq-=0.77*Re(F4q(xq-1.)); printf("%10.14f\n",x0);}
fprintf(o,"1 0 0 RGB\n");
DO(j,156){ x=-1.64+.04*j; z=x; c=F4q(xq+z); y=Re(c); o(x,y)
	   printf("%5.2f %8.3f %8.4f\n",x, y,Im(c));
//	if(j==0) M(x,y) else L(x,y)
	}
//fprintf(o,"1 setlinejoin 1 setlinecap .1 W 0 0 .8 RGB S\n");
//fprintf(o,".01 W 0 0 0 RGB S\n");


DB x0=0;
DO(j,10){ x0-=0.76*Re(F4ee(x0-1.)); printf("%10.14f\n",x0);}
fprintf(o,"1 0 0 RGB\n");
DO(j,156){ x=-1.68+.04*j; z=x; c=F4ee(x0+z); y=Re(c);
//	   printf("%5.2f %8.3f %8.4f\n",x, y,Im(c));
	if(j==0) M(x,y) else L(x,y)
	}
//fprintf(o,"1 setlinejoin 1 setlinecap .1 W 0 0 .8 RGB S\n");
fprintf(o,".006 W 0 .5 0 RGB S\n");

fprintf(o,"showpage\n\%\%\%Trailer"); fclose(o);
//	system(      "gv fig01a.eps");//for UNIX
//	system(    "open fig01a.eps"); for macintosh
	system("epstopdf fig01a.eps");
	system(    "xpdf fig01a.pdf"); // for LINUX
//getchar(); system("killall Preview");	//for macintosh
}


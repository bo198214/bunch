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
#include "ado.cin"

z_type lob(DB LB){int n; z_type s0,s1; s0=z_type(1.,1.); s1=s0;
		for(n=0;n<8800;n++){ //if( fabs(s0-s1) < 1.e-14) break;
				    s0=s1; s1=log(s1)/LB;	}
//	printf("lob, %6.3f :  %6.3f +i* %6.3f\n",LB,Re(s1),Im(s1) );
			return s1;
		}
		
main(){DB x,y,t,b,lb, L; z_type LB,Lb; int m,n;  FILE *o;
o=fopen("fig02b.eps","w"); ado(o,530,440);
fprintf(o,"120 220 translate 100 100 scale \n");
fprintf(o,"/o {.014 0 360 arc C F} bind def\n");
fprintf(o,"/O {.03 0 360 arc C S} bind def\n");
fprintf(o,"/oo    {0 360 arc C S} bind def\n");
fprintf(o,"/times-Roman findfont .3 scalefont setfont\n");
#define M(x,y) fprintf(o,"%5.3f %5.3f M\n",0.+x,0.+y);
#define L(x,y) fprintf(o,"%5.3f %5.3f L\n",0.+x,0.+y);
#define o(x,y) fprintf(o,"%5.3f %5.3f o\n",0.+x,0.+y);
#define O(x,y) fprintf(o,"%5.3f %5.3f O\n",0.+x,0.+y);
#define oo(r,x,y) fprintf(o,"%5.3 %5.3f %5.3f o\n",0.+r,0.+x,0.+y);

M(0,-2.02)L(0,2.02) M(-1.02,0)L(3.02,0) fprintf(o,".01 W S\n");
for(n=-2;n<3;n++){if(n!=0){M(-1,n)L(3,n)}} 
for(m=-1;m<4;m++){if(n!=0){M(m,-2)L(m,2)}}  fprintf(o,".0036 W S\n");

fprintf(o,".8 0 0 RGB .014 W\n"); O(M_E,0)
for(n=45;n< 50;n+= 1){b=1.+.01*n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);}
for(n=52;n< 60;n+= 2){b=1.+.01*n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);}
for(n=62;n< 70;n+= 2){b=1.+.01*n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);}
for(n=72;n< 80;n+= 2){b=1.+.01*n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);}
fprintf(o,"0 .8 0 RGB\n");
for(n=150;n<200;n+=10){b=.01*n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
fprintf(o,"0 0 0 RGB\n");b=2;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);
fprintf(o,"0 .8 0 RGB\n");
for(n=210;n<300;n+=10){b=.01*n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);}
fprintf(o,"0 0 .8 RGB\n");
for(n=3;n<6;n+=1){b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
fprintf(o,"0 0 0 RGB\n"); b=10;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);
fprintf(o,"0 0 .8 RGB\n");
for(n=20;n<31;n+=10){b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
//fprintf(o,".6 0 .6 RGB\n");
	n=50;	{b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);}
//fprintf(o,".6 0 .6 RGB\n");
	n=100;	{b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
	n=1000;	{b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
	n=10000;	{b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
	n=1000000;	{b=n;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);}
		b=1.e12;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);
fprintf(o,".6 0 .6 RGB\n");
		b=1.e24;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);
		b=1.e48;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);
fprintf(o,"0 0 0 RGB\n");
		b=1.e100;t=log(b);Lb=lob(t);x=Re(Lb);y=Im(Lb);o(x,y);o(x,-y);
fprintf(o,".6 0 0 RGB\n");
		;t=1.; Lb=lob(t);x=Re(Lb);y=Im(Lb);O(x,y);O(x,-y);

fprintf(o,".5 0 .5 RGB\n");
O(2,0)O(4,0)

fprintf(o,"showpage\n");
fprintf(o,"%cTrailer\n",'%');
fclose(o);
//	system(    "open fig02b.eps");// for macintosh
	system("epstopdf fig02b.eps");
	system(    "xpdf fig02b.pdf");// for linux
//	getchar(); system("killall Preview");// for macintosh
}

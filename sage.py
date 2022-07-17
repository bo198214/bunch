import mpmath
### Basechange vs regular ###

#Comparing base sqrt(2) at 2 with base e^(1/e) at e

from sage.hyperops.formal_powerseries import FormalPowerSeriesRing
from sage.hyperops.regular_tetration import RegularTetration

# FQa = FractionField(PolynomialRing(QQ,"a"))
# a = FQa.gen()
# FFQa = FormalPowerSeriesRing(FQa)
# h = FFQa([a])*FFQa.Dec_exp

#abel=(h.abel()+log(x))/log(a)

def mu(a,b,N=None,iprec=53,oprec=25,debug=0):
  R = RealField(iprec)
  a = R(a)
  lna = ln(a)
  b = R(b)
  lnb = ln(b)
  c = (ln(lnb)-ln(lna))/lnb
  #print c
  tau = lambda x: lnb/lna*x + (ln(lnb)-ln(lna))/lna
  err=2.0**(-oprec)
  def f(x):
    xin = x
    x = R(x)
    n=0
    y = x
    while True:
      yp = y
      xp = x
      n+=1
      x = b**xp
      if x == xp or x == R(infinity) or y == R(infinity):
        print 'xin:',xin,'x:',x
        print 'n:',n-1,'d:',d,'err:',err,'xp:',xp,'yp:',yp
        return R(NaN)
      y = x
      for n1 in range(n):
        #print "log"
        y = log(y+c)/lnb
      d=y-yp
      if debug>=1: print n,':',d,y,yp,x,xp
      if (not N==None and n >= N) or abs(d)<err:
        if debug>=1: print "res: ",tau(y).n(oprec),"n:",n,"d:",d,"err:",err
        return tau(y).n(oprec)

  return f
      
def mun(a,b,n,iprec=53):
  R = RealField(iprec)
  x = var('x')
  a = R(a)
  b = R(b)
  lna = ln(a)
  lnb = ln(b)
  if n == 0:
    return (lnb/lna*x+ (ln(lnb)-ln(lna))/lna).function(x)
  return (log(mun(a,b,n-1,iprec=iprec)(b**x))/lna).function(x)

def mud1(a,b,iprec=53,oprec=25,debug=False):
  R = RealField(iprec)
  a = R(a)
  lna = ln(a)
  b = R(b)
  lnb = ln(b)
  c = (ln(lnb)-ln(lna))/lnb
  #print c
  tau = lambda x: lnb/lna*x + (ln(lnb)-ln(lna))/lna
  err=2.0**(-oprec)
  def f(x):
    y = mu(a,b)(x)
    n=0
    c = 1
    z = 0
    while True:
      zp = z
      n+=1
      x = b**x
      y = a**y
      c *= (lnb*x)/(lna*y)
      z = c
      d=z-zp
      if debug: print n,'z:',z,'x:',x,'y:',y,'c:',c
      if x == R(infinity) or y == R(infinity):
        return R(NaN)
      if abs(d)<err:
        if debug: print "d:",d,"err:",err
        return z

  return f

def mu2(a,b,iprec=53,oprec=25,debug=False):
  R = RealField(iprec)
  a = R(a)
  lna = ln(a)
  b = R(b)
  lnb = ln(b)
  tau = lambda x: lnb/lna*x + (ln(lnb)-ln(lna))/lna
  err=2.0**(-oprec)
  def f(x):
    n=0
    y = x
    while True:
      yp = y
      xp = x
      n+=1
      x = b**xp
      y = tau(x)
      for n1 in range(n):
        #print "log"
        y = log(y)/lna
      d=y-yp
      if debug: print n,d,y,x
      if x == xp or x == R(infinity) or y == R(infinity):
        print 'xin',xin,'d:',d,'err:',err,'xp:',xp,'yp:',yp
        return R(NaN)
      if abs(d)<err:
        if debug: print "y:",y.n(oprec),"d:",d,"err:",err
        return y.n(oprec)

  return f
# z0 = 2
# z0 = 4.0/3
  
debug=True
iprec=120

a=8**(1/Integer(8))
b=4**(1/Integer(4))

oprec=53

rta = RegularTetration(a,1,direction=1,iprec=iprec,prec=oprec)
rtb = RegularTetration(b,1,direction=1,iprec=iprec,prec=oprec)

muab=mu(a,b,iprec=120,oprec=36,debug=debug)
def d(x):
  print 'x:',x
  return rta.slog(muab(x),debug=debug)-rtb.slog(x,debug=debug)

#plot(d,(0,4))

#atainable precision is 37 
#mu(e**(1/e),e,oprec=37,iprec=100)

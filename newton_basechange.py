#Stuetzstellen von a bis b:

def coeffs0(NH=15,a = -1,b = 1,iprec=530,xs=None):
  R=ComplexField(iprec)
  a = R(a)
  b = R(b)

  N=2*NH+1
  if xs==None:
    dx=R(1)/NH
    xs=[a+n*dx for n in range(N)]

#NewtonMatrix:
  NM=matrix([[1 if column==0 else xs[row]**column for column  in range(N)] for row in range(N)])
  CM=~NM

  f = mu(e**(1/e),e)
  coeffs=CM*vector([R(f(x)) for x in xs])
  return coeffs


def coeffs1(N=15,a=e**(1/e),b=1.5,x0=0,y0=3.185885,iprec=530):
  R = RealField(iprec)
  a = R(a)
  b = R(b)
  xs = vector(R,N)
  ys = vector(R,N)
  xs[0]=R(x0)
  ys[0]=R(y0)
  for n in range(1,N):
    xs[n] = b**xs[n-1]
    ys[n] = a**ys[n-1]
  NM=matrix([[1 if column==0 else xs[row]**column for column  in range(N)] for row in range(N)])
  return ~NM*ys
  
def coeffs2(N=15,b=1.5,x0=0,y0=1,iprec=530):
  R = RealField(iprec)
  b = R(b)
  xs = vector(R,N)
  ys = vector(R,N)
  xs[0]=R(x0)
  ys[0]=R(y0)
  for n in range(1,N):
    xs[n] = 1+xs[n-1]
    ys[n] = b**ys[n-1]
  NM=matrix([[1 if column==0 else xs[row]**column for column  in range(N)] for row in range(N)])
  return ~NM*ys

def root_test(coeffs,n0=1):
  return line([(n,abs(coeffs[n])**(-1/n)) for n in range(n0,len(coeffs))])

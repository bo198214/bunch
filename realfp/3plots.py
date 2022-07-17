x1=4;sr_plot=plot(x**(1/x),(0,1)) + plot(x**(1/x),(1,x1),fill=1) + line([(e-1,e**(1/e)),(e+1,e**(1/e))],color='black',thickness=0.5) + line([(e,0),(e,e**(1/e))],color='black',thickness=0.5) + text('e',(e+0.1,0.3),color='black') + text('y=x^(1/x)',(3,2)); sr_plot.set_aspect_ratio(1)
sp_plot = plot(x**x,(0,1.0),fill=1)+plot(x**x,(1.0,1.5)) + line([(1/e-0.3,e**(-1/e)),(1/e+0.3,e**(-1/e))],thickness=0.5,color='black') + line([(1/e,0),(1/e,e**(-1/e))],color='black',thickness='0.5') + text('1/e',(1/e+0.05,0.2),color='black') + text('y=x^x',(1,1.5))
me_plot = plot(x*exp(x),(-6,0),fill=0)+plot(x*exp(x),(0,0.8)) + line([(-1,-0.15),(-1,-e**(-1))],color='black',thickness=0.5) + line([(-2,-e**(-1)),(-0.1,-e**(-1))],color='black',thickness=0.5) + text('y=x*e^x',(-2,1))

def write(p,fn):
  p.show(filename=fn,dpi=300,axes_labels=['x','y'])


write(me_plot,'me.pdf')
write(sp_plot,'sp.pdf')
write(sr_plot,'sr.pdf')

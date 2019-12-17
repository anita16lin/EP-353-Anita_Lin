sr=44100
kr=4410
ksmps=10
nchnls=2
	
instr 	103			
; this instrument processes audio
		
igraindur	= p3
igrainamp	= ampdb(90+p4)
igrainfreq	= p5
iftable		= p6
ienvfn	= p7
ifrq2	= p8
ifrq3	=p9
ipan		= p10

k1  oscil   igrainamp, 1/igraindur, ienvfn ;using osc as an envelope to control the amp of loscil
k2  expseg  igrainfreq, igraindur/3, ifrq2, igraindur/3, ifrq3, igraindur/3, igrainfreq ;k2 controls the frequency of a1
a1 	loscil  k1, k2*2, iftable, 440
aleft  = a1 * sqrt(1-ipan)
aright = a1 * sqrt(ipan)

outs aleft, aright
endin

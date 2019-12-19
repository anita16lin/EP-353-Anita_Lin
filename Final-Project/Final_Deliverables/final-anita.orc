sr=44100
kr=4410
ksmps=10
nchnls=2

instr 101
;this instrument plays a single sine wave grain

igraindur	= p3
igrainamp	= ampdb(90+p4)
igrainfreq	= p5
iftable		= p6
ipan 		= p7

kgrainamp	oscil1 0, igrainamp, igraindur, iftable
agrain		oscili kgrainamp, igrainfreq, 1
aleft	=	agrain * sqrt(1-ipan)
aright	=	agrain * sqrt(ipan)

outs aleft, aright

endin

instr 102
;this instrument plays a single FM grain

igraindur	= p3
igrainamp	= ampdb(90+p4)
igraincarfreq	= p5
igrainmodfreq	= p6
ideviation	= p7 * igrainmodfreq
iftable		= p8
ipan		= p9

agrainamp	oscili igrainamp, 1/igraindur, iftable
amodgrain	oscili ideviation, igrainmodfreq, 1
acargrain	oscili agrainamp, amodgrain + igraincarfreq, 1
aleft	=	acargrain * sqrt(1-ipan)
aright	=	acargrain * sqrt(ipan)

outs	aleft, aright

endin

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
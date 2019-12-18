sr = 44100
kr = 4410
ksmps = 10
nchnls = 2

gadist init 0
garvb init 0

instr 99

kfrq    port .1, .004, 20000
a1      butterlp garvb, kfrq
a2      linseg 0, 0.003, 1, 0.01, 0.7, 0.005, 0, 1, 0
a1      =  a1 * a2
a2      =  a1 * p5
a1      =  a1 * p4
        denorm a1, a2
aL, aR  reverbsc a1, a2, 0.85, 12000, sr, 0.5, 1
        outs a1 + aL, a2 + aR
garvb = 0
        endin
        
instr 104
igrainamp = ampdb(90+p4)
igrainfreq = p5
kc1 = p6
kc2 = p7
kvrate = p8
irvbsnd = p9

kvdpth line 0, p3, p6
asig   fmb3 igrainamp, igrainfreq, kc1, kc2, kvdpth, kvrate
garvb	=		garvb+(asig*irvbsnd)
gadist = gadist + asig + garvb


endin
  
instr 50

kpre init p4
kpost init p5
kshap1 init p6
kshap2 init p7
ipan = p8
aout distort1 gadist, kpre, kpost, kshap1, kshap2, 1
aleft = aout * sqrt(1-ipan)
aright = aout * sqrt(ipan)

outs aleft, aright

gadist = 0
endin



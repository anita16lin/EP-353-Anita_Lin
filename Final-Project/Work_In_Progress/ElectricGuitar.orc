sr = 44100
kr = 4410
ksmps = 10
nchnls = 2

gadist init 0
garvb init 0

instr 99
igrainamp = ampdb(90+p4)

kfrq    port .1, .004, 20000
a1      butterlp garvb, kfrq
a2      linseg 0, 0.003, 1, 0.01, 0.7, 0.005, 0, 1, 0
a1      =  a1 * a2
a2      =  a1 * p5
a1      =  a1 * igrainamp
        denorm a1, a2
aL, aR  reverbsc a1, a2, 0.85, 12000, sr, 0.5, 1
        outs a1 + aL, a2 + aR
garvb = 0
        endin
        
instr 1
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
ipan = p9
aout distort1 gadist, kpre, kpost, kshap1, kshap2, 1
aleft = aout * sqrt(1-ipan)
aright = aout * sqrt(ipan)

outs aleft, aright

gadist = 0
endin


</CsInstruments>
<CsScore>
;======Global Reverb==== I'm trying to add this reverb to it but it's not quite sounding...I can't tell if it is.....Not sure why
;ins	strt	dur 	d1 d2
;=======================
i 99	0.0 -1	0.71 		0.71 
/*
i 99 0.5 1 0.00 		1.00		
i 99 2.5 1 -0.71 	0.71
i 99 3.0 1 1.00	 		0.00
i 99 3.5 4 0.71 		0.71
i 99 4.5 1 0.00 		1.00		
i 99 5.0 4 -0.71 	0.71
*/

;=================Global Distort==============
;   Sta  Dur  PreGain PostGain Shape1 Shape2
;=============================================
i50 0    13      2       .5       0      0

;==========Instrument Demo====================
;   Sta  Dur  Amp  Pitch kc1 kc2 kvrate irvbsnd
;=============================================
i1  0.0  3.0  0.5  6.00	 .5		.5			6		.5
i1  0.5  2.5  0.5  7.00		<			<				6		.5
i1  2.50 1.5  0.5  7.03		.			.				5		.5
i1  3.00 1.00 0.5  7.08		.			.		  	4		.5
i1  3.5  1.5  0.5  7.00		.			.				3		.5
i1  4.5  1.0  0.5  6.00		.			.				6		.5
i1  5.0  2.0  0.5  8.00		2			2				4		.5
e 2

;==========Instrument Demo====================
;   Sta  Dur  Amp  Pitch kc1 kc2 kvrate
;=============================================
/*i1  9.00  3.0  0.5  6.00	 .5			.5				6
i1  9.50  2.5  0.5  7.00		.5			.5				6
i1  10.0  2.0  0.5  7.07		5			5				6
i1  10.5  1.5  0.5  8.00		5			5				6 
*/
e

</CsScore>
</CsoundSynthesizer>

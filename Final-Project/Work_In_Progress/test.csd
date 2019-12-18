<CsoundSynthesizer>
<CsOptions>
; Select audio/midi flags here according to platform
-odac     ;;;RT audio out
;-iadc    ;;;uncomment -iadc if RT audio input is needed too
; For Non-realtime ouput leave only the line below:
; -o distort1.wav -W ;;; for file output any platform
</CsOptions>
<CsInstruments>

sr = 44100
ksmps = 10
kr = 4410
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
        
	instr 1
iamp = ampdb(90+p4)
ifqc = p5
kc1 = p6
kc2 = p7
kvrate = p8
irvbsnd = p9
kvdpth line 0, p3, p6
asig   fmb3 iamp, ifqc, kc1, kc2, kvdpth, kvrate
garvb	=		garvb+(asig*irvbsnd)
gadist = gadist + asig + garvb


endin
  
instr 50
  kpre init p4
  kpost init p5
  kshap1 init p6
  kshap2 init p7
  aout distort1 gadist, kpre, kpost, kshap1, kshap2, 1

  outs aout, aout

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
i1  0.0  3.0  -54  500	 .5		.5			6		.5
i1  0.5  2.5  -60  500		<			<				6		.5
i1  2.50 1.5  -60  500		.			.				5		.5
i1  3.00 1.00 -60  500		.			.		  	4		.5
i1  3.5  1.5  -60  100		.			.				3		.5
i1  4.5  1.0  0.5  500		.			.				6		.5
i1  5.0  2.0  0.5  500		2			2				4		.5
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
<bsbPanel>
 <label>Widgets</label>
 <objectName/>
 <x>100</x>
 <y>100</y>
 <width>320</width>
 <height>240</height>
 <visible>true</visible>
 <uuid/>
 <bgcolor mode="nobackground">
  <r>255</r>
  <g>255</g>
  <b>255</b>
 </bgcolor>
</bsbPanel>
<bsbPresets>
</bsbPresets>

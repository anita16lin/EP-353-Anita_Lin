sr=44100
kr=4410
ksmps=10
nchnls=2
	
instr 	118					
igraindur	= p3
igrainamp	= ampdb(90+p4)
igrainfreq	= p5
iftable		= p6
ipan		= p7

k1  oscil   igrainamp, 1/igraindur, p7 ;using osc as an envelope to control the amp of loscil
k2  expseg  igrainfreq, igraindur/3, p8, igraindur/3, p9, igraindur/3, igrainfreq ;k2 controls the frequency of a1
a1 	loscil  k1, k2*2, iftable, 440
aleft  = a1 * sqrt(1-ipan)
aright = a1 * sqrt(ipan)

outs aleft, aright
endin

</CsInstruments>
<CsScore>
 
f 4  0 0    1   "sing.aif" 		0 	0 	0
f 5  0 0    1   "hellorcb.aif" 	0 	0 	0 

;ins				strt			dur 		amp						frq1	sample	envfn	frq2 frq3
;============================================================================
i 118    0      2.31			30000  		440    4					7				430		450
i 118    3      4.62			30000  		220    4					8				225		215
i 118    8      2.28			10000  		442    5					6				444		438
i 118    8.3    2.28			10000  		438    	5					6				441		435
i 118    8.8    2.1				10000  		450    	5					6				460		445
i 118    11     4.62			10000  		219    	4					3				221		218
i 118    11     4.62			10000  		440    	4					7				438		442
i 118    11.5   2.31			10000  		554.4  	4					8				550		560		
i 118    12     2.31			10000  		659.2  	4					7				640		666		
i 118    14     3					20000  		440    	5					6				439		441
</CsScore>
</CsoundSynthesizer>
<bsbPanel>
 <label>Widgets</label>
 <objectName/>
 <x>0</x>
 <y>0</y>
 <width>0</width>
 <height>0</height>
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

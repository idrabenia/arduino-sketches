#define __SFR_OFFSET 0
  
#include "avr/io.h"

.global start
.global blink

start:
  sbi   DDRB, 5  ; Set PB5 as output
  ret

blink: 
  call delay_1
  sbi PORTB, 5

  call delay_1
  cbi PORTB, 5

  ret

delay_1:
	ldi r28, 0x80
  ldi r29, 0x3E

loop_0:

	ldi r17, 0xFF

loop_1:
	dec r17
	cpi r17, 0x00
	brne loop_1

	sbiw r28, 1
	brne loop_0

  ret

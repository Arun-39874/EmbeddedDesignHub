.include "m328pdef.inc"

.def R1_pins = R16
.def R2_pins = R17
.def OverflowLed = R18
.def OverflowOption = R19
.def R1 = R20
.def R2 = R21
.def Sum = R22

ldi OverflowOption, 1   ; Set OverflowOption to 1

ldi R1_pins, 0b00001111   ; R1 pin values (binary 0000 1111)
ldi R2_pins, 0b11110000   ; R2 pin values (binary 1111 0000)
ldi OverflowLed, 0b11110000 ; Overflow LED pin values (binary 1111 0000)

; Test case 1
ldi R1, 0b1011   ; Load R1 value
ldi R2, 0b1110   ; Load R2 value
call checkOverflow ; Call the checkOverflow function

; Test case 2
ldi OverflowOption, 2   ; Set OverflowOption to 2
ldi R1, 0b0011   ; Load R1 value
ldi R2, 0b0100   ; Load R2 value
call checkOverflow ; Call the checkOverflow function

; Test case 3
ldi OverflowOption, 3   ; Set OverflowOption to 3
ldi R1, 0b1100   ; Load R1 value
ldi R2, 0b1010   ; Load R2 value
call checkOverflow ; Call the checkOverflow function

; Test case 4
ldi OverflowOption, 0   ; Initialize OverflowOption to 0
ldi R1, 0b1001   ; Load R1 value
ldi R2, 0b1111   ; Load R2 value
call checkOverflow ; Call the checkOverflow function

rjmp $ ; End of program

checkOverflow:
  ; Display input numbers on Serial Monitor (not implemented in assembly)
  ; Set inputs using LEDs
  out PORTD, R1_pins
  out PORTB, R2_pins

  ; 4-bit addition
  add Sum, R1, R2

  ; Check for overflow for each option
  and R16, R1, R2       ; R16 = R1 & R2
  and R17, Sum, R1       ; R17 = Sum & R1
  and R18, Sum, R2       ; R18 = Sum & R2
  eor R16, R16, R17      ; R16 = R16 ^ R17
  brne overflow_occurred ; Branch if not equal (overflow occurred)

  ; No overflow
  out PORTD, R1_pins ; Turn off all LEDs on PORTD
  ret

overflow_occurred:
  ; Overflow occurred
  out PORTD, OverflowLed ; Set the LED corresponding to the OverflowOption
  ret
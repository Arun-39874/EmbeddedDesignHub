#include <avr/io.h>
#include <util/delay.h>

// Pin assignments
#define ledPinA 2   // LED for option A
#define ledPinB 3   // LED for option B
#define ledPinC 4   // LED for option C
#define ledPinD 5   // LED for option D

void setup() {
  // Set LED pins as outputs
  DDRD |= (1 << ledPinA) | (1 << ledPinB) | (1 << ledPinC) | (1 << ledPinD);

  // Initialize all LEDs as OFF
  PORTD &= ~((1 << ledPinA) | (1 << ledPinB) | (1 << ledPinC) | (1 << ledPinD));
  
}

//statement Y = A + B'

//OPTIONS
//A  NAND gate
//B  OR gate
//C  NOR gate
//D  AND gate

void checkOptionA() {
  // Option (A) NAND logic can be implemented
  // We don't need to perform any specific check for this; just turn on the LED
  PORTD |= (1 << ledPinA);
}

void checkOptionB() {
  // Option (B) OR logic cannot be implemented
  // Check if the given gate D performs OR logic
  if (gateDPerformsOR()) {
    // If it does, turn on the LED
    PORTD |= (1 << ledPinB);
  }
}

void checkOptionC() {
  // Option (C) NOR logic can be implemented
  // Check if NOR logic can be implemented using gate D
  if (gateDPerformsNOR()) {
    // If it does, turn on the LED
    PORTD |= (1 << ledPinC);
  }
}

void checkOptionD() {
  // Option (D) AND logic cannot be implemented
  // Check if the given gate D performs AND logic
  if (gateDPerformsAND()) {
    // If it doesn't, turn on the LED
    PORTD |= (1 << ledPinD);
  }
}

// Helper functions to simulate gate D behavior
uint8_t gateDPerformsOR() {
  // Simulate gate D performing OR logic
  return 0;
}

uint8_t gateDPerformsNOR() {
  // Simulate gate D performing NOR logic
  // NOR is a universal gate so we can implement
  return 1;
}

uint8_t gateDPerformsAND() {
  // Simulate gate D performing AND logic
  return 0;
}

int main(void) {
  setup();

  // Test each option and turn on the corresponding LED
  checkOptionA();  // NAND gate
  checkOptionB();  // OR gate
  checkOptionC();  // NOR gate
  checkOptionD();  // AND gate
  
  return 0;
}

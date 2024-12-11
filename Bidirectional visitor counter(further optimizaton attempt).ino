const int CLOCK_PIN = 9; // Output pin for the clock signal

void setup() {
  pinMode(CLOCK_PIN, OUTPUT);

  // Configure Timer1
  noInterrupts(); // Disable interrupts during setup

  TCCR1A = 0; // Clear Timer1 control registers
  TCCR1B = 0;

  // Set Timer1 prescaler to divide by 1 (no prescaling)
  TCCR1B |= (1 << CS10);

  // Set Timer1 mode to CTC (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);

  // Set Timer1 compare match value for 800kHz frequency
  OCR1A = 19;

  // Enable Timer1 compare match interrupt
  TIMSK1 |= (1 << OCIE1A);

  interrupts(); // Enable interrupts after setup
}

void loop() {
  // Your main program logic here
}

// Timer1 compare match interrupt handler
ISR(TIMER1_COMPA_vect) {
  digitalWrite(CLOCK_PIN, !digitalRead(CLOCK_PIN)); // Toggle the clock pin
}

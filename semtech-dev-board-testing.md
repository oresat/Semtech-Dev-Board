# This is incomplete and is still in process! - GNL

## Testing strategy for the Semtech Dev Board

The following tests should be performed to verify the functionality of the development board.

### General tests to get started

* Power up, and no smoke emitted
  * Make power (5 VDC through USB, or JP1) and SPI connections. Also a connection to DIO2 is needed for data.
  * Connect jumper for PA Bias. Only connect the LF side for now, JP3 1-2.
  * Apply power and verify LED indicates power is on. **No smoke is emitted!**
  * Measure current consumption of the board in in this idle state and recorded as a baseline value.

* CPU communication to the SX1236 using SPI
  * Ability to read a register and confirm data is valid.
  * Ability to write a register and read back the correct value.
  * Confirm registers (how many?) have their POR values in them as expected.
  * Read back the temperature sensor register (0x3c) and verify it makes sense.

The SX1236 has three bands it can operate in:
- Band 3:  137 to 175 MHz
- Band 2:  410 to 525 MHz
- Band 1:  862 to 1020 MHz

The SX1236 has two digital (IQ) transceivers available:
- HF (Band 1)
- LF (Band 2 and 3)


### Setup for transmitter tests

Let's go right to where we plan to use this thing (i.e. communications in the 435 to 438 MHz Amateur Space band.)

Using the LF transceiver, and knowing our crystal oscillator (FXOSC) is 32 MHz;

* Set LO synthesizer frequency (FR) to 436.5 MHz
* Set FSK bit rate (BRF) to 9.6 kbps (BitRate MSB/LSB are set to 4.8 kbps upon POR)
* Set FSK deviation (FDA) to 20 kHz (Fdev is set to 5 kHz upon POR)
* Set data processing mode to Continuous Mode. This is because (sadly) we will need to do our own packet processing to adhear
  to other standards such as AX.25. Here we will use DIO2 for data input / output.
* Set output power to 0 dBm

This sets us up for signals compatible with the G3RUH modulation standard, and we are ready to "key-up" the transmitter.


### Setup for receiver tests

* Set LO synthesizer frequency (FR) to 436.5 MHz
* Set FSK bit rate (BRF) to 9.6 kbps
* Set FSK deviation (FDA) to 20 kHz
* Set LNA gain
* Read RSSI register and confirm it is seeing about -120 dBm (Minimum discernable signal)


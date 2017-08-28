# This is incomplete and is still in process! - GNL

## Testing strategy for the Semtech Dev Board

The following tests should be performed to verify the functionality of the development board.

### General tests to get started

* Equipment needed:
  * Power supply
  * 3M wires (and possibly USB-micro cable for power)
  * DVM for current measurement
  * Laptop
  * Embedded system and software (M4) to talk SPI
  * Three (3) 2W SMA terminators
  * SMA "rubber duck" antenna

* Power up, and see that no smoke is emitted
  * Place 2W terminators on SMA connectors CF2, 3, and 4. Place a *rubber duck* antenna on connector CF1.
  * Make power connection (5 VDC through USB, or JP1) and SPI connections. Also a connection to DIO2 is needed for data.
  * Connect jumper for PA Bias. Only connect the LF side for now, JP3 1-2.
  * Apply power and verify LED indicates power is on. **Verify no smoke is emitted!**
  * Measure current consumption of the board in this idle state and record it [where?] as a baseline value.

* CPU communication to the SX1236 using SPI
  * Ability to read a register and confirm data is valid.
  * Ability to write a register and read back the correct value.
  * Confirm registers (how many?) have their POR values in them as expected.
  * Read back the temperature sensor register (0x3c) and verify it makes sense.

### Setup for emperical RF test and measurement

* Equipment needed:
  * RF signal generator
  * Throughline RF power meter
  * Spectrum Analyser and sampling antenna (RTL-SDR on another laptop)
  * SMA patch cords
  * 3M wires to generate Data I/O
  * 10k ohm leaded 1/4 watt resistor.
  * Oscilloscope to view data I/O

The SX1236 has three bands it can operate in:
- Band 3:  137 to 175 MHz
- Band 2:  410 to 525 MHz
- Band 1:  862 to 1020 MHz

The SX1236 has two digital (IQ) transceivers available:
- HF (Band 1)
- LF (Band 2 and 3)


#### Setup for transmitter tests

Let's go right to where we plan to use this thing (i.e. communications in the 435 to 438 MHz Amateur Space Band.)

Using the LF transceiver, and knowing our crystal oscillator (FXOSC) is 32 MHz;

Presently K has created SX1233 firmware test code on an M4 to communicate over SPI to generate beacon signals using packet
mode. This firmware could be used for this test without the need to apply data I/O to DIO2. 

* Set LO synthesizer frequency (FR) to 436.5 MHz
* Set FSK bit rate (BRF) to 9.6 kbps (BitRate MSB/LSB are set to 4.8 kbps upon POR)
* Set FSK deviation (FDA) to 20 kHz (Fdev is set to 5 kHz upon POR)
* Set data processing mode to Continuous Mode. This is because (sadly) we will need to do our own packet processing to adhear
  to other standards such as AX.25. Here we will use DIO2 for data input / output.
* Set output power to 0 dBm
* Set up spectrum analyser to sample 430 to 440 MHz band
* Insert throughline power meter between CF2 and 2W terminator.
* If using continuous mode, assert DIO2 to a logic high level using a 10k ohm pullup to Vcc and a 3M wire.

This sets us up for signals compatible with the G3RUH modulation standard, and we are ready to "key-up" the transmitter.

##### Turn on transmitter

* Confirm frequency on SA
* Confirm power level on throughline power meter

##### Send data through transmitter

* Confirm data sent by observing on SA
  * Alternately a second Semtech board could be used to receive the data sent over the air, but that system and test has not
    yet been described but will be in subsequent tests.


#### Setup for receiver tests

Using the same embedded system in the transmitter test, perform the following:

* Set LO synthesizer frequency (FR) to 436.5 MHz
* Set FSK bit rate (BRF) to 9.6 kbps
* Set FSK deviation (FDA) to 20 kHz
* Set LNA gain to [lowest gain]
* Remove the rubber duck antenna from CF1, and connect RF signal generator using SMA patch cables.
  * Set RF signal generator to -60 dBm level and frequency of 436.5 MHz continuous wave (no modulation)

##### Measure known receive signal

* Read RSSI register and confirm it is seeing the -60 dBm (LNA gain should be 0 dB)

##### Receive known data packet

* At this point a second system could be used to send a known data packet, and the received data couls be confirmed.
* Remove the RF signal generator from CF1, and reconnect the rubber duck antenna.
* Using K's firmware on the M4 monitor the received packet data through the SPI. DIO0 should assert an interrupt pulse
  when a packet is received.


###

Register usage for tests:

* Packet mode

* Continuous mode



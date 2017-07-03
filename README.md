# Development board for the Semtech SX1236

## Overview

OreSat is designed around a 70 cm (436 MHz) radio system for what other cubesats call their Command and Data Handling (C&DH) system. We started with the NXP Kw0x series chips but found that chip, and it's interface to its embedded Semtech SX1232 (?) radio IC, too painful to continue. 

Since the specs on the Semtech radio ICs are good, we could "upgrade" a generation by going to a separate IC, and we're interesting in using a STM32 for our system controller, we decided on using the SX1236. Of *course* no one makes an evaluation board for this IC. Sigh.

## Requirements

- Must be a barebones, "development" or "evaluation" board for the SX1236.
- Must work under USB and LiPo power
- Open source

## Specifications

- Must
   - RF out via Female SMA connector (board edge preferred)
   - Must have a 0.1" pinheader for power and control signals.
   - All but NC pads must be broken out to test points with vias for easy modding
   - Voltage input range of 3.0 to 5.5 V.
   - Use 0.1" headers and jumpers for configuration pins
- Should
   - Have large square silk screen area for board #
   - Have copper ground pads around edge of  board for scope clips
- Must not
   - Feature creep (don't go nuts, just make us an evaluation board of a refernece design)
   - This includes not bothering to deal with LNAs or PAs for this board! It's local only.

## References

- [Original Practicum Kw0x Development board](https://github.com/wrh2/sputnik/tree/master/Phase0/eagle)
- Original OreSat [Low Gain Radio board](https://github.com/oresat/low-gain-radio)
- [Semtech SX126 Webpage](http://www.semtech.com/wireless-rf/rf-transceivers/sx1236/)
- The [SX1276](http://www.semtech.com/apps/product.php?pn=SX1276) may have the same pinout, but also has a LoRa radio built in (blech)


//
//  Semtech SX1236 Register values needed for initial OreSat testing.
//  G.N. LeBrasseur  1-Sep-2017
//

//
// Register address description
//
struct SX1236 transceiver = {
	.RegFifo 		= 0x00,
	.RegOpMode 		= 0x01,
	.RegBitrateMsb 		= 0x02,
	.RegBitrateLsb 		= 0x03,
	.RegFdevMsb 		= 0x04,
	.RegFdevLsb 		= 0x05,
	.RegFrfMsb 		= 0x06,
	.RegFrfMid 		= 0x07,
	.RegFrfLsb 		= 0x08,
	.RegPaConfig 		= 0x09,
	.RegPaRamp 		= 0x0A,
	.RegOcp 		= 0x0B,
	.RegLna 		= 0x0C,
	.RegRxConfig 		= 0x0D,
	.RegRssiConfig 		= 0x0E,
	.RegRssiCollision 	= 0x0F,
	.RegRssiThresh 		= 0x10,
	.RegRssiValue 		= 0x11,
	.RegRxBw 		= 0x12,
	.RegAfcBw 		= 0x13,
	.RegOokPeak 		= 0x14,
	.RegOokFix 		= 0x15,
	.RegOokAvg 		= 0x16,
// Reserved 17, 18, 19
	.RegAfcFei 		= 0x1A,
	.RegAfcMsb 		= 0x1B,
	.RegAfcLsb 		= 0x1C,
	.RegFeiMsb 		= 0x1D,
	.RegFeiLsb 		= 0x1E,
	.RegPreambleDetect 	= 0x1F,
	.RegRxTimeout1 		= 0x20,
	.RegRxTimeout2 		= 0x21,
	.RegRxTimeout3 		= 0x22,
	.RegRxDelay 		= 0x23,
	.RegOsc 		= 0x24,
	.RegPreambleMsb 	= 0x25,
	.RegPreambleLsb 	= 0x26,
	.RegSyncConfig 		= 0x27,
	.RegSyncValue1 		= 0x28,
	.RegSyncValue2 		= 0x29,
	.RegSyncValue3 		= 0x2A,
	.RegSyncValue4 		= 0x2B,
	.RegSyncValue5 		= 0x2C,
	.RegSyncValue6 		= 0x2D,
	.RegSyncValue7 		= 0x2E,
	.RegSyncValue8 		= 0x2F,
	.RegPacketConfig1 	= 0x30,
	.RegPacketConfig2 	= 0x31,
	.RegPayloadLength 	= 0x32,
	.RegNodeAdrs 		= 0x33,
	.RegBroadcastAdrs 	= 0x34,
	.RegFifoThresh 		= 0x35,
	.RegSeqConfig1 		= 0x36,
	.RegSeqConfig2 		= 0x37,
	.RegTimerResol 		= 0x38,
	.RegTimer1Coef		= 0x39,
	.RegTimer2Coef		= 0x3A,
	.RegImageCal 		= 0x3B,
	.RegTemp 		= 0x3C,
	.RegLowBat 		= 0x3D,
	.RegIrqFlags1 		= 0x3E,
	.RegIrqFlags2 		= 0x3F,
	.RegDioMapping1 	= 0x40,
	.RegDioMapping2		= 0x41,
	.RegVersion 		= 0x42,
// Skip 43
	.RegPllHop 		= 0x44,
// Skip 45, 46, 47, 48, 49, 4A
	.RegTcxo 		= 0x4B,
// Skip 4C
	.RegPaDac 		= 0x4D,
// Skip 4E, 4F, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 5A
	.RegFormerTemp 		= 0x5B,
// Skip 5C
	.RegBitRateFrac 	= 0x5D,
// Skip 5E, 5F, 60
	.RegAgcRef 		= 0x61,
	.RegAgcThresh1 		= 0x62,
	.RegAgcThresh2 		= 0x63,
	.RegAgcThresh3 		= 0x64,
// Skip 65, 66, 67, 68, 69, 6A, 6B, 6C, 6d, 6E, 6F
	.RegPll 		= 0x70
};



//
//  Default values set upon POR. These are forced by Semtech.
//
//  NB:  Changed to reflect POR values (from previous LGR project settings).
//
struct SX1236 POR_defaults = {
	.RegFifo 		= 0x00,
//
//  Common settings
//
	.RegOpMode 		= 0x09,		// Was 0x01
	.RegBitrateMsb 		= 0x1A,
	.RegBitrateLsb 		= 0x0B,
	.RegFdevMsb 		= 0x00,
	.RegFdevLsb 		= 0x52,
	.RegFrfMsb 		= 0x6C,
	.RegFrfMid 		= 0x80,
	.RegFrfLsb 		= 0x00,
//
//  Transmitter
//
	.RegPaConfig 		= 0x4F,
	.RegPaRamp 		= 0x09,
	.RegOcp 		= 0x2B,
//
//  Receiver
//
	.RegLna 		= 0x20,
	.RegRxConfig 		= 0x0E,		// Was 0x08
	.RegRssiConfig 		= 0x02,
	.RegRssiCollision 	= 0x0A,
	.RegRssiThresh 		= 0xFF,
	.RegRssiValue 		= 0x00,
	.RegRxBw 		= 0x15,
	.RegAfcBw 		= 0x0B,
	.RegOokPeak 		= 0x28,
	.RegOokFix 		= 0x0C,
	.RegOokAvg 		= 0x12,
// Reserved registers 17, 18, 19
	.RegAfcFei 		= 0x00,
	.RegAfcMsb 		= 0x00,
	.RegAfcLsb 		= 0x00,
	.RegFeiMsb 		= 0x00,
	.RegFeiLsb 		= 0x00,
	.RegPreambleDetect 	= 0xAA,		// Was 0x40
	.RegRxTimeout1 		= 0x00,
	.RegRxTimeout2 		= 0x00,
	.RegRxTimeout3 		= 0x00,
	.RegRxDelay 		= 0x00,
//
//  Oscillator
//
	.RegOsc 		= 0x07,		// Was 0x05
//
//  Packet handling
//
	.RegPreambleMsb 	= 0x00,
	.RegPreambleLsb 	= 0x03,
	.RegSyncConfig 		= 0x93,
	.RegSyncValue1 		= 0x01,		// Was 0x55
	.RegSyncValue2 		= 0x01,		// Was 0x55
	.RegSyncValue3 		= 0x01,		// Was 0x55
	.RegSyncValue4 		= 0x01,		// Was 0x55
	.RegSyncValue5 		= 0x01,		// Was 0x55
	.RegSyncValue6 		= 0x01,		// Was 0x55
	.RegSyncValue7 		= 0x01,		// Was 0x55
	.RegSyncValue8 		= 0x01,		// Was 0x55
	.RegPacketConfig1 	= 0x90,
	.RegPacketConfig2 	= 0x40,
	.RegPayloadLength 	= 0x40,
	.RegNodeAdrs 		= 0x00,
	.RegBroadcastAdrs 	= 0x00,
	.RegFifoThresh 		= 0x8F,		// Was 0x0F
//
//  Sequencer
//
	.RegSeqConfig1 		= 0x00,
	.RegSeqConfig2 		= 0x00,
	.RegTimerResol 		= 0x00,
	.RegTimer1Coef		= 0xF5,
	.RegTimer2Coef		= 0x20,
//
//  Service registers
//
	.RegImageCal 		= 0x02,		// Was 0x82
	.RegTemp 		= 0x00,
	.RegLowBat 		= 0x02,
//
//  Status registers
//
	.RegIrqFlags1 		= 0x00,		// Was 0x80
	.RegIrqFlags2 		= 0x00,		// Was 0x40 (possibly in error?)
//
//  I/O control registers
//
	.RegDioMapping1 	= 0x00,
	.RegDioMapping2		= 0x00,
//
//  Version register
//
	.RegVersion 		= 0x00,		// Was 0x12 (read only Version value should be 0x12)
//
//  Additional registers
//
	.RegPllHop 		= 0x2D,
	.RegTcxo 		= 0x09,
	.RegPaDac 		= 0x84,
	.RegFormerTemp 		= 0x00,
	.RegBitRateFrac 	= 0x00,
//
//  Additional registers; Band specific
//  These are for for LF because RegOpMode.LowFrequencyModeOn = 1 upon POR
//
	.RegAgcRef 		= 0x19,		// Was 0x13
	.RegAgcThresh1 		= 0x0C,		// Was 0x0E
	.RegAgcThresh2 		= 0x4B,		// Was 0x5B
	.RegAgcThresh3 		= 0xCC,		// Was 0xDB
	.RegPll 		= 0xD0
};



//
//  Intended setup values after POR and needing to be set for OreSat testing.
//
//  NB:  Values marked with an "*" are modified from POR default
//
struct SX1236 defaults = {
	.RegFifo 		= 0x00,		//
//
//  Common settings
//
	.RegOpMode 		= 0x09,		// *  Bit field portion Mode (2-0) will change as transceiver is used
	.RegBitrateMsb 		= 0x06,		// *  Set BR to 19k2 bps
	.RegBitrateLsb 		= 0x83,		// *
	.RegFdevMsb 		= 0x01,		// *  Set FDEV t0 20 kHz, so Fdev(13,0) = 0x0148
	.RegFdevLsb 		= 0x48,		// *
	.RegFrfMsb 		= 0x6D,		// *  Set RF Frequency to 436.5 MHz
	.RegFrfMid 		= 0x20,		// *
	.RegFrfLsb 		= 0x00,		// *
//
//  Transmitter
//
	.RegPaConfig 		= 0x00,		// *  Set transmitter power to -4.2 dBm
	.RegPaRamp 		= 0x09,		//
	.RegOcp 		= 0x2B,		//
//
//  Receiver
//
	.RegLna 		= 0x20,		//
	.RegRxConfig 		= 0x0E,		//
	.RegRssiConfig 		= 0x02,		//
	.RegRssiCollision 	= 0x0A,		//
	.RegRssiThresh 		= 0xFF,		//
	.RegRssiValue 		= 0x00,		//
	.RegRxBw 		= 0x15,		//
	.RegAfcBw 		= 0x0B,		//
	.RegOokPeak 		= 0x28,		//
	.RegOokFix 		= 0x0C,		//
	.RegOokAvg 		= 0x12,		//
	.RegAfcFei 		= 0x00,		//
	.RegAfcMsb 		= 0x00,		//
	.RegAfcLsb 		= 0x00,		//
	.RegFeiMsb 		= 0x00,		//
	.RegFeiLsb 		= 0x00,		//
	.RegPreambleDetect 	= 0xAA,		// *  Leave Preamble Detect on
	.RegRxTimeout1 		= 0x00,		//
	.RegRxTimeout2 		= 0x00,		//
	.RegRxTimeout3 		= 0x00,		//
	.RegRxDelay 		= 0x00,		//
//
//  Oscillator
//
	.RegOsc 		= 0x05,		// *  Set CLKOUT to 1 MHz (FXOSC/32)
//
//  Packet handling
//
	.RegPreambleMsb 	= 0x00,		//
	.RegPreambleLsb 	= 0x03,		//
	.RegSyncConfig 		= 0x93,		//
	.RegSyncValue1 		= 0x55,		// *  Unsure if 0x55 is what we want
	.RegSyncValue2 		= 0x55,		// *
	.RegSyncValue3 		= 0x55,		// *
	.RegSyncValue4 		= 0x55,		// *
	.RegSyncValue5 		= 0x55,		// *
	.RegSyncValue6 		= 0x55,		// *
	.RegSyncValue7 		= 0x55,		// *
	.RegSyncValue8 		= 0x55,		// *
	.RegPacketConfig1 	= 0x90,		//
	.RegPacketConfig2 	= 0x40,		//
	.RegPayloadLength 	= 0x40,		//
	.RegNodeAdrs 		= 0x00,		//
	.RegBroadcastAdrs 	= 0x00,		//
	.RegFifoThresh 		= 0x8F,		//
//
//  Sequencer
//
	.RegSeqConfig1 		= 0x00,		//
	.RegSeqConfig2 		= 0x00,		//
	.RegTimerResol 		= 0x00,		//
	.RegTimer1Coef		= 0xF5,		//
	.RegTimer2Coef		= 0x20,		//
//
//  Service registers
//
	.RegImageCal 		= 0x02,		//
	.RegTemp 		= 0x00,		//
	.RegLowBat 		= 0x02,		//
//
//  Status registers
//
	.RegIrqFlags1 		= 0x00,		//
	.RegIrqFlags2 		= 0x00,		//
//
//  I/O control registers
//
	.RegDioMapping1 	= 0x00,		//
	.RegDioMapping2		= 0x00,		//
//
//  Version register
//
	.RegVersion 		= 0x00,		//
//
//  Additional registers
//
	.RegPllHop 		= 0x2D,		//
	.RegTcxo 		= 0x09,		//
	.RegPaDac 		= 0x84,		//
	.RegFormerTemp 		= 0x00,		//
	.RegBitRateFrac 	= 0x00,		// *  Adjust for perfect 19,200 bps (16 * 3.84 = 61.44) but cant fit in 4 bits!!
//
//  Additional registers; Band specific
//  These are for for LF because we have purposely RegOpMode.LowFrequencyModeOn = 1
//
	.RegAgcRef 		= 0x19,		//
	.RegAgcThresh1 		= 0x0C,		//
	.RegAgcThresh2 		= 0x4B,		//
	.RegAgcThresh3 		= 0xCC,		//
	.RegPll 		= 0xD0		//
};

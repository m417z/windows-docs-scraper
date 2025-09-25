# _SCARD_CARD_CAPABILITIES structure

## Description

The SCARD_CARD_CAPABILITIES structure declaration defines the data that is stored in the CardCapabilites member of the SMARTCARD_EXTENSION structure and holds all information that is specific to the particular smart card that is currently used.

## Members

### `InversConvention`

Contains a flag to indicate that the current smart card uses the inverse convention.

### `etu`

Contains the elementary time unit (ETU). The ETU indicates the space of transmission time occupied by a single bit of data.

### `ATR`

 A structure with the following members:

### `ATR.Buffer`

A pointer to the buffer that receives the answer-to-reset (ATR) information that the smart card provides to the smart card reader after a warm or cold reset.

### `ATR.Length`

Contains the length, in bytes, of the ATR.

### `HistoricalChars`

 A structure with the following members:

### `HistoricalChars.Buffer`

Contains the historical characters. Historical characters designate general information, such as the smart card manufacturer, the chip inserted in the smart card, the masked ROM in the chip, and the life cycle of the smart card. For more information about historical characters, see the *ISO 7816-3 Specification* and part 4 of the *ISO 7816 Specification*. (This resource may not be available in some languages

and countries.)

### `HistoricalChars.Length`

Indicates the length, in bytes, of the historical character information.

### `ClockRateConversion`

Contains the clock conversion rate table. Using the clock rate conversion factor, F1, as an index in this array yields the maximum frequency that is allowed. For more information about clock conversion rate, see the *ISO 7816-3 specification*. (This resource may not be available in some languages

and countries.)

### `BitRateAdjustment`

Contains the bit rate adjustment table. Using the bit rate adjustment factor, D1, as an index into this array yields the maximum bit rate that is allowed. t rate. For more information about the bit rate adjustment factor, see the *ISO 7816-3 specification*. (This resource may not be available in some languages

and countries.)

### `Fl`

Contains the clock rate conversion. This factor is used as an index into a table of maximum operating frequencies. When the smart card is reset, the smart card driver library uses this value to calculate a new clock frequency.

### `Dl`

Contains the bit rate adjustment. When the smart card is reset, the smart card driver library uses this value to calculate a new data bit rate.

### `II`

Contains the maximum programming current.

### `P`

Contains the programming voltage in units of 0.1 volts.

### `N`

Contains the extra guard time in units of the ETU. The ETU indicates the space of transmission time occupied by a single bit of data. The guard time is the minimum space of transmission time that separates two consecutive characters.

### `GT`

Contains the guard time, in units of microseconds (including the extra guard time), which is the minimum delay between two consecutive characters.

### `Protocol`

 A structure with the following members:

### `Protocol.Supported`

Contains a bitmask of the supported protocols.

### `Protocol.Selected`

Contains the protocol that is selected.

### `T0`

 A structure with the following members:

### `T0.WI`

Contains the work-waiting integer for the T=0 protocol.

### `T0.WT`

Contains the work-waiting time, in microseconds, for the T=0 protocol, which is the maximum delay allowed between two consecutive characters.

### `T1`

 A structure with the following members:

### `T1.IFSC`

Contains the size, in bytes, of the card's information field.

### `T1.CWI`

Contains the character-waiting integer.

### `T1.BWI`

Contains the block-waiting integer.

### `T1.EDC`

Contains the error detection code.

### `T1.CWT`

Contains the character-waiting time, in microseconds, for the T=1 protocol, which is the maximum delay that is allowed between two consecutive characters.s.

### `T1.BWT`

Contains the block-waiting time, in microseconds, for the T=1 protocol. This is the maximum delay between the end of a block and the start of the next block that is sent in the opposite direction.

### `T1.BGT`

Contains the block-guarding time, in microseconds, for the T=1 protocol. This is the minimum delay between the end of a block and the start of the next block that is sent in the opposite direction.

### `PtsData`

Contains a PTS_DATA structure that holds all the information that is required to perform a protocol type selection (PTS) request for the inserted smart card.art card.

### `Reserved`

Reserved.

## Remarks

The SCARD_CARD_CAPABILITIES structure describes the capabilities of the inserted smart card. If the reader driver uses the smart card driver library, **ATR** is the only member that the reader driver should populate. The driver library will automatically update all other fields when it receives an [IOCTL_SMARTCARD_SET_PROTOCOL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548909(v=vs.85)) request.
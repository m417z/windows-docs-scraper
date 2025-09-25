# _SCARD_READER_CAPABILITIES structure

## Description

The SCARD_READER_CAPABILITIES structure holds state information about the smart card reader.

## Members

### `SupportedProtocols`

Must be set to a bitmask that reflects the asynchronous or synchronous protocols that the card reader and card reader driver support. This member is required.

### `Reserved`

Reserved for system use.

### `ReaderType`

This member contains the reader type and is required. This member can have one of the values in the following table.

| Value | Meaning |
| --- | --- |
| SCARD_READER_TYPE_SERIAL | Serial reader |
| SCARD_READER_TYPE_PCMCIA | PCMCIA reader |
| SCARD_READER_TYPE_KEYBOARD | Keyboard-attached reader |
| SCARD_READER_TYPE_USB | USB reader |
| SCARD_READER_TYPE_PARALELL | Parallel reader |
| SCARD_READER_TYPE_SCSI | SCSI reader |
| SCARD_READER_TYPE_IDE | IDE reader |
| SCARD_READER_TYPE_TPM | Reader that uses a TPM chip for key material storage and cryptographic operations |
| SCARD_READER_TYPE_VENDOR | Reader that uses a proprietary vendor bus |

### `MechProperties`

Contains a value that is formed by taking a bitwise OR of all applicable reader properties shown in the following table. This member is optional.

| Value | Meaning |
| --- | --- |
| SCARD_READER_SWALLOWS | Reader has a swallowing mechanism. |
| SCARD_READER_EJECTS | Reader can eject the smart card. |
| SCARD_READER_CONFISCATES | Reader can swallow the smart card. |

### `CurrentState`

This member contains the status of the card and is required. This member can have one of the values listed in the following table.

| Status | Meaning |
| --- | --- |
| SCARD_UNKNOWN | The reader does not have information about the status. |
| SCARD_ABSENT | No smart card is inserted. |
| SCARD_PRESENT | A smart card is inserted. |
| SCARD_SWALLOWED | A smart card is inserted and the reader has swallowed it. |
| SCARD_POWERED | The smart card is turned on, but the reader does not recognize its mode. |
| SCARD_NEGOTIABLE | A smart card is inserted and awaits protocol negotiation. |
| SCARD_SPECIFIC | A smart card is inserted and a protocol has been selected. |

Access to this field must be sequentialized by using the spin lock pointed to by the **OsData->SpinLock** member of [SMARTCARD_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension).

### `Channel`

Contains the logical channel number. This member is optional. The exact meaning of this member depends on the type of smart card, as shown in the following table.

| Type of smart card | Meaning of value in channel field |
| --- | --- |
| Serial reader | Port number |
| Parallel reader | Port number |
| SCSI reader | SCSI ID |
| Keyboard reader | 0 |
| USB reader | Device number |

For more information, see Part 3 of the *Interoperability Specification for ICCs and Personal Computer Systems*.

### `CLKFrequency`

 A structure with the following members:

### `CLKFrequency.Default`

Contains the standard clock frequency at which the reader runs, in kilohertz, and encoded in little-endian format. For example, 3.58 MHz is encoded as 3580. This member is required.

### `CLKFrequency.Max`

Contains the maximum clock frequency at which the reader can run, in kilohertz, and encoded in little-endian format. This member is required.

### `DataRate`

 A structure with the following members:

### `DataRate.Default`

Contains the standard data rate of the reader, in units of bits per second, and encoded in little-endian format. This member is required.

### `DataRate.Max`

Contains the maximum data rate of the reader, in units of bits per second, and encoded in little-endian format. This member is required.

### `MaxIFSD`

Contains the maximum buffer size of the reader. This value informs the smart card at the beginning of a T=1 transmission of the maximum number of bytes that can be received in one packet. This member is required.

### `PowerMgmtSupport`

Indicates the type of power management that the card supports. A value of zero indicates that the smart card does not support power management.

### `CardConfiscated`

If **TRUE**, indicates that the smart card was confiscated.

### `DataRatesSupported`

 A structure with the following members:

### `DataRatesSupported.List`

Contains a list of data rates, in bits per second, that are supported by the reader. This member is used with the PTS request. The reader driver usually sets this member to a pointer to a static array of unsigned long values that contain the supported data rates. If the reader does not support different data rates, leave this member empty. This member is optional.

### `DataRatesSupported.Entries`

Contains the number of linked list entries in DataRatesSupported.List. This member is optional.

### `_DataRatesSupported`

 A structure with the following members:

### `CLKFrequenciesSupported`

 A structure with the following members:

### `CLKFrequenciesSupported.List`

Contains a list of clock frequencies, in kilohertz, that are supported by the reader. This member is used with the PTS request. The driver usually sets this member to a pointer to a static array of unsigned long values that contain the supported clock frequencies. If the reader does not support different clock frequencies, leave this member empty. This member is optional.

### `CLKFrequenciesSupported.Entries`

Contains the number of linked list entries of CLKFrquenciesSupported.List. This member is optional.

### `_CLKFrequenciesSupported`

 A structure with the following members:

### `Reserved1`

Reserved for system use.

## Remarks

This structure must be maintained by the smart card reader driver.
# RDF\_CARD\_POWER callback function

The RDF\_CARD\_POWER callback function resets or turns off an inserted smart card.

## Parameters

- *SmartcardExtension*
A pointer to the smart card extension, [**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension), of the device. For more information about the members of this structure, see Remarks.

## Return value

This function returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successfully executed. |
| **STATUS_NO_MEDIA** | No smart card is inserted in the reader. |
| **STATUS_IO_TIMEOUT** | The request timed out. |
| **STATUS_BUFFER_TOO_SMALL** | The user buffer is not large enough to hold the answer-to-reset (ATR). |

## Remarks

It is mandatory for smart card reader drivers to implement this callback function.

On input, the structure pointed to by **SmartcardExtension** should have the following member values:

  - **MajorIoControlCode**
Should have a value of [**IOCTL\_SMARTCARD\_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_power).

  - **IoRequest.ReplyBufferLength**
Should contain the length of the buffer.

  - **MinorIoControlCode**
Should have one of the following minor codes:
      - SCARD\_COLD\_RESET
Performs a cold reset of the smart card.
      - SCARD\_WARM\_RESET
Performs a warm reset of the smart card.
      - SCARD\_POWER\_DOWN
Turns off smart card power.

On output, the structure pointed to by **SmartcardExtension** should have the following values:

  - **IoRequest.ReplyBuffer**
Receives the ATR that is returned by the smart card. In addition, you must transfer the ATR to *SmartcardExtension-\>CardCapabilities.ATR.Buffer* so that the library can parse the ATR.

  - **IoRequest.Information**
Receives the length of the ATR.

  - **CardCapabilities.ATR.Length**
Contains the length of the ATR.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Smclib.h (include Smclib.h) |

## See also

[**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension)
# RDF\_ATR\_PARSE callback function

The RDF\_ATR\_PARSE parse function parses an answer-to-reset (ATR) for the smart card driver library when the driver library is unable to recognize or parse the smart card driver library.

## Parameters

- *SmartcardExtension*
A pointer to the smart card extension, [**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension), of the device. On input, the structure pointed to by *SmartcardExtension* should have the **MajorIoControlCode** member set to [**IOCTL\_SMARTCARD\_SET\_PROTOCOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_set_protocol).

## Return value

This function returns an NTSTATUS value, or the appropriate error value.

## Remarks

It is optional for smart card reader drivers to implement this callback function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Smclib.h (include Smclib.h) |

## See also

[**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension)
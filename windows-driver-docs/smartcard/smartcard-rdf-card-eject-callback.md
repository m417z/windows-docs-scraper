# RDF\_CARD\_EJECT callback function

The RDF\_CARD\_EJECT callback function ejects an inserted smart card from the reader.

## Parameters

- *SmartcardExtension*
A pointer to the smart card extension, [**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension), of the device. On input, **SmartcardExtension-\>MajorIoControlCode** contains [**IOCTL\_SMARTCARD\_EJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_eject).

## Return value

This function returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Function successfully executed. |
| **STATUS_NO_MEDIA** | No smart card is inserted in the reader. |
| **STATUS_IO_TIMEOUT** | The request timed out. |

## Remarks

It is optional for smart card reader drivers to implement this callback function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Smclib.h (include Smclib.h) |

## See also

[**IOCTL\_SMARTCARD\_EJECT**](https://msdn.microsoft.com/library/ff548901/(v=vs.85/))

[**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension)
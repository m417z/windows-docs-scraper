# RDF\_SET\_PROTOCOL callback function

The RDF\_SET\_PROTOCOL callback function selects a transmission protocol for the inserted smart card.

## Parameters

- *SmartcardExtension*
A pointer to the smart card extension, [**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension), of the device. For a description of the members of this structure, see Remarks.

## Return value

This function returns an NTSTATUS value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A protocol was successfully selected. |
| **STATUS_NO_MEDIA** | No smart card is inserted in the reader. |
| **STATUS_IO_TIMEOUT** | The request timed out. |
| **STATUS_BUFFER_TOO_SMALL** | The user buffer is not large enough to hold a ULONG value. |
| **STATUS_INVALID_DEVICE_STATE** | The reader is not in the correct state to select a protocol. That is, a smart card is inserted, but not reset. |
| **STATUS_INVALID_DEVICE_REQUEST** | The mask contains an unknown protocol. |

## Remarks

Smart card reader drivers must implement this callback function.

On input, the caller must pass the following values to the function:

  - **SmartcardExtension-\>MajorIoControlCode**
Contains [**IOCTL\_SMARTCARD\_SET\_PROTOCOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_set_protocol).

  - **SmartcardExtension-\>MinorIoControlCode**
Contains a bitwise OR of one or more protocols than the caller accepts. The driver must select a protocol that the inserted smart card supports. We recommend that the T = 1 protocol is given precedence over the T = 0 protocol.

| Value | Meaning |
| --- | --- |
| SCARD_PROTOCOL_RAW | Selects the raw protocol. |
| SCARD_PROTOCOL_T0 | Selects the ISO T = 0 protocol. |
| SCARD_PROTOCOL_T1 | Selects the ISO T = 1 protocol. |

  - **SmartcardExtension-\>IoRequest.ReplyBufferLength**
Contains the length of the reply buffer.

  - **SmartcardExtension-\>CardCapabilities.PtsData**
Contains the required parameters to perform the PTS request. For more information, see [**PTS\_DATA**](https://msdn.microsoft.com/library/ff548916/(v=vs.85/)).

The request returns the following values:

  - **SmartcardExtension-\>IoRequest.ReplyBuffer**
Contains the selected protocol.

  - **SmartcardExtension-\>IoRequest.Information**
Set to **sizeof**(ULONG).

The caller can supply a mask of acceptable protocols. The driver's set protocol callback routine selects one of the protocols in the mask and returns the selected protocol in **SmartcardExtension-\>IoRequest.ReplyBuffer**.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Smclib.h (include Smclib.h) |

## See also

[**IOCTL\_SMARTCARD\_SET\_PROTOCOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_set_protocol)

[**PTS\_DATA**](https://msdn.microsoft.com/library/ff548916/(v=vs.85/))

[**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension)
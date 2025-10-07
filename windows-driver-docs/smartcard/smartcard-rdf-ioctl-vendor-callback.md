# RDF\_IOCTL\_VENDOR callback function

The RDF\_IOCTL\_VENDOR callback function performs vendor-specific IOCTL operations.

## Parameters

- *SmartcardExtension*
A pointer to the smart card extension, [**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension), of the device. For more information about the members of this structure, see Remarks.

## Return value

This function returns an NTSTATUS value. Because this function executes a vendor-defined IOCTL call, the value returned depends upon the function that is performed. The possible NTSTATUS values are:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Function successfully executed. |
| **STATUS_NO_MEDIA** | No smart card is inserted in the reader. |
| **STATUS_IO_TIMEOUT** | The request timed out. |
| **STATUS_BUFFER_TOO_SMALL** | The user's reply buffer is too small. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request is not valid for the IOCTL. |
| **STATUS_PENDING** | The operation is pending. |

## Remarks

It is optional for smart card reader drivers to implement this callback function.

On input, the caller must pass the following values to the function:

  - **SmartcardExtension-\>MajorIoControlCode**
Contains a vendor-specific IOCTL code. Refer to the macro SCARD\_CTL\_CODE in *Winsmcrd.h* for information about how to define a vendor-specific IOCTL code. Note that the code must be between 2048 and 4095.

  - **SmartcardExtension-\>IoRequest.RequestBuffer**
A pointer to the user's input buffer.

  - **SmartcardExtension-\>IoRequest.RequestBufferLength**
The size, in bytes, of the user's input buffer.

  - **SmartcardExtension-\>IoRequest.ReplyBuffer**
A pointer to the user's output buffer.

  - **SmartcardExtension-\>IoRequest.ReplyBufferLength**
The size, in bytes, of the user's output buffer.

  - **SmartcardExtension-\>IoRequest.Information**
The value supplied by the request. Must be set to the number of bytes returned.

As with all other IOCTLs, a user-mode application dispatches a vendor-defined IOCTL to a smart card reader device by calling the [**DeviceIoControl**](https://msdn.microsoft.com/library/aa363216/(v=vs.85/)) function. When the IOCTL is vendor-defined, however, the application must first open the reader device for "overlapped" (that is, asynchronous) access. The application must also define an OVERLAPPED structure and pass it to the system in the last argument of **DeviceIoControl** (The OVERLAPPED structure is also described in the Windows SDK documentation.). When the operating system calls the driver's I/O control dispatch routine, it passes a DIOCPARAMETERS structure to the driver. The **lpoOverlapped** member of the DIOCPARAMETERS structure contains a pointer to the OVERLAPPED structure.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Smclib.h (include Smclib.h) |

## See also

[**SMARTCARD\_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/smclib/ns-smclib-_smartcard_extension)
# IOCTL_SMARTCARD_GET_LAST_ERROR IOCTL

## Description

The IOCTL_SMARTCARD_GET_LAST_ERROR request retrieves the error code of the most previous operation because there is no option to return an error code immediately after an overlapped operation is complete.

## Parameters

### Major code

### Input buffer

*DiocParams->cbOutBuffer*

Contains the size of the output buffer. Must be at least **sizeof**(ULONG).

### Input buffer length

### Output buffer

*DiocParams->lpvOutBuffer*

Receives the error code.

*DiocParams->lpcbBytesReturned*

Must be set to **sizeof**(ULONG).

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful, and must be returned when using this IOCTL.

Be aware that when your driver uses the smart card driver library, you should store the result of the most previously overlapped operation in the smart card extension. ion. The library will use your stored value to answer this call automatically.

## See also

[IOCTL_SMARTCARD_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsmcrd/ni-winsmcrd-ioctl_smartcard_get_state)
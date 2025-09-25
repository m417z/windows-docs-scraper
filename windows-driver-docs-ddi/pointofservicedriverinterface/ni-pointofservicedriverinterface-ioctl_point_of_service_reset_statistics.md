# IOCTL_POINT_OF_SERVICE_RESET_STATISTICS IOCTL

## Description

This I/O control function resets the specified statistic's value to zero.

## Parameters

### Major code

### Input buffer

[PosStringType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posstringtype) that names the statistic to reset to zero.

### Input buffer length

Size of the string passed in *lpInBuffer*. Set to sizeof(*PosStringType*) + the size of the string in bytes.

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following is a common error value:

- STATUS_NOT_SUPPORTED: Statistic updating or reporting is not supported.
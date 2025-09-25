# IOCTL_POINT_OF_SERVICE_MSR_AUTHENTICATE_DEVICE IOCTL

## Description

This IO control function authenticates the magnetic stripe reader (MSR).

## Parameters

### Major code

### Input buffer

Pointer to the input buffer, a [MSR_AUTHENTICATE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_msr_authenticate_device) variable.

### Input buffer length

Size of the input buffer, in bytes. Set to sizeof(**MSR_AUTHENTICATE_DEVICE**).

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are common error values:

- STATUS_ACCESS_DENIED: The device is currently claimed by another client.

- STATUS_NOT_SUPPORTED: The device does not support authentication.
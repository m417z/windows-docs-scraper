# IOCTL_POINT_OF_SERVICE_MSR_DEAUTHENTICATE_DEVICE IOCTL

## Description

This I/O control function deauthenticates the magnetic stripe reader (MSR).

## Parameters

### Major code

### Input buffer

Pointer to the input buffer, a [MSR_DEAUTHENTICATE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_msr_deauthenticate_device) variable that contains the challenge token.

### Input buffer length

Size of the input buffer, in bytes. Set to **sizeof(MSR_DEAUTHENTICATE_DEVICE)**.

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns TRUE if successful; otherwise, returns FALSE.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks
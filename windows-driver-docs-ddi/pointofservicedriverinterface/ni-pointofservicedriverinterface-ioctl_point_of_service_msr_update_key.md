# IOCTL_POINT_OF_SERVICE_MSR_UPDATE_KEY IOCTL

## Description

This I/O control function sets a new encryption key.

## Parameters

### Major code

### Input buffer

Pointer to the input buffer, a [MSR_UPDATE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_msr_update_key) variable.

### Input buffer length

Size of the input buffer, in bytes. Set to **sizeof(MSR_UPDATE_KEY)**.

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)

## Remarks
# IOCTL_POINT_OF_SERVICE_MSR_RETRIEVE_DEVICE_AUTHENTICATION IOCTL

## Description

This I/O control function retrieves the device authentication type.

## Parameters

### Major code

### Input buffer

Not used with this operation; set to **NULL**.

### Input buffer length

Not used with this operation; set to **0** (zero).

### Output buffer

Pointer to a buffer that receives a [MSR_RETRIEVE_DEVICE_AUTHENTICATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_msr_retrieve_device_authentication_data).

### Output buffer length

Size of the output buffer, in bytes. Set to sizeof(**MSR_RETRIEVE_DEVICE_AUTHENTICATION_DATA**).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks
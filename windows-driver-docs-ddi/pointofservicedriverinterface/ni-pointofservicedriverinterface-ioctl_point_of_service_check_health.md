# IOCTL_POINT_OF_SERVICE_CHECK_HEALTH IOCTL

## Description

This I/O control function checks the device health.

## Parameters

### Major code

### Input buffer

Pointer to the input buffer, a [UnifiedPosHealthCheckLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-driverunifiedposhealthchecklevel) variable.

### Input buffer length

Size of the input buffer, in bytes. Set to sizeof(*UnifiedPosHealthCheckLevel*).

### Output buffer

Pointer to a buffer that receives a [PosStringType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posstringtype) followed by the contents of the health string.

### Output buffer length

Size of the output buffer, in bytes. Set to sizeof(*PosStringType*) + enough room to hold the health string.

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following is a common error value:

- STATUS_NOT_SUPPORTED: The driver does not provide health strings.
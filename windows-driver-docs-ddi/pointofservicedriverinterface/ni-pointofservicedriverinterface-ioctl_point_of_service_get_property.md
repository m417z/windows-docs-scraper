# IOCTL_POINT_OF_SERVICE_GET_PROPERTY IOCTL

## Description

This I/O control function returns the value of the specified property from the device driver.

## Parameters

### Major code

### Input buffer

Pointer to a buffer that contains the [PosPropertyId](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_pospropertyid) for the property you want to get.

### Input buffer length

Size, in bytes, of the buffer pointed to by *lpInBuffer*. Set to sizeof(*PosPropertyId*).

### Output buffer

Pointer to a buffer that receives the property value.

### Output buffer length

Size, in bytes, of the buffer pointed to by *lpOutBuffer*.

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list shows common error values (other status values may be returned as defined by your GET property callback implementation):

- STATUS_ACCESS_DENIED: The calling thread does not have a claim on the device.

- STATUS_BUFFER_OVERFLOW: The output buffer is not large enough to contain the output value. The driver will copy as much data into the output buffer as possible.
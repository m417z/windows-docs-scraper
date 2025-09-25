# IOCTL_POINT_OF_SERVICE_SET_PROPERTY IOCTL

## Description

This I/O control function sets the specified property on the device.

## Parameters

### Major code

### Input buffer

[PosPropertyId](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ne-pointofservicedriverinterface-_pospropertyid) of the property to set followed by the value of the property. The encoding for the type follows the property ID in the byte stream.

### Input buffer length

Set to sizeof(*PosPropertyId*) + the size of the property value.

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following is a common error value (other return values may be returned as defined by your property callback implementation):

- STATUS_ACCESS_DENIED: The device is currently claimed by another client.

The client must successfully call [IOCTL_POINT_OF_SERVICE_CLAIM_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_claim_device) before using this IOCTL.
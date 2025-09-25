# IOCTL_POINT_OF_SERVICE_GET_DEVICE_BASICS IOCTL

## Description

This I/O control function gets the type of device, version, and recommended buffer size as specified by the driver.

## Parameters

### Major code

### Input buffer

32-bit encoded POS Windows Runtime (WinRT) API version. The top sixteen bits must contain the major version, and the lower sixteen bits must contain the minor version.

### Input buffer length

Size of the input buffer, in bytes. Set to sizeof(UINT32).

### Output buffer

Pointer to a buffer that receives a [PosDeviceBasicsType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posdevicebasicstype).

### Output buffer length

Size of the output buffer, in bytes. Set to sizeof(*PosDeviceBasicsType*).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list shows common error values:

- STATUS_BUFFER_TOO_SMALL: The output buffer is not large enough to contain the result.

- STATUS_INSUFFICIENT_RESOURCES: There is insufficient memory.

Provide the version of the POS WinRT API to inform the driver which version of the runtime it is working with. This IOCTL returns the version of the driver in [PosDeviceBasicsType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posdevicebasicstype), so that you can have the driver version available in the runtime API if you wish to provide it.
# KsDefaultDeviceIoCompletion function

## Description

The **KsDefaultDeviceIoCompletion** function is used to return a default response and to complete any device I/O control. It can be used in the KSDISPATCH_TABLE and as the default response to unknown Ioctl's. It is important to use this function so that queries such as property requests return the correct value rather than just STATUS_INVALID_DEVICE_REQUEST when properties are not support for instance.

## Parameters

### `DeviceObject` [in]

Specifies the device object dispatched to.

### `Irp` [in]

Specifies the IRP to return a default response to.

## Return value

The **KsDefaultDeviceIoCompletion** function returns the default response to the possible IOCTLs.

## Remarks

Note that this routine will complete the IRP.
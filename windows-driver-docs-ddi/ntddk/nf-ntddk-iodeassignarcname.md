# IoDeassignArcName macro

## Description

The **IoDeassignArcName** routine removes a symbolic link between the ARC name for a device and the named device object.

## Parameters

### `ArcName` [in]

Pointer to a buffered Unicode string that is the ARC name.

## Remarks

**IoDeassignArcName** is generally called if the driver is deleting the device object, for example, when the driver is unloading.

## See also

[IoAssignArcName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioassignarcname)
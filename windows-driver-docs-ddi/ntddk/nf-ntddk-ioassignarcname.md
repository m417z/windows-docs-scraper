# IoAssignArcName macro

## Description

The **IoAssignArcName** routine creates a symbolic link between the ARC name of a physical device and the name of the corresponding device object when it has been created.

## Parameters

### `ArcName` [in]

Pointer to a buffer containing the ARC name of the device. The ARC name must be a Unicode string.

### `DeviceName` [in]

Pointer to a buffer containing the name of the device object, representing the same device. The device object name must be a Unicode string.

## Remarks

Drivers of hard disk devices need not call this routine. Drivers of other mass storage devices, including floppy, CD-ROM, and tape devices, should call **IoAssignArcName** during their initialization.

## See also

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)
# WdfDeviceGetAlignmentRequirement function

## Description

[Applies to KMDF only]

The **WdfDeviceGetAlignmentRequirement** method retrieves a device's address alignment requirement for memory transfer operations.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceGetAlignmentRequirement** returns the device's current alignment requirement. This value is one of the FILE_*XXXX*_ALIGNMENT constants that are defined in *wdm.h*.

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfDeviceSetAlignmentRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetalignmentrequirement)
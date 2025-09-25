# WdfDeviceClearRemovalRelationsDevices function

## Description

[Applies to KMDF only]

The **WdfDeviceClearRemovalRelationsDevices** method removes all devices from the list of devices that must be removed when a specified device is removed.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfDeviceAddRemovalRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceaddremovalrelationsphysicaldevice)

[WdfDeviceRemoveRemovalRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceremoveremovalrelationsphysicaldevice)
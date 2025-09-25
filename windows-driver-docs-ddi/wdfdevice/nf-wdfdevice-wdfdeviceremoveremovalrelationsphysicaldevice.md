# WdfDeviceRemoveRemovalRelationsPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfDeviceRemoveRemovalRelationsPhysicalDevice** method removes a specified device from the list of devices that must be removed when another specified device is removed.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PhysicalDevice` [in]

A pointer to a caller-supplied [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a physical device object (PDO).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfDeviceAddRemovalRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceaddremovalrelationsphysicaldevice)

[WdfDeviceClearRemovalRelationsDevices](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceclearremovalrelationsdevices)
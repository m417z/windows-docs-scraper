# WdfPdoRemoveEjectionRelationsPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfPdoRemoveEjectionRelationsPhysicalDevice** method removes a specified device from the list of devices that must be ejected when another specified device is ejected.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PhysicalDevice` [in]

A pointer to a caller-supplied [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a physical device object (PDO).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The *PhysicalDevice* parameter points to a PDO of a device that **WdfPdoRemoveEjectionRelationsPhysicalDevice** removes from the list of devices that must be ejected when the device represented by the *Device* parameter is ejected.

For more information, see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

#### Examples

The following code example removes the device that the **pPhysicalDeviceObject** structure represents from the list of devices that are ejected when the device that **device** specifies is ejected.

```cpp
PDEVICE_OBJECT  pPhysicalDeviceObject;
NTSTATUS  status;
...
status = WdfPdoRemoveEjectionRelationsPhysicalDevice(
                                                     device,
                                                     pPhysicalDeviceObject
                                                     );
```

## See also

[WdfPdoAddEjectionRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoaddejectionrelationsphysicaldevice)

[WdfPdoClearEjectionRelationsDevices](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoclearejectionrelationsdevices)
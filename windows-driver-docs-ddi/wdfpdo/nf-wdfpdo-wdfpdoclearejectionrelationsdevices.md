# WdfPdoClearEjectionRelationsDevices function

## Description

[Applies to KMDF only]

The **WdfPdoClearEjectionRelationsDevices** method removes all devices from the list of devices that must be ejected when a specified device is ejected.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

For more information, see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

#### Examples

The following code example clears the specified device's list of ejection relations.

```cpp
WdfPdoClearEjectionRelationsDevices(device);
```

## See also

[WdfPdoAddEjectionRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoaddejectionrelationsphysicaldevice)

[WdfPdoRemoveEjectionRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoremoveejectionrelationsphysicaldevice)
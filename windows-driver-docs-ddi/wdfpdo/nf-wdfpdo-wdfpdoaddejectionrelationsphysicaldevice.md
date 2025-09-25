# WdfPdoAddEjectionRelationsPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfPdoAddEjectionRelationsPhysicalDevice** method indicates that a specified device is ejected when another specified device is ejected.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PhysicalDevice` [in]

A pointer to a caller-supplied [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a physical device object (PDO).

## Return value

If the operation succeeds, the method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation failed. |

The method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The *PhysicalDevice* parameter points to a PDO of a device that is ejected when the device that is identified by *Device* is ejected. Typically, both devices are controlled by the calling driver. Do not report the child devices of *Device* because when the PnP manager ejects a parent device, it also ejects the device's children.

For more information, see [Supporting Ejectable Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-ejectable-devices).

#### Examples

The following code example adds a device that the **pPhysicalDeviceObject** structure represents to the list of devices that are ejected when the device that **device** specifies is ejected.

```cpp
PDEVICE_OBJECT  pPhysicalDeviceObject;
NTSTATUS  status;
...
status = WdfPdoAddEjectionRelationsPhysicalDevice(
 device,
 pPhysicalDeviceObject
                                                  );
```

## See also

[WdfPdoClearEjectionRelationsDevices](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoclearejectionrelationsdevices)

[WdfPdoRemoveEjectionRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoremoveejectionrelationsphysicaldevice)
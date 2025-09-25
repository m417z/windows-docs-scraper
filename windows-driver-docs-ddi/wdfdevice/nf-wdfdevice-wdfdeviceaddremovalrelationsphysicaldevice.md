# WdfDeviceAddRemovalRelationsPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfDeviceAddRemovalRelationsPhysicalDevice** method indicates that a specified device must be removed when another specified device is removed.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PhysicalDevice` [in]

A pointer to a caller-supplied [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a physical device object (PDO).

## Return value

If the operation succeeds, **WdfDeviceAddRemovalRelationsPhysicalDevice** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *PhysicalDevice* is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation failed. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The *PhysicalDevice* parameter points to a PDO of a device whose drivers must be removed when the drivers for *Device* are removed. Typically, both devices are controlled by the calling driver. Do not report the child devices of the device object specified in *Device* because when the Plug and Play manager removes a parent device, it also removes the device's children.

Your driver can call **WdfDeviceAddRemovalRelationsPhysicalDevice** multiple times to add multiple devices to the list of devices that must be removed when *Device* is removed. The order in which the specified devices are removed is not defined.

#### Examples

The following code example adds the device that **pPdo** identifies to the list of devices that must be removed when the device that **device** specifies is removed.

```cpp
status = WdfDeviceAddRemovalRelationsPhysicalDevice(
                                                    device,
                                                    pPdo
                                                    );
```

## See also

[WdfDeviceClearRemovalRelationsDevices](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceclearremovalrelationsdevices)

[WdfDeviceRemoveRemovalRelationsPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceremoveremovalrelationsphysicaldevice)
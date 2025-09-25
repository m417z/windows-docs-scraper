# _KSDEVICE structure

## Description

The KSDEVICE structure describes a WDM functional device that is managed by AVStream.

## Members

### `Descriptor`

A pointer to a [KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor) structure that describes the characteristics of the device and the static filters supported by it.

### `Bag`

This member specifies the KSOBJECT_BAG (equivalent to type PVOID) associated with the device. See [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

### `Context`

A pointer to a memory location that contains context information for the device. AVStream stores a pointer to a device extension in this member for minidrivers that allocate a device extension in [AVStrMiniDeviceStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevicepnpstart). Memory allocated for context should be placed in the object bag using [KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag). **Context** is initialized to **NULL** at create time.

### `FunctionalDeviceObject`

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that is the WDM functional device object for the device being described.

### `PhysicalDeviceObject`

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that is the WDM physical device object for the device being described.

### `NextDeviceObject`

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that is the next device in the driver stack as determined by [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack).

### `Started`

This member indicates whether this particular device has been started or not. If **TRUE**, the device has been started. If **FALSE**, the device has not been started. This flag is set during the processing of the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) and is reset during the processing of the [IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device). A device that is not started returns STATUS_DEVICE_NOT_READY in response to all requests to create a filter.

### `SystemPowerState`

A SYSTEM_POWER_STATE-typed value that indicates the current power state of the system. SYSTEM_POWER_STATE values are defined in *wdm.h*.

### `DevicePowerState`

A DEVICE_POWER_STATE-typed value that indicates the current power state of the device. DEVICE_POWER_STATE values are defined in *wdm.h*.

## Remarks

Clients typically use this structure if they must implement specific PnP or Power Management behavior that is not provided by AVStream. A pointer to a KSDEVICE structure is the first parameter to all dispatch routines specified in [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch), and the client is free to use the context information to attach its own context for these routines. In addition, clients may obtain a pointer to the KSDEVICE structure from a WDM device object pointer by calling [KsGetDeviceForDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevicefordeviceobject).

As mentioned above, **Context** is initialized to **NULL** at create time. However, descendants of this KSDEVICE structure have their corresponding **Context** members set to the value of the parent object's **Context** member. This happens when the new object is created. For more information, see [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy) and [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags). Also see the reference pages for the possible AVStream descendant objects: [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory), [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) and [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin).

## See also

[KSDEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_descriptor)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsGetDeviceForDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevicefordeviceobject)
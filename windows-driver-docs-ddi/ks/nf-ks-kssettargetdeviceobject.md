# KsSetTargetDeviceObject function

## Description

The **KsSetTargetDeviceObject** function sets the target device object of an object. The function adds the object header to a list of object headers that have target devices.

## Parameters

### `Header` [in]

Points to a header previously allocated by [KsAllocateObjectHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectheader).

### `TargetDevice` [in, optional]

Optionally contains the target device object that will be used when recalculating the stack depth for the underlying device object. If the value is **NULL**, any current setting is removed. If the value is any setting other than **NULL**, the current setting is replaced.

## Return value

None

## Remarks

The **KsSetTargetDeviceObject** function assumes that the caller has previously allocated a device header on the underlying device object with the **KsAllocateDeviceHeader** function. The presence of the device header allows future calls to the function **KsRecalculateStackDepth**, and the device header is used when the object will be forwarding IRPs through a connection to another device and needs to keep track of the stack depth.

If **KsSetDevicePnpAndBaseObject** is also used to assign the PnP object stack, that device object will also be taken into account when recalculating stack depth.

## See also

[KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader)

[KsAllocateObjectHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectheader)

[KsRecalculateStackDepth](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksrecalculatestackdepth)

[KsSetDevicePnpAndBaseObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetdevicepnpandbaseobject)
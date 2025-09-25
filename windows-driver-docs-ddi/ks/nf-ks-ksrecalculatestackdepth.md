# KsRecalculateStackDepth function

## Description

The **KsRecalculateStackDepth** function recalculates the maximum stack depth required by the underlying device object based on all of the objects that have set a target device (they have added themselves to the object list on the underlying device object using the **KsSetTargetDeviceObject** function). If the PnP device object has been set on the underlying device header using **KsSetDevicePnpAndBaseObject**, that device is also taken into account when calculating the maximum stack depth.

## Parameters

### `Header` [in]

Points to a header previously allocated by **KsAllocateDeviceHeader**.

### `ReuseStackLocation` [in]

If this is set to **TRUE**, the current stack location is reused when any IRP is forwarded. This means that this object does not require its own stack location when forwarding IRPs and an extra location is not added to the maximum stack size. If set to **FALSE**, the calculated stack size is incremented by one. If the Pnp object stack is set, the reuse parameter also applies to that stack. Note that **KsDefaultDispatchPnp** always reuses the current stack location. The minimum stack depth is 1.

## Return value

None

## Remarks

The **KsRecalculateStackDepth** function assumes that **KsSetDevicePnpAndBaseObject** has been called on this device header and has assigned a base object whose stack depth is to be recalculated.

This function allows IRPs to be forwarded through an object by ensuring that any IRP allocated on this device will have sufficient stack locations to allow it to be forwarded. Stack depth must be recalculated on a streaming device when the device transitions out of a Stop state. It can also be recalculated when an object is freed in order to conserve resources.

## See also

[KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader)

[KsDefaultDispatchPnp](https://learn.microsoft.com/previous-versions/ff561665(v=vs.85))

[KsSetDevicePnpAndBaseObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetdevicepnpandbaseobject)

[KsSetTargetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssettargetdeviceobject)
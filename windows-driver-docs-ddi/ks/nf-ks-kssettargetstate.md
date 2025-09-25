# KsSetTargetState function

## Description

Sets the enabled state of a target device associated with the specified object header.

## Parameters

### `Header` [in]

Points to a header previously allocated by [KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader).

### `TargetState` [in]

Contains the new state of the target associated with this object header. This may be either KSTARGET_STATE_DISABLED or KSTARGET_STATE_ENABLED.

## Return value

None.

## Remarks

Assumes that such a target has been set with [KsSetTargetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssettargetdeviceobject). The target is initially disabled, and is ignored when recalculating stack depth. For WDM Streaming devices, this is called on a transition back to a Stop state, after having enabled the target and used [KsRecalculateStackDepth](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksrecalculatestackdepth) on a transition to Acquire state. This allows the stack depth to be minimized.
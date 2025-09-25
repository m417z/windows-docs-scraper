# D3DDDIARG_CHECKPRESENTDURATIONSUPPORT structure

## Description

Used in a call to the [CheckPresentDurationSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkpresentdurationsupport) function to check details on hardware device support for seamlessly switching to a new monitor refresh rate.

## Members

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input for which the hardware support is queried.

### `DesiredPresentDuration` [in]

The desired duration of a single present operation, in units of 100 nanoseconds.

### `ClosestSmallerDuration` [out]

The smallest supported desired duration of a single present operation on the given VidPN source, in units of 100 nanoseconds. The value must be ≤ **DesiredPresentDuration**.

See Remarks for more limitations on this value.

### `ClosestLargerDuration` [out]

The largest supported desired duration of a single present operation on the given VidPN source, in units of 100 nanoseconds. The value must be ≥ **DesiredPresentDuration**.

See Remarks for more limitations on this value.

## Remarks

Either **ClosestSmallerDuration** or **ClosestLargerDuration** can be zero. However, if both are zero, the device cannot seamlessly switch to a new refresh rate.

If both **ClosestSmallerDuration** and **ClosestLargerDuration** have the same value as **DesiredPresentDuration**, the device can precisely match **DesiredPresentDuration**.

The difference between **DesiredPresentDuration** and **ClosestSmallerDuration** (or **ClosestLargerDuration**) represents the driver’s knowledge of the device capabilities, but there will be additional error during execution. The final accuracy of the device when using per-present durations should typically be the same as the accuracy using existing presentation modes.

## See also

[CheckPresentDurationSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkpresentdurationsupport)
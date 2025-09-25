# VideoPortCreateSpinLock function

## Description

The **VideoPortCreateSpinLock** function creates a spin lock.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `SpinLock` [out]

Pointer to a memory location that will receive a pointer to the newly created spin lock.

## Return value

On success the function returns NO_ERROR. If an error occurs, the function returns an appropriate error code.

## Remarks

This routine must be called before an initial call to [VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85)) or to any other support routine that requires a spin lock as an argument.

## See also

[VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85))

[VideoPortDeleteSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdeletespinlock)
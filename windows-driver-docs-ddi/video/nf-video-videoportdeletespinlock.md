# VideoPortDeleteSpinLock function

## Description

The **VideoPortDeleteSpinLock** function deletes a given spin lock.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `SpinLock` [in]

Pointer to the spin lock to delete.

## Return value

If the spin lock is successfully deleted, **VideoPortDeleteSpinLock** returns NO_ERROR.

## Remarks

A miniport driver uses this function to delete a spin lock that was previously created in a call to [VideoPortCreateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcreatespinlock).

This routine cannot be called from an ISR or from a [VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution) callback requested where the *Priority* parameter is set to either **VpMediumPriority** or **VpHighPriority**.

## See also

[VideoPortCreateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcreatespinlock)

[VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution)
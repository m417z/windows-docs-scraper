# VideoPortQueueDpc function

## Description

The **VideoPortQueueDpc** function allows a miniport driver to queue a DPC.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `CallbackRoutine` [in]

Pointer to the miniport driver's [HwVidDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_dpc_routine) to be called when the DPC is scheduled. The callback routine must be nonpaged.

### `Context` [in]

Pointer to the miniport driver-supplied context that will be passed to *CallbackRoutine*.

## Return value

**VideoPortQueueDpc** returns **TRUE** if the DPC is successfully queued, and **FALSE** otherwise.

## Remarks

The deferred procedure is run when the IRQL on the current processor drops below DISPATCH_LEVEL. Callers of **VideoPortQueueDpc** must be running at IRQL >= DISPATCH_LEVEL.

## See also

[HwVidDpcRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_dpc_routine)
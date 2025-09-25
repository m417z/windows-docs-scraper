# PMINIPORT_DPC_ROUTINE callback function

## Description

*The HwVidDpcRoutine* function is a miniport driver-implemented callback that is called when a queued DPC gets scheduled.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's hardware device extension. For more information, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions).

### `Context` [in]

Contains any miniport driver-supplied data this function may need. *Context* can be **NULL** if the DPC implementation does not require additional information.

## Remarks

The miniport driver queues this DPC by calling [VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc).

Because *HwVidDpcRoutine* is called at DISPATCH_LEVEL, it must not manipulate any pageable code or data. Further, this function must be in nonpaged memory and should complete its operations as quickly as possible.

## See also

[VideoPortQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportqueuedpc)
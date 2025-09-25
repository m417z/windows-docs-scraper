# VideoPortEnableInterrupt function

## Description

The **VideoPortEnableInterrupt** function is **obsolete** and should not be called.

The **VideoPortEnableInterrupt** function reenables interrupts from a video adapter after a call to **VideoPortDisableInterrupt**.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

## Return value

If **VideoPortEnableInterrupt** succeeds, it returns NO_ERROR. Otherwise, it returns ERROR_INVALID_FUNCTION.

## Remarks

If you need to disable interrupts for the display adapter, write hardware-specific code to prevent the display adapter from generating interrupts. To subsequently enable interrupts, write hardware-specific code to allow the display adapter to resume generating interrupts.

You should not call [VideoPortDisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdisableinterrupt) or **VideoPortEnableInterrupt** for the following reasons:

* Can disable interrupts for other devices that share an interrupt vector with the display adapter.
* Disables interrupts only on the processor where the current thread is running. On a multiprocessor computer, the display adapter can still interrupt another processor.
* On a multiprocessor machine, a call to **VideoPortEnableInterrupt** might run on a different processor than the previous corresponding call to **VideoPortDisableInterrupt**. In that case, interrupts will remain disabled for the processor on which **VideoPortDisableInterrupt** ran.

If the video miniport driver has not registered an [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) routine for the display adapter, **VideoPortEnableInterrupt** returns ERROR_INVALID_FUNCTION.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VideoPortDisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdisableinterrupt)
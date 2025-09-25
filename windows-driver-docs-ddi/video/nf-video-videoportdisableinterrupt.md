# VideoPortDisableInterrupt function

## Description

The **VideoPortDisableInterrupt** function is **obsolete** and should not be called.

The **VideoPortDisableInterrupt** function disables interrupts from a video adapter. As a result, interrupts coming from the device are ignored by the operating system and are not forwarded to the driver.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

## Return value

If **VideoPortDisableInterrupt** succeeds, it returns NO_ERROR. Otherwise, it returns ERROR_INVALID_FUNCTION.

## Remarks

If you need to disable interrupts for the display adapter, write hardware-specific code to prevent the display adapter from generating interrupts. To subsequently enable interrupts, write hardware-specific code to allow the display adapter to resume generating interrupts.

You should not call **VideoPortDisableInterrupt** or [VideoPortEnableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportenableinterrupt) for the following reasons:

* Can disable interrupts for other devices that share an interrupt vector with the display adapter.
* Disables interrupts only on the processor where the current thread is running. On a multiprocessor computer, the display adapter can still interrupt another processor.
* On a multiprocessor computer, a call to **VideoPortEnableInterrupt** might run on a different processor than the previous corresponding call to **VideoPortDisableInterrupt**. In that case, interrupts will remain disabled for the processor on which **VideoPortDisableInterrupt** ran.

If the video miniport driver has not registered an [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) routine for the display adapter, **VideoPortDisableInterrupt** returns ERROR_INVALID_FUNCTION.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VideoPortEnableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportenableinterrupt)
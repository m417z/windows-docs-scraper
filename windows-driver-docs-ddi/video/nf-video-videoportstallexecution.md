# VideoPortStallExecution function

## Description

The **VideoPortStallExecution** function retains control of the processor for the specified number of microseconds and returns to the caller.

## Parameters

### `Microseconds`

Specifies the delay interval, in microseconds.

## Return value

None

## Remarks

Maximum acceptable values for *Microseconds* are thousands of microseconds during miniport driver initialization. Otherwise, the given delay interval must be no more than 50 microseconds. In general, **VideoPortStallExecution** can be called only if the miniport driver must wait for a very few microseconds for its adapter to update state.

While a miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortStallExecution**, the miniport driver should be designed to avoid such a call if at all possible. Delays while running at high hardware priorities adversely affect the overall I/O throughput of the system and can freeze the machine.

If a miniport driver has work to be done at regular intervals of more than 50 microseconds, it should implement the [HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer) function. Calls to a miniport driver-supplied *HwVidTimer* function at approximately one-second intervals can be enabled with [VideoPortStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstarttimer) and disabled with [VideoPortStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstoptimer).

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[HwVidTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_timer)

[VideoPortStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstarttimer)

[VideoPortStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstoptimer)
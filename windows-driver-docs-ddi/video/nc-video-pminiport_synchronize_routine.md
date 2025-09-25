# PMINIPORT_SYNCHRONIZE_ROUTINE callback function

## Description

*HwVidSynchronizeExecutionCallback* is an optional miniport driver function, passed in calls to **VideoPortSynchronizeExecution**.

## Parameters

### `Context`

Pointer to context data passed to the callback routine through **VideoPortSynchronizeExecution**. Usually, this is a pointer to the device extension or an offset within the device extension.

## Return value

If the operation succeeds, *HwVidSynchronizeExecutionCallback* returns **TRUE**.

## Remarks

A miniport driver with one or more functions that share memory with its [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) function must have a *HwVidSynchronizeExecutionCallback* function. Any function that shares memory with *HwVidInterrupt* must call **VideoPortSynchronizeExecution** with the *HwVidSynchronizeExecutionCallback* function to maintain the integrity of data in the shared memory area. That is, only one of the *HwVidSynchronizeExecutionCallback* and *HwVidInterrupt* functions can update state in the shared area at any given moment.

The miniport driver of an adapter that does not generate interrupts also can have an *HwVidSynchronizeExecutionCallback* function to be passed to **VideoPortSynchronizeExecution** when such a driver needs to get some critical work done at a relatively high run-time priority. For example, VGA-compatible miniport drivers with *SvgaHwIoPortXxx* functions (see [SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)) might have a *HwVidSynchronizeExecutionCallback* function that is responsible for transferring driver-buffered and validated application-issued I/O to the adapter.

*HwVidSynchronizeExecutionCallback* must not be made pageable.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[VideoPortSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsynchronizeexecution)
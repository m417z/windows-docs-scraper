# VideoPortZeroDeviceMemory function

## Description

The **VideoPortZeroDeviceMemory** function fills an adapter [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/) or other device memory with zeros.

## Parameters

### `Destination` [out]

Specifies the base address of the adapter memory area. This value must be a mapped logical address returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Length`

Specifies the size, in bytes, to be filled.

## Return value

None

## Remarks

Miniport drivers should *always* call this function, rather than **VideoPortZeroMemory**, to fill on-adapter memory with zeros.

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortZeroDeviceMemory**.

Callers of **VideoPortZeroDeviceMemory** can be running at any IRQL if the memory pointed to by the *Destination* parameter is in nonpaged pool. Otherwise, the caller must be running at IRQL < DISPATCH_LEVEL.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzeromemory)
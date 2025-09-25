# VideoPortZeroMemory function

## Description

The **VideoPortZeroMemory** function fills a block of system memory with zeros.

## Parameters

### `Destination` [out]

Specifies the starting address of the block of memory. This value must be in a mapped logical range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Length`

Specifies the size, in bytes, of the block.

## Return value

None

## Remarks

Miniport drivers' [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) functions generally call **VideoPortZeroMemory** to initialize the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure with zeros.

The given *Destination* must be in a mapped logical range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) and/or a [system space](https://learn.microsoft.com/windows-hardware/drivers/) RAM address, such as an address on the stack. Use [VideoPortZeroDeviceMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzerodevicememory) to fill any device-memory block, such as a [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/), with zeros.

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortZeroMemory**.

Callers of **VideoPortZeroMemory** can be running at any IRQL if the memory pointed to by the *Destination* parameter is in nonpaged pool. Otherwise, the caller must be running at IRQL < DISPATCH_LEVEL.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VideoPortCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcomparememory)

[VideoPortMoveMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmovememory)

[VideoPortZeroDeviceMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzerodevicememory)
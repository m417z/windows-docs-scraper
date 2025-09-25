# VideoPortReadPortUchar function

## Description

The **VideoPortReadPortUchar** function reads a byte from a mapped I/O port.

## Parameters

### `Port`

Pointer to the port. The given *Port* must be in a mapped I/O-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

## Return value

**VideoPortReadPortUchar** returns the byte read from the adapter.

## Remarks

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortReadPortUchar**.

Callers of **VideoPortReadPortUchar** can be running at any IRQL, provided that the memory pointed to by the *Port* parameter is resident, mapped device memory.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
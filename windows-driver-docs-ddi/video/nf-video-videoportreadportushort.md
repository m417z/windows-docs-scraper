# VideoPortReadPortUshort function

## Description

The **VideoPortReadPortUshort** function reads a USHORT value from a mapped I/O port.

## Parameters

### `Port`

Pointer to the port. The given *Port* must be in a mapped I/O-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

## Return value

**VideoPortReadPortUshort** returns the USHORT value read from the adapter.

## Remarks

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortReadPortUshort**.

Callers of **VideoPortReadPortUshort** can be running at any IRQL, provided that the memory pointed to by the *Port* parameter is resident, mapped device memory.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
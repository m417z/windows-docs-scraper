# VideoPortWritePortUshort function

## Description

The **VideoPortWritePortUshort** function writes a USHORT value to a mapped I/O port.

## Parameters

### `Port`

Pointer to the port. The given *Port* must be in a mapped I/O-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Value`

Specifies a USHORT value to be transferred to the adapter.

## Return value

None

## Remarks

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortWritePortUshort**.

Callers of **VideoPortWritePortUshort** can be running at any IRQL, provided that the memory pointed to by the *Port* parameter is resident, mapped device memory.

## See also

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
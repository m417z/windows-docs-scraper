# VideoPortReadPortBufferUchar function

## Description

The **VideoPortReadPortBufferUchar** function reads a number of bytes from a mapped I/O port and writes them into a buffer.

## Parameters

### `Port`

Pointer to the I/O port. The given *Port* must be in a mapped I/O-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Buffer` [out]

Pointer to a buffer into which the UCHAR values are written.

### `Count`

Specifies the number of bytes to be written to the buffer.

## Return value

None

## Remarks

The buffer must be large enough to contain at least the specified number of bytes.

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortReadPortBufferUchar**.

Callers of **VideoPortReadPortBufferUchar** can be running at any IRQL, provided that the memory pointed to by the *Buffer* parameter is resident and that pointed to by the *Port* parameter is resident, mapped device memory.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
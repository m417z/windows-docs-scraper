# VideoPortReadRegisterBufferUlong function

## Description

The **VideoPortReadRegisterBufferUlong** function reads a number of ULONG values from a mapped device memory range and writes them into a buffer.

## Parameters

### `Register`

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Buffer` [out]

Pointer to a buffer into which the ULONG values are written.

### `Count`

Specifies the number of ULONG values to be written to the buffer.

## Return value

None

## Remarks

The buffer must be large enough to contain at least the specified number of ULONG values.

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortReadRegisterBufferUlong**.

Callers of **VideoPortReadRegisterBufferUlong** can be running at any IRQL, provided that the memory pointed to by the *Buffer* parameter is resident and that pointed to by the *Register* parameter is resident, mapped device memory.

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
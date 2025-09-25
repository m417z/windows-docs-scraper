# VideoPortWriteRegisterBufferUchar function

## Description

The **VideoPortWriteRegisterBufferUchar** function writes a number of unsigned bytes to a mapped register.

## Parameters

### `Register`

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Buffer` [in]

Pointer to a buffer containing the bytes to be written.

### `Count`

Specifies the number of bytes to be transferred to the adapter.

## Return value

None

## Remarks

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortWriteRegisterBufferUchar**.

Callers of **VideoPortWriteRegisterBufferUchar** can be running at any IRQL, provided that the memory pointed to by the *Buffer* parameter is resident and that pointed to by the *Register* parameter is resident, mapped device memory.

## See also

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
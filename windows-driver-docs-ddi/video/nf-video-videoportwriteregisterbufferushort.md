# VideoPortWriteRegisterBufferUshort function

## Description

The **VideoPortWriteRegisterBufferUshort** function writes a number of USHORT values to a mapped register.

## Parameters

### `Register`

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

### `Buffer` [in]

Pointer to a buffer containing the USHORT values to be written.

### `Count`

Specifies the number of USHORT values to be transferred to the adapter.

## Return value

None

## Remarks

A miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function can call **VideoPortWriteRegisterBufferUshort**.

Callers of **VideoPortWriteRegisterBufferUshort**can be running at any IRQL, provided that the memory pointed to by the *Buffer* parameter is resident and that pointed to by the *Register* parameter is resident, mapped device memory.

## See also

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)
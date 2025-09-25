# VideoPortLockBuffer function

## Description

The **VideoPortLockBuffer** function probes the specified buffer, makes the buffer's memory pages resident in memory, and locks the physical pages mapped by the virtual address range.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `BaseAddress` [in]

Specifies the virtual address of the buffer to be locked.

### `Length` [in]

Specifies the length in bytes of the buffer to be locked.

### `Operation` [in]

Specifies the type of operation for which the caller wants the access rights probed and the pages locked. The operation can be one of the following: **VpReadAccess**, **VpWriteAccess**, or **VpModifyAccess**.

## Return value

Returns a pointer to a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)), or a **NULL** pointer if the MDL for the memory to be locked cannot be allocated.

## Remarks

To unlock the buffer, the video miniport driver should call [VideoPortUnlockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunlockbuffer).

## See also

[VideoPortUnlockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunlockbuffer)
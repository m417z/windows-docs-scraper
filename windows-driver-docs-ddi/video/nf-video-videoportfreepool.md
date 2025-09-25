# VideoPortFreePool function

## Description

The **VideoPortFreePool** function deallocates a block of pool memory previously allocated by [VideoPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatepool).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Ptr` [in]

Pointer to the first byte of the memory to be freed.

## Return value

None

## Remarks

**VideoPortFreePool** is intended to replace **VideoPortReleaseBuffer**, which is obsolete.

Callers of **VideoPortFreePool** must be running at IRQL <= DISPATCH_LEVEL. A caller at DISPATCH_LEVEL must have specified a **VpNonPaged** *XxxPoolType* when the memory was allocated. Otherwise, the caller must be running at IRQL < DISPATCH_LEVEL.

## See also

[VideoPortAllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatecommonbuffer)

[VideoPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportallocatepool)
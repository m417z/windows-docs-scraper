# VideoPortFreeCommonBuffer function

## Description

The **VideoPortFreeCommonBuffer** function is **obsolete** and is supported only for backward compatibility with existing drivers. In its place, driver writers should use [VideoPortReleaseCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasecommonbuffer).

**VideoPortFreeCommonBuffer** deallocates system memory that was allocated by a call to [VideoPortGetCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetcommonbuffer).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Length` [in]

Specifies the number of bytes of memory to be freed.

### `VirtualAddress` [in]

Pointer to the corresponding virtual address of the allocated memory range.

### `LogicalAddress` [in]

Specifies the logical address of the buffer to be freed.

### `CacheEnabled` [in]

Indicates whether the allocated memory is cached.

## Return value

None

## Remarks

Except for [VideoPortGetCommonBuffer's](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetcommonbuffer) *Alignment* parameter, all of the parameters used in a call to **VideoPortFreeCommonBuffer** must have the same values as those used in the previous call to **VideoPortGetCommonBuffer**.

## See also

[VideoPortGetCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetcommonbuffer)

[VideoPortReleaseCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportreleasecommonbuffer)
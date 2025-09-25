# VideoPortMapDmaMemory function

## Description

The **VideoPortMapDmaMemory** function is **obsolete** in Windows 2000 and later.

**VideoPortMapDmaMemory** maps a range of memory for use in DMA transfers.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pVrp` [in]

Pointer to a [VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet).

### `BoardAddress` [in]

Specifies the adapter's beginning address.

### `Length` [in]

Specifies the length, in bytes, of the range of memory.

### `InIoSpace` [in]

Indicates the location of the range. This parameter can be one of the following values:

|Value|Meaning|
|--- |--- |
|VIDEO_MEMORY_SPACE_DENSE|Memory is densely mapped and linear.|
|VIDEO_MEMORY_SPACE_IO|The range is in system I/O space. Should not be set by the display driver.|
|VIDEO_MEMORY_SPACE_MEMORY|The range is in memory space. Should not be set by the display driver.|
|VIDEO_MEMORY_SPACE_P6CACHE|P6 MTRR caching, which is equivalent to write-combine caching. (kernel and user mode).|
|VIDEO_MEMORY_SPACE_USER_MODE|Memory pointer for application use.|

### `MappedUserEvent` [in]

Is reserved for system use.

### `DisplayDriverEvent` [in]

Is reserved for system use.

### `VirtualAddress` [in, out]

Is reserved for system use.

## Return value

**VideoPortMapDmaMemory** always returns **NULL**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.
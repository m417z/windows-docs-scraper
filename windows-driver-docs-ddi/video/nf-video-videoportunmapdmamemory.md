# VideoPortUnmapDmaMemory function

## Description

The **VideoPortUnmapDmaMemory** function is **obsolete** in Windows 2000 and later.

**VideoPortUnmapDmaMemory** unmaps a range of memory previously mapped by [VideoPortMapDmaMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapdmamemory).

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `VirtualAddress`

Pointer to a virtual address within the mapped range to be released.

### `ProcessHandle`

Is the handle to the current process.

### `BoardMemoryHandle`

Is the handle to adapter's memory.

## Return value

**VideoPortUnmapDmaMemory** always **FALSE**.

## Remarks

See [Bus-Master DMA in Video Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/bus-master-dma-in-video-miniport-drivers) for information about packet-based and common-buffer DMA transfers.
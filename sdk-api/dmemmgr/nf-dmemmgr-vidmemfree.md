# VidMemFree function

## Description

The **VidMemFree** function frees [off-screen memory](https://learn.microsoft.com/windows-hardware/drivers/) allocated for a display driver by [HeapVidMemAllocAligned](https://learn.microsoft.com/windows/desktop/api/dmemmgr/nf-dmemmgr-heapvidmemallocaligned).

## Parameters

### `pvmh` [in]

Pointer to a [VMEMHEAP](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-vmemheap) structure that represents the DirectDraw heap from which the surface was allocated. The driver obtains this value from the **lpHeap** member of the [VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory) structure originally passed to **HeapVidMemAllocAligned**.

### `ptr` [in]

Specifies the FLATPTR offset of the allocated surface. This data type is equivalent to a ULONG_PTR.

## See also

[HeapVidMemAllocAligned](https://learn.microsoft.com/windows/desktop/api/dmemmgr/nf-dmemmgr-heapvidmemallocaligned)

[VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory)

[VMEMHEAP](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-vmemheap)
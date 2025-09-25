# DXGKARGCB_GETCAPTUREADDRESS structure

## Description

The **DXGKARGCB_GETCAPTUREADDRESS** structure contains the arguments used in the [**DXGKCB_GETCAPTUREADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_getcaptureaddress) callback function, to retrieve information about a capture buffer that is associated with an allocation.

## Members

### `hAllocation` [in]

A handle to the allocation that is associated with the capture buffer to retrieve information on.

### `SegmentId` [out]

The identifier of the segment for the capture buffer. The allocation that is associated with the capture buffer is currently paged in this segment.

### `PhysicalAddress` [out]

The physical address of the capture buffer.

## See also

[**DXGKCB_GETCAPTUREADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_getcaptureaddress)
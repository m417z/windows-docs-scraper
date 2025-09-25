# _DXGK_QUERYSEGMENTOUT structure

## Description

The DXGK_QUERYSEGMENTOUT structure describes memory-segment information that the display miniport driver should return from a call to its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `NbSegment` [out]

The number of memory segments that the driver supports.

### `pSegmentDescriptor` [out]

An array of [DXGK_SEGMENTDESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor) structures that the driver populates with information about the segments it supports. The size of the array is the value that **NbSegment** specifies.

### `PagingBufferSegmentId` [out]

The identifier of the segment that the video memory manager should allocate the paging buffer from. This segment must be an aperture segment.

### `PagingBufferSize` [out]

The size, in bytes, that the video memory manager should allocate for the paging buffer.

### `PagingBufferPrivateDataSize` [out]

The size, in bytes, of the driver-resident private data structure that is associated with each paging buffer. Memory for this private data structure is allocated from nonpaged pool. If the driver specifies zero for **PagingBufferPrivateDataSize**, no memory is allocated for the private data structure.

The private data structure that is associated with a paging buffer is initialized to zero when the paging buffer is created. During the lifetime of the paging buffer, the video memory manager never accesses the private data structure that is associated with the paging buffer.

## Remarks

The video memory manager allocates a paging buffer either from an aperture segment (if the **PagingBufferSegmentId** member identifies the segment) or as a contiguous write-combined memory block (if **PagingBufferSegmentId** is set to 0). If **PagingBufferSegmentId** is set to 0, the graphics processing unit (GPU) must access direct memory access (DMA) buffers by using PCI cycles on systems where AGP transfers that occur outside the AGP aperture are not permitted.

## See also

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGK_QUERYSEGMENTIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentin)

[DXGK_SEGMENTDESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
# DXGK_MEMORYRANGE structure

## Description

A **DXGK_MEMORYRANGE** structure describes a range of memory.

## Members

### `SegmentOffset`

The offset from the start of the segment in bytes. The value must be aligned to the segment page boundary.

### `SizeInBytes`

The number of bytes in the range. The value must be a multiple of the segment page size.

## Remarks

One way that **DXGK_MEMORYRANGE** is used is with [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) and [**DXGK_QUERYSEGMENTMEMORYSTATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentmemorystate) to query bad GPU memory ranges. The query is done during adapter object initialization. The driver is called only if [**DXGK_SEGMENTDESCRIPTOR4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor4)::**NumInvalidMemoryRanges** isn't zero for a segment.

## See also

[**DXGK_QUERYSEGMENTMEMORYSTATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentmemorystate)

[**DXGK_SEGMENTDESCRIPTOR4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor4)

[**DXGKARG_CREATEMEMORYBASIS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_creatememorybasis)

[**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
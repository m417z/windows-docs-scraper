# _DXGK_QUERYSEGMENTMEMORYSTATE structure

## Description

**DXGK_QUERYSEGMENTMEMORYSTATE** is used with [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) to query invalid graphics processing unit (GPU) memory ranges.

## Members

### `DriverSegmentId`

A 1-based segment identifier of a local GPU memory segment.

### `PhysicalAdapterIndex`

Physical adapter index in a linked display adapter link.

### `NumUEFIFrameBufferRanges`

### `NumInvalidMemoryRanges`

The number of entries in the **pMemoryRanges** array. This is the value returned by the kernel mode driver in [DXGK_SEGMENTDESCRIPTOR4](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor4).

### `pMemoryRanges`

Array of [DXGK_MEMORYRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_memoryrange) structures for the invalid memory ranges.

## See also

[DXGK_MEMORYRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_memoryrange)

[DXGK_SEGMENTDESCRIPTOR4](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor4)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
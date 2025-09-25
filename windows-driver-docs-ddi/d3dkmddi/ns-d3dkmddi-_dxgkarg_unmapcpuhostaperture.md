# _DXGKARG_UNMAPCPUHOSTAPERTURE structure

## Description

The **DXGKARG_UNMAPCPUHOSTAPERTURE** structure is used to unmap a previously mapped range of the CPU host aperture.

## Members

### `NumberOfPages`

Specifies the number of pages being unmapped.

### `pCpuHostAperturePages`

Array of CPU host aperture pages to unmap. This is an array of page indices from the start of the CPU host aperture physical address.

### `SegmentId`

The driver segment identifier (starting from 1) of the segment for which the CPU host aperture is unmapped.

### `PhysicalAdapterIndex`

The zero-based physical adapter index in a linked display adapter link.

**Note** The page size is equal to the segment page size.

## See also

[DxgkDdiUnmapCpuHostAperture](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_unmapcpuhostaperture)
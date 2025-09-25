# _DXGK_QUERYSEGMENTIN structure

## Description

The DXGK_QUERYSEGMENTIN structure describes relevant information for a memory-segment query through a call to the display miniport driver's [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `AgpApertureBase` [in]

A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the base address of the AGP aperture.

### `AgpApertureSize` [in]

A LARGE_INTEGER that indicates the size, in bytes, of the available AGP aperture.

### `AgpFlags` [in]

A [DXGK_SEGMENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentflags) structure that identifies properties for the available AGP aperture in bit-field flags.

## See also

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGK_QUERYSEGMENTOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout)

[DXGK_SEGMENTDESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor)

[DXGK_SEGMENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentflags)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
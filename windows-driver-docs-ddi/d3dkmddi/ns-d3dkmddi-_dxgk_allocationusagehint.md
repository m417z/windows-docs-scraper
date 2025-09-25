# _DXGK_ALLOCATIONUSAGEHINT structure

## Description

The DXGK_ALLOCATIONUSAGEHINT structure contains allocation usage and version information that is used as a hint about how to use an allocation.

## Members

### `Version` [out]

A positive integer that indicates the version of the allocation.

### `v1` [out]

A [DXGK_ALLOCATIONUSAGEINFO1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationusageinfo1) structure that describes how an allocation can be used in direct memory access (DMA) buffering.

## See also

[DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_ALLOCATIONUSAGEINFO1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationusageinfo1)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)
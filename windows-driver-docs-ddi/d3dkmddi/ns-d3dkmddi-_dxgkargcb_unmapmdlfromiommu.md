# DXGKARGCB_UNMAPMDLFROMIOMMU structure

## Description

The **DXGKARGCB_UNMAPMDLFROMIOMMU** structure contains the arguments used by the [**DXGKCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapmdlfromiommu) callback function to release the mapping that was set by [**DXGKCB_MAPMDLTOIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapmdltoiommu).

## Members

### `hMemoryHandle` [in]

A *Dxgkrnl* tracking handle for the allocation to be released.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[DXGKCB_UNMAPMDLFROMIOMMU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapmdlfromiommu)
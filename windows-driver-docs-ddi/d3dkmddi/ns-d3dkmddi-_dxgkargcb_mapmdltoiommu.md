# DXGKARGCB_MAPMDLTOIOMMU structure

## Description

The **DXGKARGCB_MAPMDLTOIOMMU** structure contains the arguments used by the [**DXGKCB_MAPMDLTOIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapmdltoiommu) callback function, to map a memory descriptor list (MDL) to the IOMMU.

## Members

### `pMdl` [in]

An MDL which must be populated with valid pages. The MDL and the pages it points to must remain unchanged until the corresponding unmap call is made.

### `hMemoryHandle` [out]

A *Dxgkrnl* tracking handle for the allocation. This value should be passed to the corresponding [**DXGKCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapmdlfromiommu) function.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_MAPMDLTOIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapmdltoiommu)
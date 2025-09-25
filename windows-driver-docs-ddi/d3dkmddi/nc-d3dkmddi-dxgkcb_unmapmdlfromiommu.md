# DXGKCB_UNMAPMDLFROMIOMMU callback function

## Description

**DXGKCB_UNMAPMDLFROMIOMMU** releases the mapping that was set by [**DXGKCB_MAPMDLTOIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapmdltoiommu).

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the master/lead device in the LDA chain.

### `pUnmapMdlFromIoMmu` [in]

A pointer to the [**DXGKARGCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unmapmdlfromiommu) structure that contains a handle to the memory to be unmapped.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unmapmdlfromiommu) and then calls **DxgkCbUnmapMdlFromIoMmu** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unmapmdlfromiommu)

[**DXGKCB_MAPMDLTOIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapmdltoiommu)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)
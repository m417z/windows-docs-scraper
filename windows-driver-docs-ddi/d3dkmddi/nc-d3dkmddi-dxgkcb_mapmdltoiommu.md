# DXGKCB_MAPMDLTOIOMMU callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_MAPMDLTOIOMMU** to map a memory descriptor list (MDL) to the IOMMU so that the underlying memory can be accessed by the GPU.

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the master/lead device in the LDA chain.

### `pMapMdlToIoMmu` [in/out]

Pointer to a [**DXGKARGCB_MAPMDLTOIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapmdltoiommu) structure that contains a handle to the memory.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate member of [DXGKARGCB_MAPMDLTOIOMMU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapmdltoiommu) and then call **DxgkCbMapMdlToIoMmu** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

If the driver uses this callback, it is responsible for ensuring that the lifetime of the MDL exceeds the corresponding [**DXGKCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapmdlfromiommu) call. Otherwise the **DXGKCB_UNMAPMDLFROMIOMMU** call has undefined behavior and may lead to compromised security of the pages from the MDL. The pages could get repurposed by Mm by the time they are unmapped.

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[DXGKARGCB_MAPMDLTOIOMMU](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapmdltoiommu)

[**DXGKCB_UNMAPMDLFROMIOMMU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapmdlfromiommu)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)
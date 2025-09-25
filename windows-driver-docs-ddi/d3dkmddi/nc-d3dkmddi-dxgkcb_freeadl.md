## Description

**DXGKCB_FREEADL** destroys an address descriptor list (ADL) created in a prior call to [**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl).

## Parameters

### `pArgs` [in]

Pointer to a [**DXGKARGCB_FREE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_free_adl) structure that describes the ADL to destroy.

## Remarks

The [**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl) and **DxgkCbFreeAdl** functions are used to create and destroy address descriptor lists that describe memory addresses that can be programmed to the GPU. The underlying memory can point to either logical or physical memory depending on whether the IOMMU is being used, so the driver must not attempt to assume that these addresses represent physical pages.

Once an ADL is freed, the memory referenced by that ADL must not be accessed by the GPU.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_FREE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_free_adl) and then call **DxgkCbFreeAdl** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_FREE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_free_adl)

[**DxgkCbAllocateAdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)
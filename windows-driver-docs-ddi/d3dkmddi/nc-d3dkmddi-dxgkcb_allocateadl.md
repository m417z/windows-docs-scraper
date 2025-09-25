## Description

**DXGKCB_ALLOCATEADL** creates an address descriptor list (ADL).

## Parameters

### `pArgs` [in/out]

Pointer to a [**DXGKARGCB_ALLOCATE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_allocate_adl) structure that contains information about the ADL to create. On success, returns a [**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl) structure with a list of page addresses that can be used to program the hardware.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS error code, such as STATUS_INVALID_PARAMETER.

## Remarks

The **DXGKCB_ALLOCATEADL** and [**DXGKCB_FREEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freeadl) functions are used to create and destroy ADLs that describe memory addresses that can be programmed (mapped) to the GPU. The underlying memory can point to either logical or physical memory depending on whether the IOMMU is being used, so the driver must not attempt to assume that these addresses represent physical pages.

When an ADL is allocated from the physical object, *Dxgkrnl* guarantees that this memory remains locked and is non-pageable for the lifetime of the ADL.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_ALLOCATE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_allocate_adl) and then call **DxgkCbAllocateAdl** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_ALLOCATE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_allocate_adl)

[**DXGKCB_FREEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freeadl)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)
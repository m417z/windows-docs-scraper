## Description

**DXGKARGCB_FREE_ADL** contains the information used by the [**DXGKCB_FREEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freeadl) callback function to destroy an address descriptor list (ADL).

## Members

### `hAdapterMemoryObject` [in]

The adapter memory object that was used to create the ADL.

### `pAdl` [in]

Pointer to the [**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl) object that is being freed.

## Remarks

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl)

[**DXGKCB_ALLOCATEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl)

[**DXGKCB_FREEADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freeadl)
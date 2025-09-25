# DXGKARGCB_UNMAPFRAMEBUFFERPOINTER structure

## Description

The **DXGKARGCB_UNMAPFRAMEBUFFERPOINTER** structure contains the arguments used by the [**DXGKCB_UNMAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapframebufferpointer) callback function to release a mapping.

## Members

### `PhysicalAdapterIndex` [in]

The index of the physical adapter.

### `pBaseAddress` [in]

A CPU accessible base address pointer to the mapped subregion of the section object.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_UNMAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapframebufferpointer)
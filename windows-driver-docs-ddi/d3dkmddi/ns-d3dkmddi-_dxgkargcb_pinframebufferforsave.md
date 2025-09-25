# DXGKARGCB_PINFRAMEBUFFERFORSAVE structure

## Description

The **DXGKARGCB_PINFRAMEBUFFERFORSAVE** structure contains the arguments used by the [**DXGKCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave) callback function, to pin the frame buffer for save.

## Members

### `PhysicalAdapterIndex` [in]

The index of the physical adapter.

### `CommitSize` [in]

The size, in bytes, that the driver requires to pin. This size must be a multiple of PAGE_SIZE and must be less than or equal to the maximum size specified by the driver during initialization in [**DXGK_FRAMEBUFFERSAVEAREA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_framebuffersavearea) (during [**DXGKQAITYPE_FRAMEBUFFERSAVESIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)).

### `pMdl` [out]

An MDL pointing to the pages of the frame buffer save area. These pages are guaranteed to be mapped to the IoMmu.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave)
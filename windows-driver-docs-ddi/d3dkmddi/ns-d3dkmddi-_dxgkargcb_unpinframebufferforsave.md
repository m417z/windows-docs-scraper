# DXGKARGCB_UNPINFRAMEBUFFERFORSAVE structure

## Description

The **DXGKARGCB_UNPINFRAMEBUFFERFORSAVE** structure contains the arguments used by the [**DXGKCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave) callback function to release the mapping that was set by [**DXGKCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave).

## Members

### `PhysicalAdapterIndex` [in]

The index of the physical adapter.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave)

[**DXGKCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave)

[**DXGKARGCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_pinframebufferforsave)
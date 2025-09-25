## Description

A kernel-mode display miniport driver (KMD) returns its dirty bit tracking capabilities for a specified segment in **DXGK_DIRTY_BIT_TRACKING_SEGMENT_CAPS** when its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called with the [**DXGKQAITYPE_DIRTYBITTRACKINGSEGMENTCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) query adapter info type.

## Members

### `PageSize`

The size of a single page, represented by each bit in the dirty bit plane. **PageSize** can be any power of two value greater than or equal to 4KB.

## Remarks

If dirty plane data is not available for the segment, [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) should return STATUS_NOT_IMPLEMENTED for that particular call. *Dxgkrnl* ignores the contents of the output in this case.

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DXGK_DIRTY_BIT_TRACKING_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_dirty_bit_tracking_caps)

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
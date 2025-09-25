## Description

A kernel-mode display miniport driver (KMD) returns its dirty bit tracking capabilities in **DXGK_DIRTY_BIT_TRACKING_CAPS** when its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called with the [**DXGKQAITYPE_DIRTYBITTRACKINGCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) query adapter info type.

## Members

### `DirtyBitTrackingSupported`

 When set TRUE, the adapter supports the ability to track dirty bit information. *Dxgkrnl* will, at a later time, call the followup **DXGKQAITYPE_DIRTYBITTRACKINGSEGMENTCAPS** call for each segment to determine the page size/granularity at which the data is tracked.

### `DirtyBitTrackingPerformant`

When set TRUE, the adapter is reporting the preference to track dirty content from the creation of the vDEV. This capability can drastically improve the performance of live migration scenarios by allowing only dirty content inside VRAM reserve to be transferred. If **DirtyBitTrackingPerformant** is FALSE, dirty tracking is only enabled during the live migration itself, and the initial transfer of content will be the entire reserved VRAM for the VF being migrated.

### `Reserved`

Reserved for system use.

### `Value`

An alternative way to access the structure's bitfields.

## Remarks

For more information, see [Dirty Bit Tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
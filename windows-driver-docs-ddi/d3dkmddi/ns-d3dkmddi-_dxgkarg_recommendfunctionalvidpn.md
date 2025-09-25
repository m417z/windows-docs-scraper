# _DXGKARG_RECOMMENDFUNCTIONALVIDPN structure

## Description

The DXGKARG_RECOMMENDFUNCTIONALVIDPN structure contains arguments for the [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn) function. The *DxgkDdiRecommendFunctionalVidPn* function creates a functional video present network (VidPN) that can be implemented on a specified display adapter.

## Members

### `NumberOfVidPnTargets`

Reserved for future use.

### `pVidPnTargetPrioritizationVector`

Reserved for future use.

### `hRecommendedFunctionalVidPn`

A handle, provided by the caller, to an empty VidPN object. *DxgkDdiRecommendFunctionalVidPn* must add a path (source-target pair) to the VidPN's topology and must pin modes on the path's source and target. For information about adding paths to a topology and creating mode sets for video present sources and targets, see [VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces).

### `RequestReason`

A [DXGK_RECOMMENDFUNCTIONALVIDPN_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_recommendfunctionalvidpn_reason) value that indicates why the caller is requesting a functional VidPN.

### `pPrivateDriverData`

A pointer to a buffer that contains private data that is passed from a user-mode application to the display miniport driver.

### `PrivateDriverDataSize`

The size, in bytes, of the data block pointed to by *pPrivateDriverData*.

## See also

[DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn)
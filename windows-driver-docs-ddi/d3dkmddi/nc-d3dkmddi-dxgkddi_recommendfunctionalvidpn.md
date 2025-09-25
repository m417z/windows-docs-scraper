# DXGKDDI_RECOMMENDFUNCTIONALVIDPN callback function

## Description

The *DxgkDdiRecommendFunctionalVidPn* function creates a functional VidPN that can be implemented on a specified display adapter.

## Parameters

### `hAdapter` [in]

A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pRecommendFunctionalVidPn` [in]

A pointer to a [DXGKARG_RECOMMENDFUNCTIONALVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_recommendfunctionalvidpn) structure that contains function arguments. The caller supplies the **hRecommendedFunctionalVidPn** member, which is a handle to an empty VidPN object. *DxgkDdiRecommendFunctionalVidPn* populates the VidPN object with the elements of a functional VidPN: topology, mode sets, pinned modes.

## Return value

*DxgkDdiRecommendFunctionalVidPn* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded in creating a functional VidPN.|
|STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN|The function was not able to create a functional VidPN.|
|STATUS_NO_MEMORY|The function failed because it was unable to allocate memory.|

## Remarks

A VidPN is functional if it satisfies the following conditions:

* It has a topology that has at least one path. (A path is an association between a source and a target.)
* Every source and target in the topology has a pinned mode.

The job of *DxgkDdiRecommendFunctionalVidPn* is to create a functional VidPN that can be implemented on the display adapter. The following list gives the steps used to create a functional VidPN.

1. Start with a handle to an empty VidPN object. This handle was supplied in the **hDesiredVidPn** member of *pRecommendFunctionalVidPnArg.*
2. Add a path (source-target pair) to the topology of the VidPN.
3. Create a new source mode set and add one source mode to the set. Assign the source mode set to the source in your path. Pin the source mode.
4. Create a new target mode set and add one target mode to the set. Assign the target mode set to the target in your path. Pin the target mode.

For information about how to add paths, add mode sets, assign modes, and pin modes, see [VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces).

*DxgkDdiRecommendFunctionalVidPn* should be made pageable.
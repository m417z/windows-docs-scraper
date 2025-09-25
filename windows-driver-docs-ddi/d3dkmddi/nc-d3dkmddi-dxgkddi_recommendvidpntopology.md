# DXGKDDI_RECOMMENDVIDPNTOPOLOGY callback function

## Description

The *DxgkDdiRecommendVidPnTopology* function creates the topology of a specified VidPN or augments the topology with a new path to video present targets.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pRecommendVidPnTopology` [in]

A pointer to a [DXGKARG_RECOMMENDVIDPNTOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_recommendvidpntopology) structure that contains function arguments.

## Return value

*DxgkDdiRecommendVidPnTopology* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully created or augmented the topology.|
|STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY|The function has no recommendation for the augmentation of the specified VidPN topology.|
|STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION|The function recommends to cancel the augmentation of the specified VidPN's topology on the specified source. This return code is allowed only in the case of VidPN topology augmentation.|
|STATUS_NO_MEMORY|The function failed because it was unable to allocate enough memory.|

The miniport driver should pass through any error code that it gets from the operating system for which it does not have a fallback code path.

## Remarks

*DxgkDdiRecommendVidPnTopology*
should be made pageable.

## See also

[VidPn Topology Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)
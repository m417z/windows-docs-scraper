# DXGKDDI_VIDPNTOPOLOGY_GETNUMPATHS callback function

## Description

The **pfnGetNumPaths** function returns the number of video present paths in a specified VidPN topology.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pNumPaths` [out]

A pointer to a SIZE_T-typed variable that receives the number of paths.

## Return value

The **pfnGetNumPaths** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|

## Remarks

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.

## See also

[pfnGetNumPathsFromSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getnumpathsfromsource)
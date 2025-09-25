# DXGKDDI_VIDPNTOPOLOGY_GETNUMPATHSFROMSOURCE callback function

## Description

The **pfnGetNumPathsFromSource** function returns the number of video present paths that contain a specified video present source.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `VidPnSourceId` [in]

An integer that identifies a particular video present source.

### `pNumPathsFromSource` [out]

A pointer to a SIZE_T-typed variable that receives the number of paths that contain the specified source.

## Return value

The **pfnGetNumPathsFromSource** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|
|STATUS_INVALID_PARAMETER|The pointer supplied in pNumPathsFromSource was in valid.|

## Remarks

A topology is a collection paths, each of which contains a (source, target) pair. It is possible for a particular source to appear in more than one path. For example, one source can be paired with two distinct targets in the case of a clone view.

VidPN source identifiers are assigned by the operating system. [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... N - 1.

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.

The D3DDDI_VIDEO_PRESENT_SOURCE_ID data type is defined in *D3dukmdt.h*.

## See also

[pfnGetNumPaths](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getnumpaths)
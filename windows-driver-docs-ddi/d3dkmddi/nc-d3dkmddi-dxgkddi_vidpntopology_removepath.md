# DXGKDDI_VIDPNTOPOLOGY_REMOVEPATH callback function

## Description

The **pfnRemovePath** function removes a video present path to a specified VidPN topology object.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `VidPnSourceId` [in]

An integer that identifies a VidPN source path.

### `VidPnTargetId` [in]

An integer that identifies a VidPN target path.

## Return value

The **pfnRemovePath** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The specified video present path has been successfully removed from this VidPN topology object.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE|The VidPN source identifier supplied in VidPnSourceId is invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET|The VidPN target identifier supplied in VidPnTargetId is invalid.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology is invalid.|
|STATUS_ACCESS_DENIED|The path cannot be removed in the context of the current DDI call.|

## Remarks

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.
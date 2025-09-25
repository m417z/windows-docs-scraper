# DXGKDDI_VIDPNTOPOLOGY_GETPATHSOURCEFROMTARGET callback function

## Description

The **pfnGetPathSourceFromTarget** function returns the identifier of the video present source that is associated with a specified video present target.

## Parameters

### `hVidTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `VidPnTargetId` [in]

An integer that identifies a particular video present source.

### `pVidPnSourceId` [out]

A pointer to a variable that receives the identifier of the video present source.

## Return value

The **pfnGetPathSourceFromTarget** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|
|STATUS_INVALID_PARAMETER|The pointer supplied in pVidPnSourceId was in valid.|

## Remarks

A topology is a collection paths, each of which contains a (source, target) pair. A particular target belongs to at most one path, so given a target ID, there is at most one source associated with that target.

VidPN source identifiers are assigned by the operating system. [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... N - 1.

VidPN target identifiers are assigned by the display miniport driver. [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.

The D3DDDI_VIDEO_PRESENT_SOURCE_ID D3DDDI_VIDEO_PRESENT_TARGET_ID data types are defined in *D3dukmdt.h*.

## See also

[pfnEnumPathTargetsFromSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_enumpathtargetsfromsource)
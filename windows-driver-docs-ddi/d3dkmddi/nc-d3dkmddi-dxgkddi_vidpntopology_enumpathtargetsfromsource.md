# DXGKDDI_VIDPNTOPOLOGY_ENUMPATHTARGETSFROMSOURCE callback function

## Description

The **pfnEnumPathTargetsFromSource** function returns the identifier of one of the video present targets associated with a specified video present source.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `VidPnSourceId` [in]

An integer that identifies a particular video present source.

### `VidPnPresentPathIndex` [in]

A zero-based index into the set of paths that contain the source identified by *VidPnSourceId*.

### `pVidPnTargetId` [out]

A pointer to a variable that receives the target identifier.

## Return value

The **pfnEnumPathTargetsFromSource** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|
|STATUS_INVALID_PARAMETER|The pointer supplied in pVidPnTargetId was in valid.|

## Remarks

*VidPnPresentPathIndex* is not an index into the set of all paths in the topology identified by *hVidPnTopology*. It is an index into a subset of all the paths in the topology: specifically, the subset of all paths that contain the source identified by *VidPnSourceId*.

To enumerate (in a given topology) all the targets associated with a particular source, perform the following steps.

Call **pfnGetNumPathsFromSource** to determine the number N of paths that contain the source of interest. Think of those paths as an indexed set with indices 0, 1, ... N - 1.

For each index 0 though N - 1, pass the source identifier and the index to **pfnEnumPathTargetsFromSource**.

A topology is a collection paths, each of which contains a (source, target) pair. It is possible for a particular source to appear in more than one path. For example, one source can be paired with two distinct targets in the case of a clone view.

VidPN source identifiers are assigned by the operating system. [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... N - 1.

VidPN target identifiers are assigned by the display miniport driver. [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

The D3DKMDT_HVIDPNTOPOLOGY and D3DKMDT_VIDPN_PRESENT_PATH_INDEX data types are defined in *D3dkmdt.h*.

The D3DDDI_VIDEO_PRESENT_SOURCE_ID and D3DDDI_VIDEO_PRESENT_TARGET_ID data types are defined in *D3dukmdt.h*.

## See also

[pfnGetNumPathsFromSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getnumpathsfromsource)

[pfnGetPathSourceFromTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getpathsourcefromtarget)
# DXGKDDI_VIDPNTOPOLOGY_UPDATEPATHSUPPORTINFO callback function

## Description

The **pfnUpdatePathSupportInfo** function updates the transformation and copy protection support of a particular path in a specified VidPN topology.

## Parameters

### `i_hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `i_pVidPnPresentPathInfo` [in]

A pointer to a [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure. The **VidPnSourceId** and **VidPnTargetId** members (taken as a pair) identify the path that is to have its transformation and copy protection support updated. The **ContentTransformation** and **CopyProtection** members supply the updated transformation and copy protection support.

## Return value

The **pfnUpdatePathSupportInfo** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_TOPOLOGY|The handle supplied in i_hVidPnTopology was invalid.|
|STATUS_INVALID_PARAMETER|An invalid parameter was supplied.|
|STATUS_ACCESS_DENIED|The path cannot be removed in the context of the current DDI call.|

## Remarks

The display miniport driver's [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality) function calls **pnfUpdatePathSupportInfo** to report rotation, scaling, and copy protection support for each of the paths in a topology.
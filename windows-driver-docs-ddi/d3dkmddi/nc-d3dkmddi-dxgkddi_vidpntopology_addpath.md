# DXGKDDI_VIDPNTOPOLOGY_ADDPATH callback function

## Description

The **pfnAddPath** function adds a video present path to a specified VidPN topology object.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnPresentPath` [in]

A pointer to a D3DKMDT_VIDPN_PRESENT_PATH structure that describes the path. The display miniport driver previously obtained this pointer by calling [pfnCreateNewPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_createnewpathinfo).

## Return value

The **pfnAddPath** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|
|STATUS_ACCESS_DENIED|The path cannot be removed in the context of the current DDI call.|

## Remarks

To add a path to a topology, the display miniport driver performs the following steps.

Call [pfnCreateNewPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_createnewpathinfo) to obtain a pointer to a [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure allocated by the VidPN manager.

Populate the D3DKMDT_VIDPN_PRESENT_PATH structure with information about the path, including video present source and target identifiers.

Call **pfnAddPath** to add the path to a topology.

The VidPN manager allocates a D3DKMDT_VIDPN_PRESENT_PATH structure when you call **pfnCreateNewPathInfo**. If you add the path described by that structure to a topology, then you do not need to explicitly release the structure; **pfnAddPath** releases it.

If you obtain a D3DKMDT_VIDPN_PRESENT_PATH structure by calling **pfnCreateNewPathInfo** and then decide not to add that path to a topology, then you must explicitly release the structure by calling **pfnReleasePathInfo**.

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[pfnCreateNewPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_createnewpathinfo)

[pfnReleasePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_releasepathinfo)
# DXGKDDI_VIDPNTOPOLOGY_ACQUIREFIRSTPATHINFO callback function

## Description

The **pfnAcquireFirstPathInfo** structure returns a descriptor of the first path in a specified VidPN topology object.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `ppFirstVidPnPresentPathInfo` [out]

A pointer to a variable that receives a pointer to a [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure. The structure contains a variety of information about the path, including the path's source and target identifiers.

## Return value

The **pfnAcquireFirstPathInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|

## Remarks

When you have finished using the D3DKMDT_VIDPN_PRESENT_PATH structure, you must release the structure by calling [pfnReleasePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_releasepathinfo).

You can enumerate all the paths that belong to a VidPN topology object by calling **pfnAcquireFirstPathInfo** and then making a sequence of calls to [pfnAcquireNextPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirenextpathinfo).

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[pfnAcqirePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirepathinfo)

[pfnAcquireNextPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirenextpathinfo)

[pfnReleasePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_releasepathinfo)
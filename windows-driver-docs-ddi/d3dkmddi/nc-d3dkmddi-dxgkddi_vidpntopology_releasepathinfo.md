# DXGKDDI_VIDPNTOPOLOGY_RELEASEPATHINFO callback function

## Description

The **pfnReleasePathInfo** function releases a [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure that the VidPN manager previously provided to the display miniport driver.

## Parameters

### `hVidPnTopology` [in]

A handle to a VidPN topology object. The display miniport driver previously obtained this handle by calling the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) interface.

### `pVidPnPresentPathInfo` [in]

A pointer to the D3DKMDT_VIDPN_PRESENT_PATH structure that is to be released.

## Return value

The **pfnReleasePathInfo** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The handle supplied in hVidPnTopology was invalid.|
|STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH|The pointer supplied in pVidPnPresentPathInfo was invalid.|

## Remarks

When you have finished using a D3DKMDT_VIDPN_PRESENT_PATH structure that you obtained by calling any of the following functions, you must release the structure by calling **pfnReleasePathInfo**.

* [pfnAcquireFirstPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirefirstpathinfo)
* [pfnAcquireNextPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirenextpathinfo)
* [pfnAcqirePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirepathinfo)

If you obtain a D3DKMDT_VIDPN_PRESENT_PATH structure by calling **pfnCreateNewPathInfo** and then pass that structure to **pfnAddPath**, you do not need to release the structure.

If you obtain a handle by calling **pfnCreateNewPathInfo** and then you decide not to add the new path to a topology, you must release the newly created structure by calling **pfnReleasePathInfo**.

The D3DKMDT_HVIDPNTOPOLOGY data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[pfnAcqirePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirepathinfo)

[pfnAcquireFirstPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirefirstpathinfo)

[pfnAcquireNextPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirenextpathinfo)
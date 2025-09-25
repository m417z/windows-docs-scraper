# _DXGK_VIDPNTOPOLOGY_INTERFACE structure

## Description

The DXGK_VIDPNTOPOLOGY_INTERFACE structure contains pointers to functions that belong to the VidPn Topology interface, which is implemented by the video present network (VidPN) manager. For more info, see [VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces).

## Members

### `pfnGetNumPaths`

A pointer to the [pfnGetNumPaths](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getnumpaths) function.

### `pfnGetNumPathsFromSource`

A pointer to the [pfnGetNumPathsFromSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getnumpathsfromsource) function.

### `pfnEnumPathTargetsFromSource`

A pointer to the [pfnEnumPathTargetsFromSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_enumpathtargetsfromsource) function.

### `pfnGetPathSourceFromTarget`

A pointer to the [pfnGetPathSourceFromTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_getpathsourcefromtarget) function.

### `pfnAcquirePathInfo`

A pointer to the [pfnAcquirePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirepathinfo) function.

### `pfnAcquireFirstPathInfo`

A pointer to the [pfnAcquireFirstPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirefirstpathinfo) function.

### `pfnAcquireNextPathInfo`

A pointer to the [pfnAcquireNextPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_acquirenextpathinfo) function.

### `pfnUpdatePathSupportInfo`

A pointer to the [pfnUpdatePathSupportInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_updatepathsupportinfo) function.

### `pfnReleasePathInfo`

A pointer to the [pfnReleasePathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_releasepathinfo) function.

### `pfnCreateNewPathInfo`

A pointer to the [pfnCreateNewPathInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_createnewpathinfo) function.

### `pfnAddPath`

A pointer to the [pfnAddPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_addpath) function.

### `pfnRemovePath`

A pointer to the [pfnRemovePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpntopology_removepath) function.

## Remarks

The display miniport driver calls the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function of the VidPn interface to obtain a handle to a VidPN topology object and a pointer to a DXGK_VIDPNTOPOLOGY_INTERFACE structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the VidPN topology object.
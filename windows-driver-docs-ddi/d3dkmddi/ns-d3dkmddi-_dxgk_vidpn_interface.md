# _DXGK_VIDPN_INTERFACE structure

## Description

The DXGK_VIDPN_INTERFACE structure contains pointers to functions that belong to the [VidPn interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/), which is implemented by the video present network (VidPN) manager.

## Members

### `Version`

A [DXGK_VIDPN_INTERFACE_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_vidpn_interface_version) enumerator that specifies the version of the interface.

### `pfnGetTopology`

A pointer to the [pfnGetTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_gettopology) function.

### `pfnAcquireSourceModeSet`

A pointer to the [pfnAcquireSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiresourcemodeset) function.

### `pfnReleaseSourceModeSet`

A pointer to the [pfnReleaseSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasesourcemodeset) function.

### `pfnCreateNewSourceModeSet`

A pointer to the [pfnCreateNewSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewsourcemodeset) function.

### `pfnAssignSourceModeSet`

A pointer to the [pfnAssignSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assignsourcemodeset) function.

### `pfnAssignMultisamplingMethodSet`

A pointer to the [pfnAssignMultisamplingMethodSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assignmultisamplingmethodset) function.

### `pfnAcquireTargetModeSet`

A pointer to the [pfnAcquireTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_acquiretargetmodeset) function.

### `pfnReleaseTargetModeSet`

A pointer to the [pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset) function.

### `pfnCreateNewTargetModeSet`

A pointer to the [pfnCreateNewTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewtargetmodeset) function.

### `pfnAssignTargetModeSet`

A pointer to the [pfnAssignTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assigntargetmodeset) function.

## Remarks

The display miniport driver calls [DxgkCbQueryVidPnInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryvidpninterface) to obtain a pointer to a DXGK_VIDPN_INTERFACE structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter a VidPN object.

For more information about the VidPN interface, see [VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces).
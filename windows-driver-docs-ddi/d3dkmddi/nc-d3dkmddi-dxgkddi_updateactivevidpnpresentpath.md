# DXGKDDI_UPDATEACTIVEVIDPNPRESENTPATH callback function

## Description

The *DxgkDdiUpdateActiveVidPnPresentPath* function updates one of the video present paths that is currently active on the display adapter.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pUpdateActiveVidPnPresentPath` [in]

A pointer to a [DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_updateactivevidpnpresentpath) structure, which contains one member: a [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure. The members of the D3DKMDT_VIDPN_PRESENT_PATH structure identify the path and supply new settings for the path. The *DxgkDdiUpdateActiveVidPnPresentPath* function must program the path on the display adapter according to the new settings.

## Return value

*DxgkDdiUpdateActiveVidPnPresentPath*returns one of the following values:

| Value | Description |
| --- | --- |
|STATUS_SUCCESS | The function succeeded.|
|STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY|The path specified by *pUpdateActiveVidPnPresentPathArg*->**VidPnPresentPathInfo** is not in the topology of the active VidPN.|
|STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED|The path does not support the content transformation specified by *pUpdateActiveVidPnPresentPathArg*->**VidPnPresentPathInfo.ContentTransformation**. The path does not support the gamma ramp specified by *pUpdateActiveVidPnPresentPathArg*->**VidPnPresentPathInfo.GammaRamp**.|

## Remarks

The operating system calls the *DxgkDdiUpdateActiveVidPnPresentPath* function to control the settings of video present paths, such as path rotation, a presented content's geometry transformations, gamma ramps that are used to adjust the presented content's brightness, and so on.

**Note** The display miniport driver's *DxgkDdiUpdateActiveVidPnPresentPath* function must support gamma ramps.

Beginning with Windows 8, if the display miniport driver sets the **SupportSmoothRotation** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure, it must support updating the path rotation on the adapter using the *DxgkDdiUpdateActiveVidPnPresentPath* function. The driver must always be able to set the path rotation during a call to the [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

The *DxgkDdiUpdateActiveVidPnPresentPath* function should be made pageable.

## See also

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_updateactivevidpnpresentpath)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn)
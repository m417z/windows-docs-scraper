# _DXGKARG_ISSUPPORTEDVIDPN structure

## Description

The DXGKARG_ISSUPPORTEDVIDPN structure contains arguments for the [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn) function. The *DxgkDdiIsSupportedVidPn* function determines whether a specified video present network (VidPN) is supported on a display adapter.

## Members

### `hDesiredVidPn`

A handle to the VidPN object in question.

### `IsVidPnSupported`

A Boolean variable that receives **TRUE** if the VidPN is supported and **FALSE** if the VidPN is not supported.

## See also

[DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn)
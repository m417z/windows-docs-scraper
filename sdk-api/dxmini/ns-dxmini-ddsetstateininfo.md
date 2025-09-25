# DDSETSTATEININFO structure

## Description

The DDSETSTATEININFO structure contains the surface and [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object information.

## Members

### `lpSurfaceData`

Points to a [DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata) structure that contains the surface information.

### `lpVideoPortData`

Points to a [DDVIDEOPORTDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddvideoportdata) structure that contains the VPE object information.

## See also

[DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata)

[DDVIDEOPORTDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddvideoportdata)

[DxSetState](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_setstate)
# DDFLIPVIDEOPORTINFO structure

## Description

The DDFLIPVIDEOPORTINFO structure contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object and surface information.

## Members

### `lpVideoPortData`

Points to a [DDVIDEOPORTDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddvideoportdata) structure that contains the VPE object information.

### `lpCurrentSurface`

Points to a [DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata) structure that contains information about the current surface.

### `lpTargetSurface`

Points to a DDSURFACEDATA structure that contains information about the target surface.

### `dwFlipVPFlags`

Indicates whether the surfaces represent [vertical blanking interval (VBI)](https://learn.microsoft.com/windows-hardware/drivers/) surfaces or regular surfaces. One of the following:

| Flag | Meaning |
| --- | --- |
| DDVPFLIP_VBI | Flip the VBI surface. |
| DDVPFLIP_VIDEO | Flip the normal video surface. |

## See also

[DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata)

[DDVIDEOPORTDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddvideoportdata)

[DxFlipVideoPort](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipvideoport)
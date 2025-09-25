# DDFLIPOVERLAYINFO structure

## Description

The DDFLIPOVERLAYINFO structure contains the flip information for the surface.

## Members

### `lpCurrentSurface`

Points to a [DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata) structure that contains information about the current surface.

### `lpTargetSurface`

Points to a DDSURFACEDATA structure that contains information about the target surface.

### `dwFlags`

Specifies the polarity of the data in the field being flipped. One of the following flags is returned:

| Flag | Meaning |
| --- | --- |
| DDFLIP_EVEN | The target surface contains the even field of video data. |
| DDFLIP_ODD | The target surface contains the odd field of video data. |

## See also

[DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata)

[DxFlipOverlay](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipoverlay)
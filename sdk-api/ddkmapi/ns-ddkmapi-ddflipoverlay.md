# DDFLIPOVERLAY structure

## Description

The DDFLIPOVERLAY structure contains the surface information required for the flip.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw handle.

### `hCurrentSurface`

Specifies the current DirectDrawSurface handle.

### `hTargetSurface`

Handle of the DirectDrawSurface to which the flip occurs.

### `dwFlags`

Flags specifying flip options.

| Flag | Meaning |
| --- | --- |
| DDFLIP_EVEN | For use only when displaying video in an overlay surface. The new surface contains data from the even field of a video signal. This flag cannot be used with the DDFLIP_ODD flag. |
| DDFLIP_ODD | For use only when displaying video in an overlay surface. The new surface contains data from the odd field of a video signal. This flag cannot be used with the DDFLIP_EVEN flag. |

## See also

[DD_DXAPI_FLIP_OVERLAY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550612(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)
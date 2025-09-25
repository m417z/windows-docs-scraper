# DDFLIPVIDEOPORT structure

## Description

The DDFLIPVIDEOPORT structure contains the information required to flip the hardware video port.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw handle.

### `hVideoPort`

Specifies the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object handle.

### `hCurrentSurface`

Specifies the current DirectDrawSurface handle.

### `hTargetSurface`

Specifies the handle of the DirectDrawSurface to which the flip occurs.

### `dwFlags`

Indicates whether the surfaces represent [VBI](https://learn.microsoft.com/windows-hardware/drivers/) surfaces or regular surfaces. One of the following:

| Flag | Meaning |
| --- | --- |
| DDVPFLIP_VBI | Flips the VBI surface. |
| DDVPFLIP_VIDEO | Flips the normal video surface. |

## See also

[DD_DXAPI_FLIP_VP](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550618(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)
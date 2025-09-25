# DD_SETCOLORKEYDATA structure

## Description

The DD_SETCOLORKEYDATA structure contains information necessary to set the color key value for the specified surface.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface with which the color key is to be associated.

### `dwFlags`

Specifies which color key is being requested. This member is a bitwise OR of any of the following values:

| Value | Meaning |
| --- | --- |
| DDCKEY_COLORSPACE | The DDCOLORKEY structure contains a color space. If this bit is not set, the structure contains a single color key. |
| DDCKEY_DESTBLT | The DDCOLORKEY structure specifies a color key or color space to be used as a destination color key for blt operations. |
| DDCKEY_DESTOVERLAY | The DDCOLORKEY structure specifies a color key or color space to be used as a destination color key for overlay operations. |
| DDCKEY_SRCBLT | The DDCOLORKEY structure specifies a color key or color space to be used as a source color key for blit operations. |
| DDCKEY_SRCOVERLAY | The DDCOLORKEY structure specifies a color key or color space to be used as a source color key for overlay operations |

### `ckNew`

Specifies a DDCOLORKEY structure that specifies the new color key values for the DirectDrawSurface object. For more information about DDCOLORKEY, see the latest Microsoft DirectX SDK documentation.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSetColorKey](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setcolorkey) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `SetColorKey`

This is not used on Microsoft Windows 2000 and later.

## See also

[DdSetColorKey](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setcolorkey)
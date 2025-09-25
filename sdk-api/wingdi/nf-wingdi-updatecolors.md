# UpdateColors function

## Description

The **UpdateColors** function updates the client area of the specified device context by remapping the current colors in the client area to the currently realized logical palette.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

An inactive window with a realized logical palette may call **UpdateColors** as an alternative to redrawing its client area when the system palette changes.

The **UpdateColors** function typically updates a client area faster than redrawing the area. However, because **UpdateColors** performs the color translation based on the color of each pixel before the system palette changed, each call to this function results in the loss of some color accuracy.

This function must be called soon after a [WM_PALETTECHANGED](https://learn.microsoft.com/windows/desktop/gdi/wm-palettechanged) message is received.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)
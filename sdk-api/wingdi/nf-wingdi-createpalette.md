# CreatePalette function

## Description

The **CreatePalette** function creates a logical palette.

## Parameters

### `plpal` [in]

A pointer to a [LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette) structure that contains information about the colors in the logical palette.

## Return value

If the function succeeds, the return value is a handle to a logical palette.

If the function fails, the return value is **NULL**.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

Once an application creates a logical palette, it can select that palette into a device context by calling the [SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette) function. A palette selected into a device context can be realized by calling the [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) function.

When you no longer need the palette, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette)

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)

[SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette)
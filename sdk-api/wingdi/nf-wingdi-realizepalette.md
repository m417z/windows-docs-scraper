# RealizePalette function

## Description

The **RealizePalette** function maps palette entries from the current logical palette to the system palette.

## Parameters

### `hdc` [in]

A handle to the device context into which a logical palette has been selected.

## Return value

If the function succeeds, the return value is the number of entries in the logical palette mapped to the system palette.

If the function fails, the return value is GDI_ERROR.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

The **RealizePalette** function modifies the palette for the device associated with the specified device context. If the device context is a memory DC, the color table for the bitmap selected into the DC is modified. If the device context is a display DC, the physical palette for that device is modified.

A logical palette is a buffer between color-intensive applications and the system, allowing these applications to use as many colors as needed without interfering with colors displayed by other windows.

When an application's window has the focus and it calls the **RealizePalette** function, the system attempts to realize as many of the requested colors as possible. The same is also true for applications with inactive windows.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette)
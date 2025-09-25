# SelectPalette function

## Description

The **SelectPalette** function selects the specified logical palette into a device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hPal` [in]

A handle to the logical palette to be selected.

### `bForceBkgd` [in]

Specifies whether the logical palette is forced to be a background palette. If this value is **TRUE**, the [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) function causes the logical palette to be mapped to the colors already in the physical palette in the best possible way. This is always done, even if the window for which the palette is realized belongs to a thread without active focus.

If this value is **FALSE**, [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) causes the logical palette to be copied into the device palette when the application is in the foreground. (If the *hdc* parameter is a memory device context, this parameter is ignored.)

## Return value

If the function succeeds, the return value is a handle to the device context's previous logical palette.

If the function fails, the return value is **NULL**.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

An application can select a logical palette into more than one device context only if device contexts are compatible. Otherwise **SelectPalette** fails. To create a device context that is compatible with another device context, call [CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc) with the first device context as the parameter. If a logical palette is selected into more than one device context, changes to the logical palette will affect all device contexts for which it is selected.

An application might call the **SelectPalette** function with the *bForceBackground* parameter set to **TRUE** if the child windows of a top-level window each realize their own palettes. However, only the child window that needs to realize its palette must set *bForceBackground* to **TRUE**; other child windows must set this value to **FALSE**.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc)

[CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)
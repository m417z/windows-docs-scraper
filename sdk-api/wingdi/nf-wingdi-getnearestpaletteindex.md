# GetNearestPaletteIndex function

## Description

The **GetNearestPaletteIndex** function retrieves the index for the entry in the specified logical palette most closely matching a specified color value.

## Parameters

### `h` [in]

A handle to a logical palette.

### `color` [in]

A color to be matched. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value is the index of an entry in a logical palette.

If the function fails, the return value is CLR_INVALID.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

If the given logical palette contains entries with the PC_EXPLICIT flag set, the return value is undefined.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetNearestColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getnearestcolor)

[GetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpaletteentries)

[GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)
# AnimatePalette function

## Description

The **AnimatePalette** function replaces entries in the specified logical palette.

## Parameters

### `hPal` [in]

A handle to the logical palette.

### `iStartIndex` [in]

The first logical palette entry to be replaced.

### `cEntries` [in]

The number of entries to be replaced.

### `ppe` [in]

A pointer to the first member in an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures used to replace the current entries.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

The **AnimatePalette** function only changes entries with the PC_RESERVED flag set in the corresponding **palPalEntry** member of the [LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette) structure.

If the given palette is associated with the active window, the colors in the palette are replaced immediately.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))
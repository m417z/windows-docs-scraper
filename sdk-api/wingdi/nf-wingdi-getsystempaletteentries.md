# GetSystemPaletteEntries function

## Description

The **GetSystemPaletteEntries** function retrieves a range of palette entries from the system palette that is associated with the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the device context.

### `iStart` [in]

The first entry to be retrieved from the system palette.

### `cEntries` [in]

The number of entries to be retrieved from the system palette.

### `pPalEntries` [out]

A pointer to an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures to receive the palette entries. The array must contain at least as many structures as specified by the *cEntries* parameter. If this parameter is **NULL**, the function returns the total number of entries in the palette.

## Return value

If the function succeeds, the return value is the number of entries retrieved from the palette.

If the function fails, the return value is zero.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpaletteentries)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))
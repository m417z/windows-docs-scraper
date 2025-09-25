# GetPaletteEntries function

## Description

The **GetPaletteEntries** function retrieves a specified range of palette entries from the given logical palette.

## Parameters

### `hpal` [in]

A handle to the logical palette.

### `iStart` [in]

The first entry in the logical palette to be retrieved.

### `cEntries` [in]

The number of entries in the logical palette to be retrieved.

### `pPalEntries` [out]

A pointer to an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures to receive the palette entries. The array must contain at least as many structures as specified by the *nEntries* parameter.

## Return value

If the function succeeds and the handle to the logical palette is a valid pointer (not **NULL**), the return value is the number of entries retrieved from the logical palette. If the function succeeds and handle to the logical palette is **NULL**, the return value is the number of entries in the given palette.

If the function fails, the return value is zero.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

If the *nEntries* parameter specifies more entries than exist in the palette, the remaining members of the [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structure are not altered.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetSystemPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteentries)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))

[SetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpaletteentries)
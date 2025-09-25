## Description

Generates a matching font set based on the requested inputs, ordered so that nearer matches are earlier.

## Parameters

### `familyName`

Type: \_In\_z\_ **[WCHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) const\***

Font family name. This can be: a typographic family name, weight/stretch/style family name, GDI (RBIZ) family name, or full name.

### `fontAxisValues`

Type: \_In\_reads\_(fontAxisValueCount) **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const\***

Array of font axis values.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of font axis values.

### `allowedSimulations`

Type: **[DWRITE_FONT_SIMULATIONS](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations)**

Specifies which simulations (that is, algorithmic emboldening and/or slant) may be applied to matching fonts to better match the specified axis values. If the argument is **DWRITE_FONT_SIMULATIONS_NONE** (0), then no simulations are applied.

### `matchingFonts`

Type: \_COM\_Outptr\_ **[IDWriteFontSet4](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontset4)\*\***

Receives a pointer to a newly-created font set, which contains a prioritized list of fonts that match the specified inputs.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, then it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

This can yield distinct items that were not in the original font set, including items with simulation flags (if they would be a closer match to the request) and instances that were not named by the font author. Items from the same font resources are collapsed into one: the closest possible match.

## See also
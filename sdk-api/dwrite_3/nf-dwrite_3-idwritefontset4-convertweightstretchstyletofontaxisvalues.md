## Description

Computes derived font axis values from the specified font weight, stretch, style, and size.

## Parameters

### `inputAxisValues`

Type: \_In\_reads\_opt\_(inputAxisCount) **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value) const\***

Optional pointer to an array of input axis values. Axes present in this array are excluded from the output. That's so that explicit axis values take precedence over derived axis values.

### `inputAxisCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the array of input axis values.

### `fontWeight`

Type: **[DWRITE_FONT_WEIGHT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_weight)**

Font weight, used to compute "wght" axis value.

### `fontStretch`

Type: **[DWRITE_FONT_STRETCH](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_stretch)**

Font stretch, used to compute "wdth" axis value.

### `fontStyle`

Type: **[DWRITE_FONT_STYLE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_style)**

Font style, used to compute "slnt" and "ital" axis values.

### `fontSize`

Type: **float**

Font size in DIPs, used to compute "opsz" axis value. If this parameter is zero, then no "opsz" axis value is added to the output array.

### `outputAxisValues`

Type: \_Out\_writes\_to\_(DWRITE_STANDARD_FONT_AXIS_COUNT, return) **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value)\***

Pointer to an output array to which derived axis values are written. The size of this array must be at least **DWRITE_STANDARD_FONT_AXIS_COUNT** (5). The return value is the number of axis values that were actually written to this array.

## Return value

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Returns the number of derived axis values that were actually written to the output array.

## Remarks

The caller should concatenate the output axis values to the input axis values (if any), and pass the combined axis values to the **GetMatchingFonts** method. This doesn't result in duplicates because the output doesn't include any axes present in the *inputAxisValues* array.

## See also
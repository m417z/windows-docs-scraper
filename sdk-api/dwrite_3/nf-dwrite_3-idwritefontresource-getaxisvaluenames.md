## Description

Retrieves the localized names of specific values for a font axis.

## Parameters

### `axisIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Font axis, from 0 to [GetFontAxisCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontresource-getfontaxiscount) minus 1.

### `axisValueIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Value index, from 0 to [GetAxisValueNameCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontresource-getaxisvaluenamecount) minus 1.

### `fontAxisRange` [out]

Type: **[DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range)\***

Range of the named value.

### `names` [out]

Type: **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)\*\***

The address of a pointer to an [IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings) interface. On successful completion, the function sets the pointer to a newly created localized strings object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

The font author may not have supplied names for some font axis values. The localized strings will be empty in that case. The range may be a single point, where *minValue* == *maxValue*. All ranges are in ascending order by *axisValueIndex*.

## See also
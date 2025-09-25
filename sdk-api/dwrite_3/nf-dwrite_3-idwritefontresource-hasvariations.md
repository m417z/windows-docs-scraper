## Description

Determines whether this font face's resource supports any variable axes. When `true`, at least one [DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range) in the font resource has a non-empty range (*maxValue* > *minValue*).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`true` if the font face's resource supports any variable axes. Otherwise, `false`.

## Remarks

## See also

[DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range)
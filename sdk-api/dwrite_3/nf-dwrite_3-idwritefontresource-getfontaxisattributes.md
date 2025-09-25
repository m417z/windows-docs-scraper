## Description

Retrieves attributes describing the given axis, such as whether the font author recommends to hide the axis in user interfaces.

## Parameters

### `axisIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Font axis, from 0 to [GetFontAxisCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontresource-getfontaxiscount) minus 1.

## Return value

Type: **[DWRITE_FONT_AXIS_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_axis_attributes)**

The attributes for the given axis, or **DWRITE_FONT_AXIS_ATTRIBUTES_NONE** if *axisIndex* is beyond the font count.

## Remarks

## See also
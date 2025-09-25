# ID2D1StrokeStyle::GetDashStyle

## Description

Gets a value that describes the stroke's dash pattern.

## Return value

Type: **[D2D1_DASH_STYLE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_dash_style)**

A value that describes the predefined dash pattern used, or [D2D1_DASH_STYLE_CUSTOM](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_dash_style) if a custom dash style is used.

## Remarks

If a custom dash style is specified, the dash pattern is described by the dashes array, which can be retrieved by calling the [GetDashes](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1strokestyle-getdashes) method.

## See also

[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)
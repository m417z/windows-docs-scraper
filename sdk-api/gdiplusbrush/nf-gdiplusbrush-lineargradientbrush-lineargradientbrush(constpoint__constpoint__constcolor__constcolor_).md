## Description

Creates a **LinearGradientBrush::LinearGradientBrush** object from a set of boundary points and boundary colors.

## Parameters

### `point1` [in, ref]

Type: **const [Point](https://learn.microsoft.com/windows/win32/api/gdiplustypes/nl-gdiplustypes-point)**

Reference to a **Point** object that specifies the starting point of the gradient. The starting boundary line passes through the starting point.

### `point2` [in, ref]

Type: **const [Point](https://learn.microsoft.com/windows/win32/api/gdiplustypes/nl-gdiplustypes-point)**

Reference to a **Point** object that specifies the ending point of the gradient. The ending boundary line passes through the ending point.

### `color1` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/win32/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/win32/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the starting boundary line of this linear gradient brush.

### `color2` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/win32/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/win32/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the ending boundary line of this linear gradient brush.

## Remarks

The "directional line," an imaginary straight line, is defined by the starting point, *point1*, and the ending point, *point2*. The starting boundary of the gradient is a straight line that is perpendicular to the directional line and that passes through the starting point. The ending boundary of the gradient is a straight line that is parallel to the starting boundary line and that passes through the ending point. The gradient color is constant along lines that are parallel to the boundary lines. The gradient gradually changes from the starting color to the ending color along the directional line.

## See also

[Color](https://learn.microsoft.com/windows/win32/api/gdipluscolor/nl-gdipluscolor-color)

[Point](https://learn.microsoft.com/windows/win32/api/gdiplustypes/nl-gdiplustypes-point)

[LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)
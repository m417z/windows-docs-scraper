## Description

Creates a **LinearGradientBrush::LinearGradientBrush** object from a set of boundary points and boundary colors.

## Parameters

### `point1` [in, ref]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

Reference to a [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) object that specifies the starting point of the gradient. The starting boundary line passes through the starting point.

### `point2` [in, ref]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

Reference to a [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) object that specifies the ending point of the gradient. The ending boundary line passes through the ending point.

### `color1` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the starting boundary line of this linear gradient brush.

### `color2` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the ending boundary line of this linear gradient brush.

## Remarks

The "directional line," an imaginary straight line, is defined by the starting point, *point1*, and the ending point, *point2*. The starting boundary of the gradient is a straight line that is perpendicular to the directional line and that passes through the starting point. The ending boundary of the gradient is a straight line that is parallel to the starting boundary line and that passes through the ending point. The gradient color is constant along lines that are parallel to the boundary lines. The gradient gradually changes from the starting color to the ending color along the directional line.

## Examples

The following example creates a linear gradient brush from a set of boundary points and boundary colors. The code then uses the brush to paint the interior of a rectangle.

```cpp
VOID Example_Construct02(HDC hdc)
{
   Graphics myGraphics(hdc);

   LinearGradientBrush linGrBrush(
      PointF(0.8f, 1.6f),
      PointF(3.0f, 2.4f),
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255));  // blue

   myGraphics.SetPageUnit(UnitInch);
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 4, 3);
}
```

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)
# LinearGradientBrush::SetBlendBellShape

## Description

The **LinearGradientBrush::SetBlendBellShape** method sets the blend shape of this linear gradient brush to create a custom blend based on a bell-shaped curve.

## Parameters

### `focus` [in]

Type: **REAL**

Real number that specifies the position of the ending color. This number is a percentage of the distance between the boundary lines and must be in the range from 0.0 through 1.0.

### `scale` [in]

Type: **REAL**

Optional. Real number that specifies the percentage of the gradient's ending color that gets blended, at the focus position, with the gradient's starting color. This number must be in the range from 0.0 through 1.0. The default value is 1.0, which specifies that the ending color is at full intensity.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

By default, the color changes gradually from the starting color (color at the starting boundary of the linear gradient brush) to the ending color (color at the ending boundary of the linear gradient brush) as you move from the starting boundary to the ending boundary. You can customize the positioning and blending of the starting and ending colors by using the **LinearGradientBrush::SetBlendBellShape** method.

The **LinearGradientBrush::SetBlendBellShape** method customizes the blend so that it follows a bell-shaped curve with the extremes of the bell's base at the gradient's boundaries. The starting color, which, in a default blend, is at the starting boundary of a linear gradient brush, appears at the starting and ending boundaries of the linear gradient brush when a bell-shaped blend is applied. The position of the ending color, which, in a default blend, is at the ending boundary, is somewhere between the boundaries and is determined by the value of the focus. In other words, the focus specifies the position of the peak of the bell. For example, a focus value of 0.7 places the peak at 70 percent of the distance between the starting and ending boundaries. The ending color appears at this peak.

The ending color in a bell-shaped blend is a percentage of the gamut between the gradient's default-blend starting color and default-blend ending color. For example, suppose a linear gradient brush is constructed with red as the starting color and blue as the ending color. If **LinearGradientBrush::SetBlendBellShape** is called with a scale value of 0.8, the ending color in the bell shaped blend is a hue that is 80 percent between red and blue (20 percent red, 80 percent blue). A scale value of 1.0 produces an ending color that is 100 percent blue.

#### Examples

The following example creates a linear gradient brush, sets a bell-shaped blend, and uses the brush to fill a rectangle. Twice more, the code sets a bell-shaped blend with different values and, each time, uses the brush to fill a rectangle.

```cpp
VOID Example_SetBlendBell(HDC hdc)
{
   Graphics myGraphics(hdc);

   LinearGradientBrush linGrBrush(
      Point(0, 0),
      Point(500, 0),
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255));  // blue

   linGrBrush.SetBlendBellShape(0.5f, 0.6f);
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 500, 50);

   linGrBrush.SetBlendBellShape(0.5f, 0.8f);
   myGraphics.FillRectangle(&linGrBrush, 0, 75, 500, 50);

   linGrBrush.SetBlendBellShape(0.5f, 1.0f);
   myGraphics.FillRectangle(&linGrBrush, 0, 150, 500, 50);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetBlend](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getblend)

[LinearGradientBrush::SetBlend](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setblend)

[LinearGradientBrush::SetBlendTriangularShape](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-setblendtriangularshape)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)
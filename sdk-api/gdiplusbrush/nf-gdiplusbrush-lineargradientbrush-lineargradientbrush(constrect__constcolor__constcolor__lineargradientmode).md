# LinearGradientBrush::LinearGradientBrush(IN const Rect &,IN const Color &,IN const Color &,IN LinearGradientMode)

## Description

Creates a **LinearGradientBrush::LinearGradientBrush** object based on a rectangle and mode of direction.

## Parameters

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that specifies the starting and ending points of the gradient. The direction of the gradient, specified by *mode*, affects how these points are defined. The dimensions of the rectangle affect the direction of the gradient for forward diagonal mode and backward diagonal mode.

### `color1` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the starting boundary line of this linear gradient brush.

### `color2` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the ending boundary line of this linear gradient brush.

### `mode` [in]

Type: **[LinearGradientMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-lineargradientmode)**

Element of the [LinearGradientMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-lineargradientmode) enumeration that specifies the direction of the gradient.

## Remarks

The starting boundary of the gradient is a straight line that either passes through the starting point or borders the rectangle *rect*. The ending boundary of the gradient is a straight line that is parallel to the starting boundary line and that either passes through the ending point or borders the rectangle. The "directional line," an imaginary straight line, is perpendicular to the boundary lines. The gradient color is constant along lines that are parallel to the boundary lines. The gradient gradually changes from the starting color to the ending color along the directional line.

The mode affects the boundaries of the gradient:

* Vertical mode
  The boundary lines are parallel to the top (and bottom) of the rectangle *rect*. The starting and ending boundary lines are the top and bottom, respectively, of the rectangle *rect*.
* Horizontal mode
  The boundary lines are parallel to the left (and right) of the rectangle
  *rect*. The starting and ending boundary lines are the left and right, respectively, of the rectangle *rect*.
* Forward diagonal mode
  The boundary lines are parallel to the diagonal line that is defined by the upper-right corner and lower-left corner of the rectangle *rect*. The starting boundary line passes through the starting point (upper-left corner of the rectangle *rect*). The ending boundary line passes through the ending point (lower-right corner of the rectangle *rect*). Note that starting and ending points are opposites of the starting and ending points for backward diagonal mode.
* Backward diagonal mode
  The boundary lines are parallel to the diagonal line that is defined by the upper-left corner and lower-right corner of the rectangle *rect*. The starting boundary line passes through the starting point (upper-right corner of the rectangle *rect*). The ending boundary line passes through the ending point (lower-left corner of the rectangle *rect*). Note that starting and ending points are opposites of the starting and ending points for forward diagonal mode.

#### Examples

The following example creates a linear gradient brush using LinearGradientModeVertical for the mode setting.

```cpp
VOID Example_Construct04(HDC hdc)
{
   Graphics myGraphics(hdc);

   LinearGradientBrush linGrBrush(
      Rect(20, 10, 200, 100),
      Color(255, 255, 0, 0),   // red
      Color(255, 0, 0, 255),   // blue
      LinearGradientModeVertical);
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 300, 300);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-lineargradientmode)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)
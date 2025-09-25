# LinearGradientBrush::GetRectangle(OUT Rect)

## Description

The **LinearGradientBrush::GetRectangle** method gets the rectangle that defines the boundaries of the gradient.

## Parameters

### `rect` [out]

Type: **[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)***

Pointer to a [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object that receives the rectangle that defines the boundaries of the gradient. For example, if a linear gradient brush is constructed with a starting point at (20, 50) and an ending point at (60, 110), then the defining rectangle has its upper-left point at (20, 50), a width of 40, and a height of 60.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The rectangle defines the boundaries of the gradient in the following ways: The right and left sides of the rectangle form the boundaries of a horizontal gradient. The top and bottom sides form the boundaries of a vertical gradient. Two of the diagonally opposing corners lie on the boundaries of a diagonal gradient. In each of these cases, either side/corner may be on the starting boundary, depending on how the starting and ending points are passed to the constructor.

#### Examples

The following example creates a linear gradient brush. Then the code gets the brush's rectangle and draws it.

```cpp
VOID Example_GetRect(HDC hdc)
{
   Graphics myGraphics(hdc);

   // Create a linear gradient brush.
   LinearGradientBrush linGrBrush(
      Point(20, 10),
      Point(60, 110),
      Color(255, 0, 0, 0),     // black
      Color(255, 0, 0, 255));  // blue

   // Obtain information about the linear gradient brush.
   Rect rect;
   linGrBrush.GetRectangle(&rect);

   // Draw the retrieved rectangle.
   Pen myPen(Color(255, 0, 0, 0));
   myGraphics.DrawRectangle(&myPen, rect);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)
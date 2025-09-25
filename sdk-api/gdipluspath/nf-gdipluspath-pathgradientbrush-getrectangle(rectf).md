# PathGradientBrush::GetRectangle

## Description

The **PathGradientBrush::GetRectangle** method gets the smallest rectangle that encloses the boundary path of this path gradient brush.

## Parameters

### `rect`

Pointer to a **RectF** object that receives the bounding rectangle.

## Return value

**Type:** [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a [PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a polygon that is defined by four points.
The code calls the **PathGradientBrush::GetRectangle** method of the PathGradientBrush object to obtain the smallest rectangle that encloses the brush's boundary path.
The code calls the **Graphics::FillRectangle** method of a Graphics object, passing the address of the **PathGradientBrush** object and a reference to the brush's bounding rectangle.
That call fills only the portion of the bounding rectangle that is inside the brush's boundary path.
Finally the code draws the outline of the bounding rectangle.

```cpp
VOID Example_GetRect(HDC hdc)
{
   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 0));

   // Create a path gradient brush based on an array of points.
   Point points[] = {
      Point(30, 20),
      Point(150, 40),
      Point(100, 100),
      Point(60, 200) };

   PathGradientBrush pthGrBrush(points, 4);

   // Obtain information about the path gradient brush.
   RectF rect;
   pthGrBrush.GetRectangle(&rect);

   graphics.FillRectangle(&pthGrBrush, rect);
   graphics.DrawRectangle(&pen, rect);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)
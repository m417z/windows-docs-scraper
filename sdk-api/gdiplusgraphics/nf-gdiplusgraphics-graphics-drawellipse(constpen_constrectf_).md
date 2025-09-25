# DrawEllipse(Pen*,RectF&)

## Description

The **Graphics::DrawEllipse** method draws an ellipse.

## Parameters

### `pen`

Pointer to a pen that is used to draw the ellipse.

### `rect`

Reference to a rectangle that bounds the ellipse.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example draws an ellipse.

```cpp
VOID Example_DrawEllipse2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen bluePen(Color(255, 0, 0, 255));

   // Create a Rect object that bounds the ellipse.
   RectF ellipseRect(0.0f, 0.0f, 200.0f, 100.0f);

   // Draw the ellipse.
   graphics.DrawEllipse(&bluePen, ellipseRect);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[FillEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillellipse(inconstbrush_inconstrect_))

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Ellipses and Arcs](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-ellipses-and-arcs-about)
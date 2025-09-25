# GraphicsPath::IsOutlineVisible

## Description

The **GraphicsPath::IsOutlineVisible** method determines whether a specified point touches the outline of this path when the path is drawn by a specified [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and a specified pen.

## Parameters

### `point`

Reference to the point to be tested.

### `pen`

Pointer to a **Pen** object.
This method determines whether the test point touches the path outline that would be drawn by this pen.
More points will touch an outline drawn by a wide pen than will touch an outline drawn by a narrow pen.

### `g`

Optional.
Pointer to a **Graphics** object that specifies a world-to-device transformation.
If the value of this parameter is **NULL**, the test is done in world coordinates; otherwise, the test is done in device coordinates.
The default value is **NULL**.

## Return value

If the test point touches the outline of this path, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

#### Examples

The following example creates an elliptical path and draws that path with a wide yellow pen.
Then the code tests each point in an array to see whether the point touches the outline (as it would be drawn by the wide yellow pen) of the path.
Points that touch the outline are painted green, and points that don't touch the outline are painted red.

```cpp
VOID Example_IsOutlineVisibleExample(HDC hdc)
{
   Graphics graphics(hdc);

   INT j;
   Pen yellowPen(Color(255, 255, 255, 0), 20);
   SolidBrush brush(Color(255, 255, 0,  0));

   // Create and draw a path.
   GraphicsPath path;
   path.AddEllipse(50, 50, 200, 100);
   graphics.DrawPath(&yellowPen, &path);

   // Create an array of three points, and determine whether each
   // point in the array touches the outline of the path.
   // If a point touches the outline, paint it green.
   // If a point does not touch the outline, paint it red.
   PointF[] = {
      PointF(230, 138),
      PointF(100, 120),
      PointF(150, 170)};

   for(j = 0; j <= 2; ++j)
   {
      if(path.IsOutlineVisible(points[j], &yellowPen, NULL))
         brush.SetColor(Color(255, 0, 255,  0));
      else
         brush.SetColor(Color(255, 255, 0,  0));

      graphics.FillEllipse(&brush, points[j].X - 3.0f, points[j].Y - 3.0f, 6.0f, 6.0f);
   }
}

Color(255, 255, 0,  0)Color(255, 255, 0,  0)
```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[IsOutlineVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-isoutlinevisible(inconstpoint__inconstpen_inconstgraphics))

[IsVisible Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-isvisible(inconstpoint__inconstgraphics))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[Setting Pen Width and Alignment](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-setting-pen-width-and-alignment-use)
# GraphicsPath::IsVisible

## Description

The **GraphicsPath::IsVisible** method determines whether a specified point lies in the area that is filled when this path is filled by a specified [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `point`

Reference to the point to be tested.

### `g`

Optional.
Pointer to a **Graphics** object that specifies a world-to-device transformation.
If the value of this parameter is **NULL**, the test is done in world coordinates; otherwise, the test is done in device coordinates.
The default value is **NULL**.

## Return value

If the test point lies in the interior of this path, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

#### Examples

The following example creates an elliptical path and draws that path with a narrow black pen.
Then the code tests each point in an array to see whether the point lies in the interior of the path.
Points that lie in the interior are painted green, and points that do not lie in the interior are painted red.

```cpp
VOID IsVisibleExample(HDC hdc)
{
   Graphics graphics(hdc);

   INT j;
   Pen blackPen(Color(255, 0, 0, 0), 1);
   SolidBrush brush(Color(255, 255, 0,  0));

   // Create and draw a path.
   GraphicsPath path;
   path.AddEllipse(50, 50, 200, 100);
   graphics.DrawPath(&blackPen, &path);

   // Create an array of four points, and determine whether each
   // point in the array touches the outline of the path.
   // If a point touches the outline, paint it green.
   // If a point does not touch the outline, paint it red.
   PointF[] = {
      PointF(50, 100),
      PointF(250, 100),
      PointF(150, 170),
      PointF(180, 60)};

   for(j = 0; j <= 3; ++j)
   {
      if(path.IsVisible(points[j], &graphics))
         brush.SetColor(Color(255, 0, 255,  0));
      else
         brush.SetColor(Color(255, 255, 0,  0));

      graphics.FillEllipse(&brush, points[j].X - 3.0f, points[j].Y - 3.0f, 6.0f, 6.0f);
   }
}
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

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)
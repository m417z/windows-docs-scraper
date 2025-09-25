# Region::IsVisible(IN const Rect &,IN const Graphics)

## Description

The **Region::IsVisible** method determines whether a rectangle intersects this region.

## Parameters

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle to test.

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Optional. Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains the world and page transformations required to calculate the device coordinates of this region and the rectangle. The default value is **NULL**.

## Return value

Type: **BOOL**

If the rectangle intersects this region, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

**Note** A region contains its border.

#### Examples

The following example creates a region from a path and then tests to determine whether a rectangle intersects the region.

```cpp
VOID Example_IsVisibleRect(HDC hdc)
{
   Graphics graphics(hdc);

   Point points[] = {
      Point(110, 20),
      Point(120, 30),
      Point(100, 60),
      Point(120, 70),
      Point(150, 60),
      Point(140, 10)};

   GraphicsPath path;
   SolidBrush solidBrush(Color(255, 255, 0, 0));

   path.AddClosedCurve(points, 6);

   // Create a region from a path.
   Region pathRegion(&path);
   graphics.FillRegion(&solidBrush, &pathRegion);

   // Check to see whether a rectangle intersects the region.
   Rect testRect(65, 25, 70, 30);

   if(pathRegion.IsVisible(testRect, &graphics))
   {
      // All or part of the rectangle is in the region.
   }

   // Draw the test rectangle.
   Pen pen(Color(255, 0, 0, 0));
   graphics.DrawRectangle(&pen, testRect);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)
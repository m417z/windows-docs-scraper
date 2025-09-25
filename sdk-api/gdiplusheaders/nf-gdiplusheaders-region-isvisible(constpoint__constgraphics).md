# Region::IsVisible(IN const Point &,IN const Graphics)

## Description

The **Region::IsVisible** method determines whether a point is inside this region.

## Parameters

### `point` [in, ref]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)**

Reference to a point to test.

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Optional. Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains the world and page transformations required to calculate the device coordinates of this region and the point. The default value is **NULL**.

## Return value

Type: **BOOL**

If the point is inside this region, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

**Note** A region contains its border.

#### Examples

The following example creates a region from a path and then tests to determine whether a point is in the region.

```cpp
VOID Example_IsVisiblePoint(HDC hdc)
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

   // Check to see whether a point is in the region.
   Point testPoint(125, 30);

   if(pathRegion.IsVisible(testPoint, &graphics))
   {
      // The test point is in the region.
   }

   // Fill a small circle centered at the test point.
   SolidBrush brush(Color(255, 0, 0, 0));
   graphics.FillEllipse(&brush, testPoint.X - 4, testPoint.Y - 4, 8, 8);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
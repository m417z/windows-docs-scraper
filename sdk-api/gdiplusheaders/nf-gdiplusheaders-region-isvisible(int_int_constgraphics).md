# Region::IsVisible(INT,INT,Graphics*)

## Description

The **Region::IsVisible** method determines whether a point is inside this region.

## Parameters

### `x`

Integer that specifies the x-coordinate of the point to test.

### `y`

Integer that specifies the y-coordinate of the point to test.

### `g`

Optional.
Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains the world and page transformations required to calculate the device coordinates of this region and the point.
The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a region from a path and then tests to determine whether a point is inside the region.

```cpp
VOID Example_IsVisibleXY(HDC hdc)
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

   // Check to see whether the point (125, 40) is in the region.
   INT x = 125;
   INT y = 40;
   if(pathRegion.IsVisible(x, y, &graphics))
   {

      // The point is in the region.
   }

   // Fill a small circle centered at the point (125, 40).
   SolidBrush brush(Color(255, 0, 0, 0));
   graphics.FillEllipse(&brush, x - 4, y - 4, 8, 8);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
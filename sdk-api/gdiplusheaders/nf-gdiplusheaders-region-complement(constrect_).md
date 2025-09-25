# Region::Complement(Rect&)

## Description

The **Region::Complement** method updates this region to the portion of the specified rectangle's interior that does not intersect this region.

## Parameters

### `rect`

Reference to a rectangle to use to update this [Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a region from a path and then uses a rectangle to update the region.

```cpp
VOID Example_ComplementRect(HDC hdc)
{
   Graphics graphics(hdc);

   SolidBrush solidBrush(Color(255, 255, 0, 0));

   Point points[] = {
      Point(110, 20),
      Point(120, 30),
      Point(100, 60),
      Point(120, 70),
      Point(150, 60),
      Point(140, 10)};

   Rect rect(65, 15, 70, 45);

   GraphicsPath path;

   path.AddClosedCurve(points, 6);

   // Create a region from a path.
   Region region(&path);

   // Update the region so that it consists of all points inside the
   // rectangle but outside the path region.
   region.Complement(rect);

   graphics.FillRegion(&solidBrush, &region);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
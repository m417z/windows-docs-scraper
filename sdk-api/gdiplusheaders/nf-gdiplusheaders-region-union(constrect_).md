# Region::Union(Rect&)

## Description

The Region::Union method updates this region to all portions (intersecting and nonintersecting) of itself and all portions of the specified rectangle's interior.

## Parameters

### `rect`

Reference to a rectangle to use to update this region.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a region from a path and then uses a rectangle to update the region.
The updated region is the union of the path region and a rectangle.

```cpp
VOID Example_UnionRect(HDC hdc)
{
   Graphics graphics(hdc);

   Point points[] = {
      Point(110, 20),
      Point(120, 30),
      Point(100, 60),
      Point(120, 70),
      Point(150, 60),
      Point(140, 10)};

   Rect rect(65, 15, 70, 45);
   GraphicsPath path;
   SolidBrush solidBrush(Color(255, 255, 0, 0));

   path.AddClosedCurve(points, 6);

   // Create a region from a path.
   Region pathRegion(&path);

   // Form the union of the region and a rectangle.
   pathRegion.Union(rect);

   graphics.FillRegion(&solidBrush, &pathRegion);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
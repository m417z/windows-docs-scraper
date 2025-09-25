# Region::Translate(INT,INT)

## Description

The **Region::Translate** method offsets this region by specified amounts in the horizontal and vertical directions.

## Parameters

### `dx`

Integer that specifies the amount to shift the region in the x direction.

### `dy`

Integer that specifies the amount to shift the region in the y direction.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example creates a region from a path and fills it.
The code then translates the region and fills the translated region to show how the region has shifted.

```cpp
VOID Example_Translate(HDC hdc)
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

   // Translate the region.
   INT dx = 100;
   INT dy = 60;
   pathRegion.Translate(dx, dy);
   graphics.FillRegion(&solidBrush, &pathRegion);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[Region::Transform](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-transform)
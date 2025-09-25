# Region::GetBounds(Rect*,Graphics*)

## Description

The **Region::GetBounds** method gets a rectangle that encloses this region.

## Parameters

### `rect`

Pointer to a [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object that receives the enclosing rectangle.

### `g`

Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains the world and page transformations required to calculate the device coordinates of this region and the rectangle.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The current world and page transformations of the graphics object are used to calculate the region and the rectangle as they are drawn on the display device.
The rectangle returned by **Region::GetBounds** is not always the smallest possible rectangle.

#### Examples

The following example creates a region from a path, gets the region's enclosing rectangle, and then displays both.

```cpp
VOID Example_GetBoundsRect(HDC hdc)
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
    Pen pen(Color(255, 0, 0, 0));
    Rect rect;

   path.AddClosedCurve(points, 6);

    // Create a region from a path.
    Region pathRegion(&path);

    // Get the region's enclosing rectangle.
    pathRegion.GetBounds(&rect, &graphics);

    // Show the region and the enclosing rectangle.
    graphics.FillRegion(&solidBrush, &pathRegion);
    graphics.DrawRectangle(&pen, rect);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
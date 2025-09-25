# Region::GetHRGN

## Description

The **Region::GetHRGN** method creates a Windows Graphics Device Interface (GDI) region from this region.

## Parameters

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains the world and page transformations required to calculate the device coordinates of this region.

## Return value

Type: **HRGN**

This method returns a Windows handle to a GDI region that is created from this region.

## Remarks

It is the caller's responsibility to call the GDI function
[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) to free the GDI region when it is no longer needed.

#### Examples

The following example creates a GDI+ region from a path and then uses the GDI+ region to create a GDI region. The code then uses a GDI function to display the GDI region.

```cpp
VOID Example_GetHRGN(HDC hdc)
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
   path.AddClosedCurve(points, 6);

    // Create a region from a path.
    Region pathRegion(&path);

   // Get a handle to a GDI region.
   HRGN hRegion;
   hRegion = pathRegion.GetHRGN(&graphics);

   // Use GDI to display the region.
   HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
   FillRgn(hdc, hRegion, hBrush);

   DeleteObject(hBrush);
   DeleteObject(hRegion);
}
```

## See also

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)
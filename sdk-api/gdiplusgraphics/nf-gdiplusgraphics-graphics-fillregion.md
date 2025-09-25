# Graphics::FillRegion

## Description

The **Graphics::FillRegion** method uses a brush to fill a specified region.

## Parameters

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a brush that is used to paint the region.

### `region` [in]

Type: **const [Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)***

Pointer to a region to be filled.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Because a region describes a set of pixels, a pixel is considered either fully inside, or fully outside the region. Consequently, **Graphics::FillRegion** does not antialias the edges of the region.

#### Examples

The following example creates a region from a rectangle and then fills the region.

```cpp
VOID Example_FillRegion(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a SolidBrush object.
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Create a Region object from a rectangle.
   Region ellipseRegion(Rect(0, 0, 200, 100));

   // Fill the region.
   graphics.FillRegion(&blackBrush, &ellipseRegion);
}
```

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Regions](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-regions-about)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
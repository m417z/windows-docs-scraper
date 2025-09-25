# Graphics::SetClip(IN HRGN,IN CombineMode)

## Description

The **Graphics::SetClip** method updates the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to a region that is the combination of itself and a Windows Graphics Device Interface (GDI) region.

## Parameters

### `hRgn` [in]

Type: **HRGN**

Handle to a GDI region to be combined with the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. This is provided for legacy code. New applications should pass a [Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object as the first parameter.

### `combineMode` [in]

Type: **[CombineMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-combinemode)**

Optional. Element of the [CombineMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-combinemode) enumeration that specifies how the GDI region is combined with the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The default value is CombineModeReplace.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method assumes that the GDI region specified by
*hRgn* is already in device units, so it does not transform the coordinates of the GDI region.

#### Examples

The following example uses a GDI region to update the clipping region.

```cpp
VOID Example_SetClip2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Region object, and get its handle.
   Region region(Rect(0, 0, 100, 100));
   HRGN hRegion = region.GetHRGN(&graphics);

   // Set the clipping region with hRegion.
   graphics.SetClip(hRegion);

   // Fill a rectangle to demonstrate the clipping region.
   graphics.FillRectangle(&SolidBrush(Color(255, 0, 0, 0)), 0, 0, 500, 500);
}
```

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[CombineMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-combinemode)

[GetClipBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclipbounds(outrect))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[Graphics::IsClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isclipempty)

[Graphics::ResetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resetclip)

[IntersectClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-intersectclip(inconstrect_))

[TranslateClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translateclip(inint_inint))
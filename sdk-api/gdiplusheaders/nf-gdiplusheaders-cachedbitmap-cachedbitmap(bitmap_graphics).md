## Description

Creates a **CachedBitmap::CachedBitmap** object based on a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object and a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The cached bitmap takes the pixel data from the **Bitmap** object and stores it in a format that is optimized for the display device associated with the **Graphics** object.

## Parameters

### `bitmap`

Type: [in] **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)***

Pointer to a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object that contains the pixel data to be optimized.

### `graphics`

Type: [in] **[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that is associated with a display device for which the image will be optimized.

## Remarks

You can display a cached bitmap by passing the address of a **CachedBitmap::CachedBitmap** object to the
[DrawCachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawcachedbitmap) method of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. Use the **Graphics** object that was passed to the **CachedBitmap::CachedBitmap** constructor or another **Graphics** object that represents the same device.

## Examples

The following example creates a **CachedBitmap::CachedBitmap** object based on a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object and a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The code calls the
[DrawCachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawcachedbitmap) method of that **Graphics** object to display the cached bitmap.

```cpp
VOID Example_CachedBitmap(HDC hdc)
{
   Graphics graphics(hdc);
   Bitmap bitmap(L"Grapes.jpg");
   CachedBitmap cachedBitmap(&bitmap, &graphics);

   graphics.DrawCachedBitmap(&cachedBitmap, 10, 10);
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Using a Cached Bitmap to Improve Performance](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-cached-bitmap-to-improve-performance-use)
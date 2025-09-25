# Graphics::DrawCachedBitmap

## Description

The **Graphics::DrawCachedBitmap** method draws the image stored in a
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object.

## Parameters

### `cb` [in]

Type: **[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap)***

Pointer to a
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object that contains the image to be drawn.

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the image.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the image.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object stores an image in a format that is optimized for a particular display screen. You cannot draw a cached bitmap to a printer or to a metafile.

Cached bitmaps will not work with any transformations other than translation.

When you construct a
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object, you must pass the address of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to the constructor. If the screen associated with that
**Graphics** object has its bit depth changed after the cached bitmap is constructed, then the **Graphics::DrawCachedBitmap** method will fail, and you should reconstruct the cached bitmap. Alternatively, you can hook the display change notification message and reconstruct the cached bitmap at that time.

#### Examples

The following example calls **Graphics::DrawCachedBitmap** to draw the image stored in a
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object.

```cpp
VOID Example_DrawCachedBitmap(HDC hdc)
{
   Graphics graphics(hdc);

   // Create Bitmap object.
   Bitmap bitmap(L"Climber.jpg");

   // Use the Bitmap object to create a CachedBitmap object.
   CachedBitmap cachedBitmap(&bitmap, &graphics);

   // Draw the cached bitmap.
   graphics.DrawCachedBitmap(&cachedBitmap, 20, 10);
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Using a Cached Bitmap to Improve Performance](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-cached-bitmap-to-improve-performance-use)
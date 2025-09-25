# Graphics::FromImage

## Description

The **Graphics::FromImage** method creates a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that is associated with a specified
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that will be associated with the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Return value

Type: **[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

This method returns a pointer to the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Remarks

This method fails if the
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object is based on a metafile that was opened for reading. The
[Image::Image(filename, useEmbeddedColorManagement)](https://learn.microsoft.com/previous-versions/ms535411(v=vs.85)) and
[Metafile::Metafile(filename)](https://learn.microsoft.com/previous-versions/ms535285(v=vs.85)) constructors open a metafile for reading. To open a metafile for recording, use a
[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) constructor that receives a device context handle.

This method also fails if the image has one of the following pixel formats:

* **PixelFormatUndefined**
* **PixelFormatDontCare**
* **PixelFormat1bppIndexed**
* **PixelFormat4bppIndexed**
* **PixelFormat8bppIndexed**
* **PixelFormat16bppGrayScale**
* **PixelFormat16bppARGB1555**

#### Examples

The following example calls the **Graphics::FromImage** method to create a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that is associated with an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object. The call to
[Graphics::FillEllipse](https://learn.microsoft.com/previous-versions/ms535969(v=vs.85)) does not paint on the display device; instead, it alters the bitmap of the
**Image** object. The call to
[Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536030(v=vs.85)) displays the altered bitmap.

```cpp
VOID Example_FromImage(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an Image object from a PNG file.
   Image image(L"Mosaic.png");

   // Create a Graphics object that is associated with the image.
   Graphics* imageGraphics = Graphics::FromImage(&image);

   // Alter the image.
   SolidBrush brush(Color(255, 0, 0, 255));
   imageGraphics->FillEllipse(&brush, 10, 40, 100, 50);

   // Draw the altered image.
   graphics.DrawImage(&image, 30, 20);

   delete imageGraphics;
}
```

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[FromHDC Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhdc(inhdc))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))

[Graphics::FromHWND](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhwnd)

[Graphics::GetHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gethdc)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)
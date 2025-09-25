# Graphics::Graphics(IN Image)

## Description

Creates a **Graphics::Graphics** object that is associated with an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `image` [in]

Type: **Image***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that will be associated with the new **Graphics::Graphics** object.

## Remarks

This constructor fails if the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object is based on a metafile that was opened for reading. The
**Image::Image(file)** and
**Metafile::Metafile(file)** constructors open a metafile for reading. To open a metafile for recording, use a
**Metafile** constructor that receives a device context handle.

This constructor also fails if the image uses one of the following pixel formats:

* PixelFormatUndefined
* PixelFormatDontCare
* PixelFormat1bppIndexed
* PixelFormat4bppIndexed
* PixelFormat8bppIndexed
* PixelFormat16bppGrayScale
* PixelFormat16bppARGB1555

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[Getting Started](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-getting-started-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)
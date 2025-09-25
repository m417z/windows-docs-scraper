# Image::GetThumbnailImage

## Description

The **Image::GetThumbnailImage** method gets a thumbnail image from this
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.

## Parameters

### `thumbWidth` [in]

Type: **UINT**

Width, in pixels, of the requested thumbnail image.

### `thumbHeight` [in]

Type: **UINT**

Height, in pixels, of the requested thumbnail image.

### `callback` [in]

Type: **GetThumbnailImageAbort**

Optional. Callback function that you provide. During the process of creating or retrieving the thumbnail image, GDI+ calls this function to give you the opportunity to abort the process. The default value is **NULL**.

### `callbackData`

Type: **VOID***

Optional. Pointer to a block of memory that contains data to be used by the callback function. The default value is **NULL**.

## Return value

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

This method returns a pointer to an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that contains the thumbnail image.

## Remarks

A thumbnail image is a small copy of an image. Some image files have a thumbnail image embedded in the file. In such cases, this method retrieves the embedded thumbnail image. If there is no embedded thumbnail image, this method creates a thumbnail image by scaling the main image to the size specified in the
*thumbWidth* and
*thumbHeight* parameters. If both of those parameters are 0, a system-defined size is used.

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a JPEG file. The code calls the **Image::GetThumbnailImage** method of that
**Image** object and then displays the thumbnail image along with the main image.

```cpp
VOID Example_GetThumbnail(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an image and a thumbnail of the image.
   Image image(L"Crayons.jpg");
   Image* pThumbnail = image.GetThumbnailImage(40, 40, NULL, NULL);

   // Draw the original and the thumbnail images.
   graphics.DrawImage(&image, 10, 10, image.GetWidth(), image.GetHeight());
   graphics.DrawImage(
      pThumbnail,
      150,
      10,
      pThumbnail->GetWidth(),
      pThumbnail->GetHeight());

   delete pThumbnail;

}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Creating Thumbnail Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-thumbnail-images-use)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)
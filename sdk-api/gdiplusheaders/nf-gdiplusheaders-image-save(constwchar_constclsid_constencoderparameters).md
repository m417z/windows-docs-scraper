# Image::Save(WCHAR*,CLSID*,EncoderParameters*)

## Description

The **Image::Save** method saves this image to a file.

## Parameters

### `filename`

Pointer to a null-terminated string that specifies the path name for the saved image.

### `clsidEncoder`

Pointer to a CLSID that specifies the encoder to use to save the image.

### `encoderParams`

Optional.
Pointer to an [EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85)) object that holds parameters used by the encoder.
The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

GDI+ does not allow you to save an image to the same file that you used to construct the image.
The following code creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object by passing the file name `MyImage.jpg` to an **Image** constructor.
That same file name is passed to the **Image::Save** method of the Image object, so the **Image::Save** method fails.

```cpp
Image image(L"myImage.jpg");

// Do other operations.

// Save the image to the same file name. (This operation will fail.)
image.Save(L"myImage.jpg", ...);
```

#### Examples

The following example creates an **Image** object from a PNG file and then creates a Graphics object based on that **Image** object.
The code draws the image, alters the image, and draws the image again.
Finally, the code saves the altered image to a file.

The code relies on a helper function, *GetEncoderClsid*, to get the class identifier for the PNG encoder.
The *GetEncoderClsid* function is shown in *Retrieving the Class Identifier for an Encoder*.

The technique of constructing a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object based on an image works only for certain image formats.
For example, you cannot construct a **Graphics** object based on an image that has a color depth of 4 bits per pixel.
For more information about which formats are supported by the **Graphics** constructor, see [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics).

```cpp
VOID Example_SaveFile(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an Image object based on a PNG file.
   Image  image(L"Mosaic.png");

   // Draw the image.
   graphics.DrawImage(&image, 10, 10);

   // Construct a Graphics object based on the image.
   Graphics imageGraphics(&image);

   // Alter the image.
   SolidBrush brush(Color(255, 0, 0, 255));
   imageGraphics.FillEllipse(&brush, 20, 30, 80, 50);

   // Draw the altered image.
   graphics.DrawImage(&image, 200, 10);

   // Save the altered image.
   CLSID pngClsid;
   GetEncoderClsid(L"image/png", &pngClsid);
   image.Save(L"Mosaic2.png", &pngClsid, NULL);
}
```

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))

[EncoderParameters](https://learn.microsoft.com/previous-versions/ms534435(v=vs.85))

[GetImageEncoders](https://learn.microsoft.com/windows/desktop/api/gdiplusimagecodec/nf-gdiplusimagecodec-getimageencoders)

[Image::Save Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-save(inistream_inconstclsid_inconstencoderparameters))

[Image::SaveAdd Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-saveadd(inimage_inconstencoderparameters))

[Using Image Encoders and Decoders](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-image-encoders-and-decoders-use)
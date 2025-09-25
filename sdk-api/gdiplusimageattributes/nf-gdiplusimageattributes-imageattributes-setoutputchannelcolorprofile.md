# ImageAttributes::SetOutputChannelColorProfile

## Description

The **ImageAttributes::SetOutputChannelColorProfile** method sets the output channel color-profile file for a specified category.

## Parameters

### `colorProfileFilename` [in]

Type: **const WCHAR***

Path name of a color-profile file. If the color-profile file is in the %SystemRoot%\System32\Spool\Drivers\Color directory, then this parameter can be the file name. Otherwise, this parameter must be the fully qualified path name.

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the output channel color-profile file is set. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You can use the [ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel) and **ImageAttributes::SetOutputChannelColorProfile** methods to convert an image to a cyan-magenta-yellow-black (CMYK) color space and examine the intensities of one of the CMYK color channels. For example, suppose you write code that performs the following steps:

1. Create an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object.
2. Create an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object.
3. Pass [ColorChannelFlagsC](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags) to the [ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel) method of the
   [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object.
4. Pass the path name of a color profile file to the **ImageAttributes::SetOutputChannelColorProfile** method of the
   [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object.
5. Pass the addresses of the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) and
   [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) objects to the [DrawImage](https://learn.microsoft.com/previous-versions/ms536030(v=vs.85)) method.

Windows GDI+ will use the color-profile file to calculate the cyan component of each pixel in the image, and each pixel in the rendered image will be a shade of gray that indicates the intensity of its cyan channel.

An
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify an output channel color-profile file for the default category and a different output channel color-profile file for the bitmap category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the bitmap category, then the default settings apply to the bitmap category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a collection of adjustment settings for the default category. If you set the output channel color-profile file for the bitmap category by passing [ColorAdjustTypeBitmap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::SetOutputChannelColorProfile** method, then none of the default adjustment settings will apply to bitmaps.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and calls the [DrawImage](https://learn.microsoft.com/previous-versions/ms536030(v=vs.85)) method to draw the image. Then the code creates an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and calls its **ImageAttributes::SetOutputChannelColorProfile** method to specify a profile file for the bitmap category. The call to [ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel) sets the output channel (for the bitmap category) to cyan. The code calls **DrawImage** a second time, passing the address of the **Image** object and the address of the **ImageAttributes** object. The cyan channel of each pixel is calculated, and the rendered image shows the intensities of the cyan channel as shades of gray. The code calls **DrawImage** three more times to show the intensities of the magenta, yellow, and black channels.

```cpp

VOID Example_SetOutputProfile(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"Mosaic2.bmp");
   ImageAttributes imAtt;
   UINT width = image.GetWidth();
   UINT height = image.GetHeight();

   // Draw the image unaltered.
   graphics.DrawImage(&image, 10, 10, width, height);

   imAtt.SetOutputChannelColorProfile(
      L"TEKPH600.ICM", ColorAdjustTypeBitmap);

   // Draw the image, showing the intensity of the cyan channel.
   imAtt.SetOutputChannel(ColorChannelFlagsC, ColorAdjustTypeBitmap);
   graphics.DrawImage(
      &image,
      Rect(110, 10, width, height),  // dest rect
      0, 0, width, height,           // source rect
      UnitPixel,
      &imAtt);

   // Draw the image, showing the intensity of the magenta channel.
   imAtt.SetOutputChannel(ColorChannelFlagsM, ColorAdjustTypeBitmap);
   graphics.DrawImage(
      &image,
      Rect(210, 10, width, height),  // dest rect
      0, 0, width, height,           // source rect
      UnitPixel,
      &imAtt);

   // Draw the image, showing the intensity of the yellow channel.
   imAtt.SetOutputChannel(ColorChannelFlagsY, ColorAdjustTypeBitmap);
   graphics.DrawImage(
      &image,
      Rect(10, 110, width, height),  // dest rect
      0, 0, width, height,           // source rect
      UnitPixel,
      &imAtt);

   // Draw the image, showing the intensity of the black channel.
   imAtt.SetOutputChannel(ColorChannelFlagsK, ColorAdjustTypeBitmap);
   graphics.DrawImage(
      &image,
      Rect(110, 110, width, height),  // dest rect
      0, 0, width, height,            // source rect
      UnitPixel,
      &imAtt);
}
				
```

The preceding code, along with the files Mosaic2.bmp and Tekph600.icm, produced the following output.

![Illustration showing four versions of one image: first in color, then in three different patterns of greyscale](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributessetoutputprofile.png)

## See also

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorChannelFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearoutputchannel)

[ImageAttributes::ClearOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearoutputchannelcolorprofile)

[ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel)
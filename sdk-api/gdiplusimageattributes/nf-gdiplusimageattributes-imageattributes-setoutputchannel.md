# ImageAttributes::SetOutputChannel

## Description

The **ImageAttributes::SetOutputChannel** method sets the CMYK output channel for a specified category.

## Parameters

### `channelFlags` [in]

Type: **[ColorChannelFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags)**

Element of the [ColorChannelFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags) enumeration that specifies the output channel.

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the output channel is set. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You can use the **ImageAttributes::SetOutputChannel** method to convert an image to a cyan-magenta-yellow-black (CMYK) color space and examine the intensities of one of the CMYK color channels. For example, suppose you create an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and set its bitmap output channel to [ColorChannelFlagsC](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags). If you pass the address of that **ImageAttributes** object to the [DrawImage](https://learn.microsoft.com/previous-versions/ms536037(v=vs.85)) method, the cyan component of each pixel is calculated, and each pixel in the rendered image is a shade of gray that indicates the intensity of its cyan channel. Similarly, you can render images that indicate the intensities of the magenta, yellow, and black channels.

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify an output channel for the default category and a different output channel for the bitmap category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the bitmap category, then the default settings apply to the bitmap category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a collection of adjustment settings for the default category. If you set the output channel for the bitmap category by passing [ColorAdjustTypeBitmap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::SetOutputChannel** method, then none of the default adjustment settings will apply to bitmaps.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and calls the [DrawImage](https://learn.microsoft.com/previous-versions/ms536037(v=vs.85)) method to draw the image. Then the code creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and sets its bitmap output channel to cyan ([ColorChannelFlagsC](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags)). The code calls [DrawImage](https://learn.microsoft.com/previous-versions/ms536030(v=vs.85)) a second time, passing the address of the **Image** object and the address of the **ImageAttributes** object. The cyan channel of each pixel is calculated, and the rendered image shows the intensities of the cyan channel as shades of gray. The code calls **DrawImage** three more times to show the intensities of the magenta, yellow, and black channels.

```cpp

VOID Example_SetOutputChannel(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"Mosaic2.bmp");

   // Draw the image unaltered.
   graphics.DrawImage(&image, 10, 10, width, height);

   UINT width = image.GetWidth();
   UINT height = image.GetHeight();

   ImageAttributes imAtt;

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

The following illustration shows the output of the preceding code.

![Illustration showing five versions of one image: first in color, then in four different patterns of greyscale](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributessetoutputchannel.png)

## See also

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorChannelFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearoutputchannel)

[ImageAttributes::ClearOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearoutputchannelcolorprofile)

[ImageAttributes::SetOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannelcolorprofile)
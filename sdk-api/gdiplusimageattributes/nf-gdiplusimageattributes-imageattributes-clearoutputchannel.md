# ImageAttributes::ClearOutputChannel

## Description

The **ImageAttributes::ClearOutputChannel** method clears the cyan-magenta-yellow-black (CMYK) output channel setting for a specified category.

## Parameters

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the output channel setting is cleared. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify an output channel for the default category and a different output channel for the bitmap category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the bitmap category, then the default settings apply to the bitmap category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify an output channel and an adjustment matrix for the default category. If you set the output channel for the bitmap category by calling [ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel), then the default output channel will not apply to bitmaps. If you later clear the bitmap output channel by calling **ImageAttributes::ClearOutputChannel**, the bitmap category will not revert to the default output channel; rather, the bitmap category will have no output channel setting. Similarly, the bitmap category will not revert to the default color-adjustment matrix; rather, the bitmap category will have no color-adjustment matrix.

## See also

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorChannelFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearoutputchannelcolorprofile)

[ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel)

[ImageAttributes::SetOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannelcolorprofile)
# ImageAttributes::ClearOutputChannelColorProfile

## Description

The **ImageAttributes::ClearOutputChannelColorProfile** method clears the output channel color profile setting for a specified category.

## Parameters

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the output channel profile setting is cleared. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify an output channel profile for the default category and a different output channel profile for the bitmap category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the bitmap category, then the default settings apply to the bitmap category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify an output channel profile and an adjustment matrix for the default category. If you set the output channel profile for the bitmap category by calling [ImageAttributes::SetOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannelcolorprofile), then the default output channel profile will not apply to bitmaps. If you later clear the bitmap output channel profile by calling **ImageAttributes::ClearOutputChannelColorProfile**, the bitmap category will not revert to the default output channel profile; rather, the bitmap category will have no output channel profile setting. Similarly, the bitmap category will not revert to the default color-adjustment matrix; rather, the bitmap category will have no color-adjustment matrix.

## See also

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorChannelFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/ne-gdipluscolor-colorchannelflags)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearoutputchannel)

[ImageAttributes::SetOutputChannel](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannel)

[ImageAttributes::SetOutputChannelColorProfile](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setoutputchannelcolorprofile)
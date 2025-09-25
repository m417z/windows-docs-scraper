# ColorAdjustType enumeration

## Description

The **ColorAdjustType** enumeration specifies which GDI+ objects use color-adjustment information. You can adjust the colors in a rendered image by passing the address of an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object to the
[Graphics::DrawImage](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(inimage_inconstpointf_inint)) method. An
**ImageAttributes** object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. Several of the methods of the
**ImageAttributes** class receive an element of the **ColorAdjustType** enumeration to specify the adjustment category.

## Constants

### `ColorAdjustTypeDefault`

Specifies that color or grayscale adjustment applies to all categories that do not have adjustment settings of their own.

### `ColorAdjustTypeBitmap`

Specifies that color or grayscale adjustment applies to bitmapped images.

### `ColorAdjustTypeBrush`

Specifies that color or grayscale adjustment applies to brush operations in metafiles.

### `ColorAdjustTypePen`

Specifies that color or grayscale adjustment applies to pen operations in metafiles.

### `ColorAdjustTypeText`

Specifies that color or grayscale adjustment applies to text drawn in metafiles.

### `ColorAdjustTypeCount`

Used internally to record the number of color adjustment types.

### `ColorAdjustTypeAny`

Reserved
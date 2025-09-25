# InkRasterOperation enumeration

## Description

Defines values for performing raster operations on drawn ink.

## Constants

### `IRO_Black:1`

 Black pen color.

### `IRO_NotMergePen:2`

The inverse of MergePen.

### `IRO_MaskNotPen:3`

 A combination of the colors that are common to the background color and the inverse of the pen.

### `IRO_NotCopyPen:4`

 The inverse of CopyPen.

### `IRO_MaskPenNot:5`

A combination of the colors that are common to both the pen and the inverse of the display.

### `IRO_Not:6`

The inverse of the display color.

### `IRO_XOrPen:7`

A combination of the colors in the pen and in the display color, but not in both.

### `IRO_NotMaskPen:8`

The inverse of MaskPen.

### `IRO_MaskPen:9`

A combination of the colors that are common to both the pen and the display.

### `IRO_NotXOrPen:10`

An inverse of XOrPen.

### `IRO_NoOperation:11`

No operation; the output remains unchanged.

### `IRO_MergeNotPen:12`

A combination of the display color and the inverse of the pen color.

### `IRO_CopyPen:13`

The pen color.

This is the default value.

### `IRO_MergePenNot:14`

A combination of the pen color and the inverse of the display color.

### `IRO_MergePen:15`

A combination of the pen color and the display color.

### `IRO_White:16`

A white pen color.

## Remarks

Use these values to set the value for the [RasterOperation](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_rasteroperation) drawing attribute. Any object with a [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) property can have this value set.

**Note** Many printers do not support many of the available raster operations. Because of this, the colors you see on the display may be different from the colors that you would see if they were printed on paper. This is directly related to the printer drivers or printer hardware. You may need to experiment to determine which printers can produce the correct output when various raster operations are set on ink.

When the **RasterOperation** value is set to anything other than CopyPen, all drawing attributes (anti-aliasing, smoothing, transparency, and pressure) are ignored.

## See also

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[RasterOperation Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdrawingattributes-get_rasteroperation)
# IInkDrawingAttributes::put_RasterOperation

## Description

Gets or sets a value that defines how the colors of the pen and background interact.

This property is read/write.

## Parameters

## Remarks

The [InkRasterOperation](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrasteroperation) enumeration defines values for performing raster operations on drawn ink. For example, if you want to perform subtractive transparency, set the raster value to MaskPen.

For a complete list of available raster operations, see the [InkRasterOperation](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrasteroperation) enumeration type.

**Note** Many printers do not support many of the available raster operations. Because of this, the colors displayed may be different than the colors printed. This is directly related to the printer drivers or printer hardware. You may have to experiment to determine which printers can produce the correct output when various raster operations are set on ink.

When the **RasterOperation** property is set to anything other than [InkRasterOperation.IRO_CopyPen](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrasteroperation), all drawing attributes-anti-aliasing, smoothing, transparency, and pressure-are ignored.

## See also

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkRasterOperation Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrasteroperation)
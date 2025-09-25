# IXpsRasterizer::SetMinimalLineWidth

## Description

The `SetMinimalLineWidth` method allows the caller to set the minimum thickness (in pixels) of the lines that the device can render. The default minimum thickness value is 1 pixel if `SetMinimalLineWidth` is not called. This minimum thickness value only applies to the Nominal Width Stroke as defined in the XPS Specification v1.0, Sec 11.6.12. **IXpsRasterizer** requires that any Nominal Width Stroke is rasterized with either the width specified by its **StrokeThickness** attribute, or the pixel value set by `SetMinimalLineWidth` (1 pixel if `SetMinimalLineWidth` is not called), whichever is bigger.

## Parameters

### `width` [in]

The minimum thickness (in pixels) of the lines the device is capable of rendering. The value should be greater than 1.

## Return value

`SetMinimalLineWidth` always returns S_OK.

## Remarks

This method is supported in Windows 7 and later. It is not supported in versions of the Windows operating system before Windows 7.

## See also

[IWICBitmap](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmap)

[IXpsRasterizationFactory::CreateRasterizer](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizationfactory-createrasterizer)

[IXpsRasterizer](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizer)

[IXpsRasterizer::RasterizeRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizer-rasterizerect)

[IXpsRasterizerNotificationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizernotificationcallback)
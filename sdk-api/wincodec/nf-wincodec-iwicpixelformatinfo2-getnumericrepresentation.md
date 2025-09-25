## Description

Retrieves the [WICPixelFormatNumericRepresentation](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicpixelformatnumericrepresentation) of the pixel format.

## Parameters

### `pNumericRepresentation` [out]

Type: **[WICPixelFormatNumericRepresentation](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicpixelformatnumericrepresentation)***

The address of a [WICPixelFormatNumericRepresentation](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicpixelformatnumericrepresentation) variable that you've defined. On successful completion, the function sets your variable to the **WICPixelFormatNumericRepresentation** of the pixel format.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWICPixelFormatInfo2](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicpixelformatinfo2)
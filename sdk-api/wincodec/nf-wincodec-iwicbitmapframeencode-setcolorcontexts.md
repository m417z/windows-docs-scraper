# IWICBitmapFrameEncode::SetColorContexts

## Description

Sets a given number [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) profiles to the frame.

## Parameters

### `cCount` [in]

Type: **UINT**

The number of [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) profiles to set.

### `ppIColorContext` [in]

Type: **[IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext)****

A pointer to an [IWICColorContext](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccolorcontext) pointer containing the color contexts profiles to set to the frame.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

* **BMP**Setting color contexts is unsupported. This function will return **WINCODEC_ERR_UNSUPPORTEDOPERATION**.
* **PNG**Setting at most one color context is supported, and additional color contexts will be ignored. This context must be a [WICColorContextProfile](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype), and is used to encode the iCCP, gAMA, and cHRM chunks in the PNG file.
* **JPEG, TIFF, JPEG-XR**Setting up to one [WICColorContextProfile](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype) and one [WICColorContextExifColorSpace](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype) is supported. Users must not provide more than one of each type of color context, as all but the last context of each type will be ignored. In JPEG, the **WICColorContextProfile** is encoded to JPEG APP2 ICC metadata block.

  In TIFF and JPEG-XR, the [WICColorContextProfile](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype) is encoded to the IFD ICC profile metadata block (IFD tag 0x8773). In all three formats, the [WICColorContextExifColorSpace](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype) is encoded to EXIF colorspace metadata block (EXIF tag 0xA001).
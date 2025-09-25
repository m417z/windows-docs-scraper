# IWICJpegFrameEncode::WriteScan

## Description

Writes scan data to a JPEG frame.

## Parameters

### `cbScanData`

Type: **UINT**

The size of the data in the *pbScanData* parameter.

### `pbScanData`

Type: **BYTE***

The scan data to write.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK on successful completion.

## Remarks

**WriteScan** may be called multiple times. Each call appends the scan data specified to any previous scan data. Complete the scan by calling [IWICBitmapFrameEncode::Commit](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-commit).

Any calls to set encoder parameters or image metadata that will appear before the scan data in the resulting JPEG file must be completed before the first call to this method. This includes calls to [IWICBitmapFrameEncode::SetColorContexts](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setcolorcontexts) , [IWICBitmapFrameEncode::SetPalette](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpalette), [IWICBitmapFrameEncode::SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setpixelformat), [IWICBitmapFrameEncode::SetResolution](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setresolution), and [IWICBitmapFrameEncode::SetThumbnail](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setthumbnail). [IWICBitmapFrameEncode::SetSize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-setsize) is required as it has no default value for encoded image size.

## See also

[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode)

[IWICJpegFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicjpegframeencode)
# IWICColorContext::GetExifColorSpace

## Description

Retrieves the Exchangeable Image File (EXIF) color space color context.

## Parameters

### `pValue` [out]

Type: **UINT***

A pointer that receives the EXIF color space color context.

| Value | Meaning |
| --- | --- |
| 1 | A sRGB color space. |
| 2 | An Adobe RGB color space. |
| 3 through 65534 | Unused. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should only be used when [IWICColorContext::GetType](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwiccolorcontext-gettype) indicates [WICColorContextExifColorSpace](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype).
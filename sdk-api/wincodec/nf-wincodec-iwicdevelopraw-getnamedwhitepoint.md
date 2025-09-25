# IWICDevelopRaw::GetNamedWhitePoint

## Description

Gets the named white point of the raw image.

## Parameters

### `pWhitePoint` [out]

Type: **[WICNamedWhitePoint](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicnamedwhitepoint)***

A pointer that receives the bitwise combination of the enumeration values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the named white points are not supported by the raw image or the raw file contains named white points that are not supported by this API, the codec implementer should still mark this capability as supported.

If the named white points are not supported by the raw image, a best effort should be made to adjust the image to the named white point even when it isn't a pre-defined white point of the raw file.

If the raw file contains named white points not supported by this API, the codec implementer should support the named white points in [WICNamedWhitePoint](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicnamedwhitepoint).
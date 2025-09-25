# IWICDevelopRaw::SetNamedWhitePoint

## Description

Sets the named white point of the raw file.

## Parameters

### `WhitePoint` [in]

Type: **[WICNamedWhitePoint](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicnamedwhitepoint)**

A bitwise combination of the enumeration values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the named white points are not supported by the raw image or the raw file contains named white points that are not supported by this API, the codec implementer should still mark this capability as supported.

If the named white points are not supported by the raw image, a best effort should be made to adjust the image to the named white point even when it isn't a pre-defined white point of the raw file.

If the raw file contains named white points not supported by this API, the codec implementer should support the named white points in the API.

Due to other white point setting methods (e.g. [SetWhitePointKelvin](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicdevelopraw-setwhitepointkelvin)), care must be taken by codec implementers to ensure proper interoperability. For instance, if the caller sets via a named white point then the codec implementer may wish to disable reading back the corresponding Kelvin temperature. In specific cases where the codec implementer wishes to deny a given action because of previous calls, **WINCODEC_ERR_WRONGSTATE** should be returned.
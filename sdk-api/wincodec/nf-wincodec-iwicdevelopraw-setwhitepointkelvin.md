# IWICDevelopRaw::SetWhitePointKelvin

## Description

Sets the white point Kelvin value.

## Parameters

### `WhitePointKelvin` [in]

Type: **UINT**

The white point Kelvin value. Acceptable Kelvin values are 1,500 through 30,000.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Codec implementers should faithfully adjust the color temperature within the range supported natively by the raw image. For values outside the native support range, the codec implementer should provide a best effort representation of the image at that color temperature.

Codec implementers should return **WINCODEC_ERR_VALUEOUTOFRANGE** if the value is out of defined acceptable range.

Codec implementers must ensure proper interoperability with other white point setting methods such as [SetWhitePointRGB](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicdevelopraw-setwhitepointrgb). For example, if the caller sets the white point via [SetNamedWhitePoint](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicdevelopraw-setnamedwhitepoint) then the codec implementer may want to disable reading back the corresponding Kelvin temperature. In specific cases where the codec implementer wants to deny a given action because of previous calls, **WINCODEC_ERR_WRONGSTATE** should be returned.
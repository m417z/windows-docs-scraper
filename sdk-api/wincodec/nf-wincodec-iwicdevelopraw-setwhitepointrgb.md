# IWICDevelopRaw::SetWhitePointRGB

## Description

Sets the white point RGB values.

## Parameters

### `Red` [in]

Type: **UINT**

The red white point value.

### `Green` [in]

Type: **UINT**

The green white point value.

### `Blue` [in]

Type: **UINT**

The blue white point value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Due to other white point setting methods (e.g. [SetWhitePointKelvin](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicdevelopraw-setwhitepointkelvin)), care must be taken by codec implementers to ensure proper interoperability. For instance, if the caller sets via a named white point then the codec implementer may wish to disable reading back the corresponding Kelvin temperature. In specific cases where the codec implementer wishes to deny a given action because of previous calls, **WINCODEC_ERR_WRONGSTATE** should be returned.
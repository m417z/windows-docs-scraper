# IWICDevelopRaw::SetToneCurve

## Description

Sets the tone curve for the raw image.

## Parameters

### `cbToneCurveSize` [in]

Type: **UINT**

The size of the *pToneCurve* structure.

### `pToneCurve` [in]

Type: **const [WICRawToneCurve](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrawtonecurve)***

The desired tone curve.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
# IWICDevelopRaw::GetToneCurve

## Description

Gets the tone curve of the raw image.

## Parameters

### `cbToneCurveBufferSize` [in]

Type: **UINT**

The size of the *pToneCurve* buffer.

### `pToneCurve` [out]

Type: **[WICRawToneCurve](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrawtonecurve)***

A pointer that receives the [WICRawToneCurve](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrawtonecurve) of the raw image.

### `pcbActualToneCurveBufferSize` [out]

Type: **UINT***

A pointer that receives the size needed to obtain the tone curve structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
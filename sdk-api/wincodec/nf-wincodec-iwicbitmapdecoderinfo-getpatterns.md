# IWICBitmapDecoderInfo::GetPatterns

## Description

Retrieves the file pattern signatures supported by the decoder.

## Parameters

### `cbSizePatterns` [in]

Type: **UINT**

The array size of the *pPatterns* array.

### `pPatterns` [out]

Type: **[WICBitmapPattern](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicbitmappattern)***

Receives a list of [WICBitmapPattern](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicbitmappattern) objects supported by the decoder.

### `pcPatterns` [out]

Type: **UINT***

Receives the number of patterns the decoder supports.

### `pcbPatternsActual` [out]

Type: **UINT***

Receives the actual buffer size needed to retrieve all pattern signatures supported by the decoder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To retrieve all pattern signatures, this method should first be called with *pPatterns* set to `NULL` to retrieve the actual buffer size needed through *pcbPatternsActual*.
Once the needed buffer size is known, allocate a buffer of the needed size and call **GetPatterns** again with the allocated buffer.
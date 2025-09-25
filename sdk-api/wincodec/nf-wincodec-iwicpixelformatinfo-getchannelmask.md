# IWICPixelFormatInfo::GetChannelMask

## Description

Gets the pixel format's channel mask.

## Parameters

### `uiChannelIndex` [in]

Type: **UINT**

The index to the channel mask to retrieve.

### `cbMaskBuffer` [in]

Type: **UINT**

The size of the *pbMaskBuffer* buffer.

### `pbMaskBuffer` [in, out]

Type: **BYTE***

Pointer to the mask buffer.

### `pcbActual` [out]

Type: **UINT***

The actual buffer size needed to obtain the channel mask.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If 0 and NULL are passed in for *cbMaskBuffer* and *pbMaskBuffer*, respectively, the required buffer size will be returned through *pcbActual*.
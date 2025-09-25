# IWICColorContext::GetProfileBytes

## Description

Retrieves the color context profile.

## Parameters

### `cbBuffer` [in]

Type: **UINT**

The size of the *pbBuffer* buffer.

### `pbBuffer` [in, out]

Type: **BYTE***

A pointer that receives the color context profile.

### `pcbActual` [out]

Type: **UINT***

A pointer that receives the actual buffer size needed to retrieve the entire color context profile.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only use this method if the context type is [WICColorContextProfile](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccolorcontexttype).

Calling this method with *pbBuffer* set to **NULL** will cause it to return the required buffer size in *pcbActual*.
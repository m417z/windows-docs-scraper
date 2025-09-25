# IRichChunk::GetData

## Description

Retrieves the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) and input string that represents a chunk of data.

## Parameters

### `pFirstPos` [out]

Type: **ULONG***

Receives the zero-based starting position of the range. This parameter can be **NULL**.

### `pLength` [out]

Type: **ULONG***

Receives the length of the range. This parameter can be **NULL**.

### `ppsz` [out]

Type: **LPWSTR***

Receives the associated Unicode string value, or **NULL** if not available.

### `pValue` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Receives the associated [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) value, or **VT_EMPTY** if not available. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Prior to Windows 7, this was declared in structuredquery.idl and structuredquery.h.

## See also

[IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk)
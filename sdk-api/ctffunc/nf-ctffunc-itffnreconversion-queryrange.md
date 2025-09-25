# ITfFnReconversion::QueryRange

## Description

The **ITfFnReconversion::QueryRange** method obtains the range of text that the reconversion applies to.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers all or part of the text to be reconverted.

### `ppNewRange`

[in, out] Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) pointer that receives a range object that covers all of text that can be reconverted. If none of the text covered by *pRange* can be reconverted, this parameters receives NULL. In this case, the method will return S_OK, so the caller must verify that this parameter is not NULL before using the pointer.

When this method is implemented by a text service, this parameter is optional and can be NULL. In this case, the range is not required.

When the TSF manager implementation of this method is called, this parameter is not optional and cannot be NULL.

### `pfConvertable` [out]

Pointer to a **BOOL** value that receives zero if none of the text covered by *pRange* can be reconverted or nonzero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfFnReconversion](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnreconversion)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)
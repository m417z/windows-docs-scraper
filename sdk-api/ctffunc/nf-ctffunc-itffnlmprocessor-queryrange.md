# ITfFnLMProcessor::QueryRange

## Description

Obtains the range of text that a reconversion applies to.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers all or part of the text to be reconverted.

### `ppNewRange` [out]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) pointer that receives a range object that covers all of the text that can be reconverted. If none of the text covered by *pRange* can be reconverted, this parameters receives **NULL**. In this case, the method will return S_OK; the caller must verify that this parameter is not **NULL** before using the pointer.

This parameter is optional and can be **NULL**. In this case, the range is not required.

### `pfAccepted` [out]

Pointer to a **BOOL** value that receives zero if none of the text covered by *pRange* can be reconverted or nonzero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

This method is identical to [ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange). When **ITfFnReconversion::QueryRange** is called in the text service, the text service should forward the call to this method if a language model processor is installed. If no language model processor is installed, the text service should perform its default processing.

## See also

[ITfFnLMProcessor](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnlmprocessor)

[ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)
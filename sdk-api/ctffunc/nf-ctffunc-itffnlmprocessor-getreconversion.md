# ITfFnLMProcessor::GetReconversion

## Description

Obtains an ITfCandidateList object for a range from the language model text service.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers the text to be reconverted. To obtain this range object, call [ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange).

### `ppCandList` [out]

Pointer to an **ITfCandidateList** pointer that receives the candidate list object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

This method is identical to [ITfFnReconversion::GetReconversion](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-getreconversion). When **ITfFnReconversion::GetReconversion** is called in the text service, the text service should forward the call to this method if a language model processor is installed. If no language model processor is installed, the text service should perform its default processing.

## See also

[ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist)

[ITfFnLMProcessor](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnlmprocessor)

[ITfFnReconversion::GetReconversion](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-getreconversion)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)
# ITfFnReconversion::GetReconversion

## Description

Obtains an ITfCandidateList object for a range of text.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers the text to be reconverted. This range object is obtained by calling [ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange).

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

## See also

[ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist)

[ITfFnReconversion](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnreconversion)

[ITfFnReconversion::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnreconversion-queryrange)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)
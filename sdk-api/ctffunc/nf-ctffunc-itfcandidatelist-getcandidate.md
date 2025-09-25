# ITfCandidateList::GetCandidate

## Description

Obtains a specific candidate string object.

## Parameters

### `nIndex` [in]

Specifies the zero-based index of the candidate string to obtain.

### `ppCand` [out]

Pointer to an [ITfCandidateString](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatestring) interface pointer that receives the candidate string object. The caller must release this interface when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | *nIndex* is invalid. |
| **E_INVALIDARG** | *ppCand* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist)

[ITfCandidateString](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatestring)
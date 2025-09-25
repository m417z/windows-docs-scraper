# ITfCandidateList::EnumCandidates

## Description

Obtains an enumerator that contains all the candidate string objects in the candidate list.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfCandidates](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtfcandidates) interface pointer that receives the enumerator object. The caller must release this interface when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumTfCandidates](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtfcandidates)

[ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist)
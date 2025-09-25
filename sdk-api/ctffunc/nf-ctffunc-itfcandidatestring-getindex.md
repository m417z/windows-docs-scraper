# ITfCandidateString::GetIndex

## Description

## Parameters

### `pnIndex` [out]

Pointer to a **ULONG** value that receives the zero-based index of the candidate string object within the candidate list.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pnIndex* is invalid. |

## See also

[ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist)

[ITfCandidateString](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatestring)
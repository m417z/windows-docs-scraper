# ITfFnGetLinguisticAlternates::GetAlternates

## Description

Returns a list of alternate strings for a given text range.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers the text to return alternates for.

### `ppCandidateList` [out]

Pointer to an [ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist) pointer that receives the list object containing alternate strings.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred or no alternates could be generated for the range. **ppCandidateList* is returned as null. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfFnGetLinguisticAlternates](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffngetlinguisticalternates)
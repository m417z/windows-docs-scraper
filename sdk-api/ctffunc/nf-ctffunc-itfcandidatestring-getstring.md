# ITfCandidateString::GetString

## Description

Obtains the text of the candidate string object.

## Parameters

### `pbstr` [out]

Pointer to a **BSTR** value that receives the text of the candidate string object. The caller must release this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pbstr* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfCandidateString](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatestring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)
# IEnumTfLanguageProfiles::Next

## Description

Obtains, from the current position, the specified number of elements in the enumeration sequence.

## Parameters

### `ulCount` [in]

Specifies the number of elements to obtain.

### `pProfile` [out]

Pointer to an array of [TF_LANGUAGEPROFILE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_languageprofile) structures that receives the requested data. This array must be at least *ulCount* elements in size.

### `pcFetch` [out]

Pointer to a ULONG value that receives the number of elements obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be obtained. |
| **E_INVALIDARG** | *pProfile* is invalid. |

## See also

[IEnumTfLanguageProfiles interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtflanguageprofiles), [TF_LANGUAGEPROFILE](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_languageprofile)
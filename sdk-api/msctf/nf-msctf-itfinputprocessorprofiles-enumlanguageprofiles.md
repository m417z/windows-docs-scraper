# ITfInputProcessorProfiles::EnumLanguageProfiles

## Description

Obtains an enumerator that contains all of the profiles for a specific language.

## Parameters

### `langid` [in]

Contains a **LANGID** value that specifies the language to obtain an enumerator for.

### `ppEnum` [out]

Pointer to an [IEnumTfLanguageProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtflanguageprofiles) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | No corresponding language profile was found in the operating system.-or-An unspecified error occurred. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumTfLanguageProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtflanguageprofiles)

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)
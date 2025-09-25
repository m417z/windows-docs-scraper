# ITfInputProcessorProfiles::GetLanguageList

## Description

Obtains a list of the installed languages.

## Parameters

### `ppLangId` [out]

Pointer to a **LANGID** pointer that receives the array of identifiers of the currently installed languages. The number of identifiers placed in this array is supplied in *pulCount*. The array is allocated by this method. The caller must free this memory when it is no longer required using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pulCount` [out]

Pointer to a ULONG value the receives the number of identifiers placed in the array at *ppLangId*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)
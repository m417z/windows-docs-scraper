# ITfInputProcessorProfiles::EnumInputProcessorInfo

## Description

Obtains an enumerator that contains the class identifiers of all registered text services.

## Parameters

### `ppEnum` [out]

Pointer to an **IEnumGUID** interface pointer that receives the enumerator object. The enumerator contains the CLSID for each registered text service. The caller must release this object when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfInputProcessorProfiles::Register](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-register)
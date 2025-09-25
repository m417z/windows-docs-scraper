# ITfInputProcessorProfiles::GetDefaultLanguageProfile

## Description

Obtains the default profile for a specific language.

## Parameters

### `langid` [in]

Contains a **LANGID** value that specifies which language to obtain the default profile for.

### `catid` [in]

Contains a GUID value that identifies the category that the text service is registered under. This can be a user-defined category or one of the [predefined category values](https://learn.microsoft.com/windows/desktop/TSF/predefined-category-values).

### `pclsid` [out]

Pointer to a **CLSID** value that receives the class identifier of the default text service for the language.

### `pguidProfile` [out]

Pointer to a **GUID** value that receives the identifier of the default profile for the language.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | No default language profile was found for the specified language and category. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[Predefined Category Values](https://learn.microsoft.com/windows/desktop/TSF/predefined-category-values)
# ITfInputProcessorProfiles::GetActiveLanguageProfile

## Description

Obtains the identifier of the currently active language profile for a specific text service.

## Parameters

### `rclsid` [in]

Contains the text service CLSID.

### `plangid` [out]

Pointer to a **LANGID** value that receives the active profile language identifier.

### `pguidProfile` [out]

Pointer to a **GUID** value that receives the language profile identifier. This is the value specified in [ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile) when the profile was added.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The text service identified by *rclsid* is not currently active. *pguidProfile* receives GUID_NULL. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile)
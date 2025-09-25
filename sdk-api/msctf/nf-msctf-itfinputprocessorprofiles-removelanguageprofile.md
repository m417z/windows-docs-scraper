# ITfInputProcessorProfiles::RemoveLanguageProfile

## Description

Removes a language profile.

## Parameters

### `rclsid` [in]

Contains the text service CLSID.

### `langid` [in]

Contains a **LANGID** value that specifies the language identifier of the profile.

### `guidProfile` [out]

Contains a GUID value that identifies the language profile. This is the value specified in [ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile) when the profile was added.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile)
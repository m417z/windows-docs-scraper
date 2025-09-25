# ITfInputProcessorProfiles::EnableLanguageProfile

## Description

Enables or disables a language profile for the current user.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service of the profile to be enabled or disabled.

### `langid` [in]

Contains a **LANGID** value that specifies the language of the profile to be enabled or disabled.

### `guidProfile` [in]

Contains a GUID value that identifies the profile to be enabled or disabled.

### `fEnable` [in]

Contains a **BOOL** value that specifies if the profile will be enabled or disabled. If this contains a nonzero value, the profile will be enabled. If this contains zero, the profile will be disabled.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfInputProcessorProfiles::EnableLanguageProfileByDefault](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-enablelanguageprofilebydefault)
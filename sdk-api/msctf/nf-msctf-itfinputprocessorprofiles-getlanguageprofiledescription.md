# ITfInputProcessorProfiles::GetLanguageProfileDescription

## Description

Obtains the description string for a language profile.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service to obtain the profile description for.

### `langid` [in]

Contains a **LANGID** value that specifies which language to obtain the profile description for.

### `guidProfile` [in]

Contains a GUID value that identifies the language to obtain the profile description for.

### `pbstrProfile` [out]

Pointer to a **BSTR** value that receives the description string. The caller is responsible for freeing this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pbstrProfile* is invalid. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)
# ITfInputProcessorProfiles::AddLanguageProfile

## Description

Creates a language profile that consists of a specific text service and a specific language identifier.

## Parameters

### `rclsid` [in]

Contains the text service CLSID.

### `langid` [in]

Contains a **LANGID** value that specifies the language identifier of the profile that the text service is added to. If this contains -1, the text service is added to all languages.

### `guidProfile` [in]

Contains a GUID value that identifies the language profile. This is the value obtained by [ITfInputProcessorProfiles::GetActiveLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-getactivelanguageprofile) when the profile is active.

### `pchDesc` [in]

Pointer to a **WCHAR** buffer that contains the description string for the text service in the profile. This is the text service name displayed in the language bar.

### `cchDesc` [in]

Contains the length, in characters, of the description string in *pchDesc*. If this contains -1, *pchDesc* is assumed to be a **NULL**-terminated string.

### `pchIconFile` [in]

Pointer to a **WCHAR** buffer that contains the path and file name of the file that contains the icon to be displayed in the language bar for the text service in the profile. This file can be an executable (.exe), DLL (.dll) or icon (.ico) file.

This parameter is optional and can be **NULL**. In this case, a default icon is displayed for the text service.

### `cchFile` [in]

Contains the length, in characters, of the icon file string in *pchIconFile*. If this contains -1, *pchIconFile* is assumed to be a **NULL**-terminated string. This parameter is ignored if *pchIconFile* is **NULL**.

### `uIconIndex` [in]

Contains the zero-based index of the icon in *pchIconFile* to be displayed in the language bar for the text service in the profile. This parameter is ignored if *pchIconFile* is **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pszDesc* is invalid. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[ITfInputProcessorProfiles::GetActiveLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-getactivelanguageprofile)
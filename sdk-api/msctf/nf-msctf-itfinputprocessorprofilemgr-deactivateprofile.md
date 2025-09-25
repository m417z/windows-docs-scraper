# ITfInputProcessorProfileMgr::DeactivateProfile

## Description

The **ITfInputProcessorProfileMgr::DeactivateProfile** method deactivates the specified text service's profile or keyboard layout.

## Parameters

### `dwProfileType` [in]

[in] The type of this profile. This is one of these values.

| Value | Meaning |
| --- | --- |
| **TF_PROFILETYPE_INPUTPROCESSOR** | This is a text service. |
| **TF_PROFILETYPE_KEYBOARDLAYOUT** | This is a keyboard layout. |

### `langid` [in]

[in] The language id of the profile to be activated.

### `clsid` [in]

[in] The CLSID of the text service of the profile to be activated. This must be CLSID_NULL if *dwProfileType* is TF_PROFILETYPE_KEYBOARDLAYOUT.

### `guidProfile` [in]

[in] The guidProfile of the profile to be activated. This must be GUID_NULL if *dwProfileType* is TF_PROFILETYPE_KEYBOARDLAYOUT.

### `hkl` [in]

[in] The handle of the keyboard layout. This must be **NULL** if *dwProfileType* is TF_PROFILETYPE_INPUTPROCESSOR.

### `dwFlags` [in]

The combination of the following bits:

| Value | Meaning |
| --- | --- |
| **TF_IPPMF_FORPROCESS** | Deactivate this profile for all threads in the process. |
| **TF_IPPMF_FORSESSION** | Deactivate this profile for all threads in the current desktop. |
| **TF_IPPMF_DISABLEPROFILE** |  |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfInputProcessorProfileMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofilemgr)

[ITfInputProcessorProfileMgr::ActivateProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofilemgr-activateprofile)
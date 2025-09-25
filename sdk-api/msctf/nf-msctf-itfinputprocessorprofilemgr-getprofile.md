# ITfInputProcessorProfileMgr::GetProfile

## Description

The **ITfInputProcessorProfileMgr::GetProfile** method returns the information of the specified text service's profile or keyboard layout in [TF_INPUTPROCESSORPROFILE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_inputprocessorprofile) structure.

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

### `pProfile` [out]

[out] The buffer to receive [TF_INPUTPROCESSORPROFILE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_inputprocessorprofile).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
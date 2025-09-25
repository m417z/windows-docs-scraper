# ITfInputProcessorProfileMgr::RegisterProfile

## Description

The **ITfInputProcessorProfileMgr::RegisterProfile** method registers the text service and the profile.

## Parameters

### `rclsid` [in]

[in] CLSID of the text service.

### `langid` [in]

[in] The language id of the profile.

### `guidProfile` [in]

[in] The GUID to identify the profile.

### `pchDesc`

[in, size_is(cchDesc)] The description of the profile.

### `cchDesc` [in]

[in] The length of pchDesc.

### `pchIconFile`

[in, size_is(cchFile] The full path of the icon file.

### `cchFile` [in]

[in] The length of pchIconFile.

### `uIconIndex` [in]

[in] The icon index of the icon file for this profile.

### `hklsubstitute` [in]

[in] The substitute hkl of this profile.

### `dwPreferredLayout` [in]

[in] Unused. this must be 0.

### `bEnabledByDefault` [in]

[in] True if this profile is enabled by default.

### `dwFlags` [in]

[in] The combination of the following bits:

| Value | Meaning |
| --- | --- |
| **TF_RP_HIDDENINSETTINGUI** | This profile will not appear in the setting UI. |
| **TF_RP_LOCALPROCESS** | This profile is available only on the local process. |
| **TF_RP_LOCALTHREAD** | This profile is available only on the local thread. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
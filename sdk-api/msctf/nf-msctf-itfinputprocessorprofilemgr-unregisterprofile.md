# ITfInputProcessorProfileMgr::UnregisterProfile

## Description

The **ITfInputProcessorProfileMgr::UnregisterProfile** method unregisters the text service and the profile.

## Parameters

### `rclsid` [in]

[in] CLSID of the text service.

### `langid` [in]

[in] The language id of the profile.

### `guidProfile` [in]

[in] The GUID to identify the profile.

### `dwFlags` [in]

[in] The combination of the following bits:

| Value | Meaning |
| --- | --- |
| **TF_URP_ALLPROFILES** | If this bit is on, **UnregistrProfile** unregisters all profiles of the *rclsid* parameter. The *langid* and *guidProfile* parameters are ignored. |
| **TF_URP_LOCALPROCESS** | The profile was registered on the local process. |
| **TF_URP_LOCALTHREAD** | The profile was registered on the local thread. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
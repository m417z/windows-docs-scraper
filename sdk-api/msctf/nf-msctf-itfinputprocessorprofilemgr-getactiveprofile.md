# ITfInputProcessorProfileMgr::GetActiveProfile

## Description

This method returns the current active profile.

## Parameters

### `catid` [in]

[in] The category id for the profile. This must be GUID_TFCAT_TIP_KEYBOARD. Only GUID_TFCAT_TIP_KEYBOARD is supported.

### `pProfile` [out]

[out] The buffer to receive the profile information.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The profile was not found or is not active. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |
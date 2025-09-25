# DeriveAppContainerSidFromAppContainerName function

## Description

Gets the SID of the specified profile.

## Parameters

### `pszAppContainerName` [in]

The name of the profile.

### `ppsidAppContainerSid` [out]

The SID for the profile. This buffer must be freed using the [FreeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-freesid) function.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_INVALIDARG** | The *pszAppContainerName* parameter, or the *ppsidAppContainerSid* parameter is either **NULL** or not valid. |
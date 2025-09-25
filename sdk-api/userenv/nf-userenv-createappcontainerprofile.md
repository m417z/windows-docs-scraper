## Description

Creates a per-user, per-app profile for an AppContainer.

## Parameters

### `pszAppContainerName` [in]

The name of the app container. To ensure uniqueness, this string should ideally contain the app name as well as the publisher. This string can be up to 64 characters in length. Further, it must fit into the pattern described by the regular expression "[-_. A-Za-z0-9]+".

### `pszDisplayName` [in]

The display name. This string can be up to 512 characters in length.

### `pszDescription` [in]

A description for the app container. This string can be up to 2048 characters in length.

### `pCapabilities` [in]

The SIDs that define the requested UWP capabilities (if applicable).

### `dwCapabilityCount` [in]

The number of SIDs in *pCapabilities*.

### `ppSidAppContainerSid` [out]

The SID for the profile. This buffer must be freed using the [FreeSid](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-freesid) function.

## Return value

If this function succeeds, then it returns a standard HRESULT code, including the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The data store was created successfully. |
| **E_ACCESSDENIED** | The caller doesn't have permission to create the profile. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | The application data store already exists. |
| **E_INVALIDARG** | The container name is **NULL**, or the container name, the display name, or the description strings exceed their specified respective limits for length. |

## Remarks

A profile contains folders and registry storage that are per-user and per-app. The folders have ACLs that prevent them from being accessed by other users and apps. These folders can be accessed by calling [SHGetKnownFolderPath](https://learn.microsoft.com/windows/win32/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath).

The function creates a profile for the current user. To create a profile on behalf of another user, you must impersonate that user. To create profiles for multiple users of the same app, you must call **CreateAppContainerProfile** for each user.

## See also

* [DeleteAppContainerProfile](https://learn.microsoft.com/windows/win32/api/userenv/nf-userenv-deleteappcontainerprofile)
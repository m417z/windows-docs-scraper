# CreateProfile function

## Description

Creates a new user profile.

## Parameters

### `pszUserSid` [in]

Type: **LPCWSTR**

Pointer to the SID of the user as a string.

### `pszUserName` [in]

Type: **LPCWSTR**

The user name of the new user. This name is used as the base name for the profile directory.

### `pszProfilePath` [out]

Type: **LPWSTR**

When this function returns, contains a pointer to the full path of the profile.

### `cchProfilePath` [in]

Type: **DWORD**

Size of the buffer pointed to by *pszProfilePath*, in characters.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The caller does not have a sufficient permission level to create the profile. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | A profile already exists for the specified user. |

## Remarks

The caller must have administrator privileges to call this function.
# GetAppContainerRegistryLocation function

## Description

Gets the location of the registry storage associated with an app container.

## Parameters

### `desiredAccess` [in]

Type: **[REGSAM](https://learn.microsoft.com/windows/desktop/shell/messages)**

The desired registry access.

### `phAppContainerKey` [out]

Type: **PHKEY**

A pointer to an HKEY that, when this function returns successfully, receives the registry storage location for the current profile.

## Return value

Type: **HRESULT**

This function returns an **HRESULT** code, including but not limited to the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_INVALIDARG** | The caller is not running as or impersonating a user who can access this profile. |

## Remarks

The function gets the registry storage for the current user. To get the registry storage for another user, you must impersonate that user.

## See also

[GetAppContainerFolderPath](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getappcontainerfolderpath)
## Description

Registers the media extension with the given Package Family Name (PFN) for the current user.

## Parameters

### `packageFamilyName` [in]

The Package Family Name of the media extension to be registered. For more information, see [An overview of Package Identity in Windows apps](https://learn.microsoft.com/windows/apps/desktop/modernize/package-identity-overview).

## Return value

An HRESULT including the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| E_ACCESSDENIED | The API was called from a process that is not full-trust. |
| ERROR_INSTALL_FAILED | The specified Package Family Name was not found on the system. |

## Remarks

This API can be used to register media extensions that are already present in Windows but which have not yet been registered for the current user. Packages will not be automatically downloaded from the Microsoft Store. The API must be called from a full-trust process. For more information on the **Full Trust Permission Level** restricted capability. See [Restricted capability list](https://learn.microsoft.com/windows/uwp/packaging/app-capability-declarations#restricted-capability-list).

## See also
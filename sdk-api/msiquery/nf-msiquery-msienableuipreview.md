# MsiEnableUIPreview function

## Description

The
**MsiEnableUIPreview** function enables preview mode of the user interface to facilitate authoring of user-interface dialog boxes. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `hDatabase` [in]

Handle to the database.

### `phPreview` [out]

Pointer to a returned handle for user-interface preview capability.

## Return value

This function returns UINT.

## Remarks

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

## See also

[User Interface Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)
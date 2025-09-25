# GetLocalManagedApplications function

## Description

The
**GetLocalManagedApplications** function can be run on the target computer to get a list of managed applications on that computer. The function can also be called in the context of a user to get a list of managed applications for that user. This function only returns applications that can be installed by the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal).

## Parameters

### `bUserApps` [in]

A value that, if **TRUE**, the *prgLocalApps* parameter contains a list of managed applications that applies to the user. If the value of this parameter is **FALSE**, the *prgLocalApps* parameter contains a list of managed applications that applies to the local computer.

### `pdwApps` [out]

The address of a **DWORD** that specifies the number of applications in the list returned by *prgLocalApps*.

### `prgLocalApps` [out]

The address of an array that contains the list of managed applications. You must call **LocalFree** to free this array when its contents are no longer required. This parameter cannot be null. The list is returned as a [LOCALMANAGEDAPPLICATION](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-localmanagedapplication) structure.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[LOCALMANAGEDAPPLICATION](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-localmanagedapplication)
# SetupAddToSourceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupAddToSourceList** function appends a value to the list of installation sources for either the current user or the system. If the value already exists, it is removed first, so that duplicate entries are not created.

A caller of this function is required have administrative privileges, otherwise the function fails.

## Parameters

### `Flags` [in]

List to which the source will be appended. This parameter can be any combination of the following values.

#### SRCLIST_SYSTEM

Add the source to the per-system list. The caller must be an administrator.

#### SRCLIST_USER

Add the source to the per-user list.

#### SRCLIST_SYSIFADMIN

If the caller is an administrator, the source is added to the per-system list; if the caller is not a member of the administrators local group, the source is added to the per-user list for the current user.

**Note** If a temporary list is currently in use (see
[SetupSetSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetsourcelista)), the preceding flags are ignored and the source is added to the temporary list.

#### SRCLIST_APPEND

Add the source to the end of the list. If this flag is not specified, the source is added to the beginning of the list.

### `Source` [in]

Pointer to the source to be added to the list. You should use a null-terminated string.

##### - Flags.SRCLIST_APPEND

Add the source to the end of the list. If this flag is not specified, the source is added to the beginning of the list.

##### - Flags.SRCLIST_SYSIFADMIN

If the caller is an administrator, the source is added to the per-system list; if the caller is not a member of the administrators local group, the source is added to the per-user list for the current user.

##### - Flags.SRCLIST_SYSTEM

Add the source to the per-system list. The caller must be an administrator.

##### - Flags.SRCLIST_USER

Add the source to the per-user list.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupRemoveFromSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovefromsourcelista)

[SetupSetSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetsourcelista)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupAddToSourceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
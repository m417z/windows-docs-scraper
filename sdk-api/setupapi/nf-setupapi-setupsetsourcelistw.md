# SetupSetSourceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupSetSourceList** function allows the caller to set the list of installation sources for either the current user or the system (common to all users).

## Parameters

### `Flags` [in]

Specifies the type of list. This parameter can be a combination of the following values.

#### SRCLIST_SYSTEM

The list is the per-system Most Recently Used (MRU) list stored in the registry. The caller must be a member of the administrators local group.

#### SRCLIST_USER

The list is the per-user MRU list stored in the registry.

#### SRCLIST_TEMPORARY

The specified list is temporary and will be the only list accessible to the current process until
[SetupCancelTemporarySourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcanceltemporarysourcelist) is called or **SetSourceList** is called again.

**Important** If a temporary list is set, sources are not added to or deleted from the system or user lists, even if subsequent calls to
[SetupAddToSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddtosourcelista) or
[SetupRemoveFromSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovefromsourcelista) explicitly specify those lists.

**Note** One of the SRCLIST_SYSTEM, SRCLIST_USER, or SRCLIST_TEMPORARY flags must be specified.

#### SRCLIST_NOBROWSE

The user is not allowed to add or change sources when
[SetupPromptForDisk](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptfordiska) is used. This flag is typically used in combination with the SRCLIST_TEMPORARY flag.

### `SourceList` [in]

Pointer to an array of strings to use as the source list, as specified by the *Flags* parameter.

### `SourceCount` [in]

Number of elements in the array pointed to by *SourceList*.

##### - Flags.SRCLIST_NOBROWSE

The user is not allowed to add or change sources when
[SetupPromptForDisk](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptfordiska) is used. This flag is typically used in combination with the SRCLIST_TEMPORARY flag.

##### - Flags.SRCLIST_SYSTEM

The list is the per-system Most Recently Used (MRU) list stored in the registry. The caller must be a member of the administrators local group.

##### - Flags.SRCLIST_TEMPORARY

The specified list is temporary and will be the only list accessible to the current process until
[SetupCancelTemporarySourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcanceltemporarysourcelist) is called or **SetSourceList** is called again.

##### - Flags.SRCLIST_USER

The list is the per-user MRU list stored in the registry.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupAddToSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupaddtosourcelista)

[SetupCancelTemporarySourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcanceltemporarysourcelist)

[SetupRemoveFromSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovefromsourcelista)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupSetSourceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
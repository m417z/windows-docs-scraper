# SetupQuerySourceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQuerySourceList** function queries the current list of installation sources. The list is built from the system and user-specific lists, and potentially overridden by a temporary list (see
[SetupSetSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetsourcelista)).

## Parameters

### `Flags` [in]

Specifies which list to query. This parameter can be any combination of the following values.

#### SRCLIST_SYSTEM

Query the system list.

#### SRCLIST_USER

Query the per-user list.

**Note** If the system and the user lists are both retrieved, they are merged with those items in the system list that appear first.

**Note** If none of the preceding flags are specified, the entire current (merged) list is returned.

#### SRCLIST_NOSTRIPPLATFORM

Normally, all paths are stripped of a platform-specific component if it is the final component. For example, a path stored in the registry as f:\x86 is returned as f:\. If this flag is specified, the platform-specific component is not stripped.

### `List` [in, out]

Pointer to a variable in which this function returns a pointer to an array of sources. Use a null-terminated string. The caller must free this array with a call to
[SetupFreeSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfreesourcelista).

### `Count` [in, out]

Pointer to a variable in which this function returns the number of sources in the list.

##### - Flags.SRCLIST_NOSTRIPPLATFORM

Normally, all paths are stripped of a platform-specific component if it is the final component. For example, a path stored in the registry as f:\x86 is returned as f:\. If this flag is specified, the platform-specific component is not stripped.

##### - Flags.SRCLIST_SYSTEM

Query the system list.

##### - Flags.SRCLIST_USER

Query the per-user list.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupSetSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetsourcelista)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupQuerySourceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
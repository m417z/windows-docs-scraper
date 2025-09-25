# PathUnmakeSystemFolderW function

## Description

Removes the attributes from a folder that make it a system folder. This folder must actually exist in the file system.

## Parameters

### `pszPath` [in]

Type: **LPTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the name of an existing folder that will have the system folder attributes removed.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathUnmakeSystemFolder as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
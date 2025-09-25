# PathIsNetworkPathA function

## Description

Determines whether a path string represents a network resource.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path.

## Return value

Type: **BOOL**

Returns **TRUE** if the string represents a network resource, or **FALSE** otherwise.

## Remarks

**PathIsNetworkPath** interprets the following two types of paths as network paths.

* Paths that begin with two backslash characters (\\) are interpreted as Universal Naming Convention (UNC) paths.
* Paths that begin with a letter followed by a colon (:) are interpreted as a mounted network drive. However, **PathIsNetworkPath** cannot recognize a network drive mapped to a drive letter through the Microsoft MS-DOS SUBST command or the [DefineDosDevice](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-definedosdevicew) function.

**Note** The function does not verify that the specified network resource exists, is currently accessible, or that the user has sufficient permissions to access it.

> [!NOTE]
> The shlwapi.h header defines PathIsNetworkPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
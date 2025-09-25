# PathSkipRootA function

## Description

Retrieves a pointer to the first character in a path following the drive letter or Universal Naming Convention (UNC) server/share path elements.

## Parameters

### `pszPath` [in]

Type: **PTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to parse.

## Return value

Type: **PTSTR**

A pointer that, when this function returns successfully, points to the beginning of the subpath that follows the root (drive letter or UNC server/share). If the function encounters an error, this value will be **NULL**.

## See also

[PathCchSkipRoot](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchskiproot)

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathSkipRoot as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
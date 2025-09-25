# PathFindExtensionW function

## Description

Searches a path for an extension.

## Parameters

### `pszPath` [in]

Type: **PTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search, including the extension being searched for.

## Return value

Type: **PTSTR**

Returns the address of the "." that precedes the extension within *pszPath* if an extension is found, or the address of the terminating null character otherwise.

## Remarks

Note that a valid file name extension cannot contain a space. For more information on valid file name extensions, see [File Type Handlers](https://learn.microsoft.com/windows/desktop/shell/fa-file-extensions).

> [!NOTE]
> The shlwapi.h header defines PathFindExtension as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
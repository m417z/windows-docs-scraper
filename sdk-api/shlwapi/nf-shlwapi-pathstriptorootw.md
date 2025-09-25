# PathStripToRootW function

## Description

Removes all file and directory elements in a path except for the root information.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchStripToRoot](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchstriptoroot) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path to be converted. When this function returns successfully, this string contains only the root information taken from that path.

## Return value

Type: **BOOL**

Returns **TRUE** if a valid drive letter was found in the path, or **FALSE** otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathStripToRoot as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
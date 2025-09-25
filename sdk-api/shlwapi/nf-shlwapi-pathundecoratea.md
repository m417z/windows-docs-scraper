# PathUndecorateA function

## Description

Removes the decoration from a path string.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A null-terminated string of length MAX_PATH that contains the path. When the function returns, *pszPath* points to the undecorated string.

## Remarks

A decoration consists of a pair of square brackets with one or more digits in between, inserted immediately after the base name and before the file name extension.

#### Examples

The following table illustrates how strings are modified by **PathUndecorate**.

| Initial String | Undecorated String |
| --- | --- |
| C:\Path\File[5].txt | C:\Path\File.txt |
| C:\Path\File[12] | C:\Path\File |
| C:\Path\File.txt | C:\Path\File.txt |
| C:\Path\[3].txt | C:\Path\[3].txt |

> [!NOTE]
> The shlwapi.h header defines PathUndecorate as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
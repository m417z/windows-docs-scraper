# PathCombineW function

## Description

Concatenates two strings that represent properly formed paths into one path; also concatenates any relative path elements.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine) or [PathCchCombineEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombineex) function in its place.

## Parameters

### `pszDest` [out]

Type: **LPTSTR**

A pointer to a buffer that, when this function returns successfully, receives the combined path string. You must set the size of this buffer to MAX_PATH to ensure that it is large enough to hold the returned string.

### `pszDir` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the first path. This value can be **NULL**.

### `pszFile` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the second path. This value can be **NULL**.

## Return value

Type: **LPTSTR**

A pointer to a buffer that, when this function returns successfully, receives the concatenated path string. This is the same string pointed to by *pszPathOut*. If this function does not return successfully, this value is **NULL**.

## Remarks

The directory path should be in the form of A:,B:, ..., Z:. The file path should be in a correct form that represents the file name part of the path. If the directory path ends with a backslash, the backslash will be maintained. Note that while *lpszDir* and *lpszFile* are both optional parameters, they cannot both be **NULL**.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

int main( void )
{
// Buffer to hold combined path.
char buffer_1[MAX_PATH] = "";
char *lpStr1;
lpStr1 = buffer_1;

// String for balance of path name.
char buffer_2[ ] = "One\\Two\\Three";
char *lpStr2;
lpStr2 = buffer_2;

// String for directory name.
char buffer_3[ ] = "C:";
char *lpStr3;
lpStr3 = buffer_3;

cout << "The file path to be combined is  "
     << lpStr2 << endl;
cout << "The directory name path is       "
     << lpStr3 << endl;
cout << "The combined path is             "
     << PathCombine(lpStr1,lpStr3,lpStr2) << endl;
}

------------
INPUT:
------------
Path for directory part: "C:"
Path for file part: "One\Two\Three"
------------
OUTPUT:
------------
The file path to be combined is  One\Two\Three
The directory name path is       C:
The combined path is             C:\One\Two\Three
```

> [!NOTE]
> The shlwapi.h header defines PathCombine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
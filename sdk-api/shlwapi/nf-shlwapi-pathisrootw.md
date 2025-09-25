# PathIsRootW function

## Description

Determines whether a path string refers to the root of a volume.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be validated.

## Return value

Type: **BOOL**

Returns **TRUE** if the specified path is a root, or **FALSE** otherwise.

## Remarks

Returns **TRUE** for paths such as "\", "*X*:\" or "\\*server*\*share*". Paths such as "..\path2" or "\\*server*\" return **FALSE**.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
// String path name 1.
char buffer_1[ ] = "C:\\";
char *lpStr1;
lpStr1 = buffer_1;

// String path name 2.
char buffer_2[ ] = "path\\file";
char *lpStr2;
lpStr2 = buffer_2;

// Variable to get the return from "PathIsRoot".
int retval;

// Test case with path not absolute.
retval = PathIsRoot(lpStr1);
cout << "The return from function is       :" << retval << endl;
cout << "The path does contain a root part :" << lpStr1 << endl;

// Test case with path absolute.
retval = PathIsRoot(lpStr2);
cout << "The return from function is       :" << retval << endl;
cout << "The path does not contain part    :" << lpStr2 << endl;
}

OUTPUT:
============
The return from function is       :1
The path does contain a root part :C:\
The return from function is       :0
The path does not contain part    :path\file
============
```

> [!NOTE]
> The shlwapi.h header defines PathIsRoot as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
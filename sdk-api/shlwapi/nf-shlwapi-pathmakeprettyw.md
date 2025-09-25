# PathMakePrettyW function

## Description

Converts an all-uppercase path to all lowercase characters to give the path a consistent appearance.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path to be converted.

## Return value

Type: **BOOL**

Returns **TRUE** if the path has been converted, or **FALSE** otherwise.

## Remarks

This function only operates on paths that are entirely uppercase. For example: C:\WINDOWS will be converted to c:\windows, but c:\Windows will not be changed.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
// Path name 1.
char buffer_1[ ] = "C:\\TEST\\FILE";
char *lpStr1;
lpStr1 = buffer_1;

// Path name 2.
char buffer_2[ ] = "c:\\test\\file";
char *lpStr2;
lpStr2 = buffer_2;

// Test path name 1.
    cout << "The content of the unconverted path is : " << lpStr1 << endl;
    cout << "The \"PathMakePretty\" function returns the value "
         << PathMakePretty(lpStr1) << "  = TRUE & converts"  << endl;
    cout << "The content of the converted path is   : " << lpStr1 << endl;

// Test path name 2.
    cout << "\nThe content of the unconverted path is : " << lpStr2 << endl;
    cout << "The \"PathMakePretty\" function returns the value "
         << PathMakePretty(lpStr2) << "  = FALSE & no conversion"  << endl;
    cout << "The content of the converted path is   : " << lpStr2 << endl;
}

OUTPUT:
=============
The content of the unconverted path is : C:\TEST\FILE
The "PathMakePretty" function returns the value 1  = TRUE & converts
The content of the converted path is   : C:\test\file

The content of the unconverted path is : c:\test\file
The "PathMakePretty" function returns the value 0  = FALSE & no conversion
The content of the converted path is   : c:\test\file
```

> [!NOTE]
> The shlwapi.h header defines PathMakePretty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
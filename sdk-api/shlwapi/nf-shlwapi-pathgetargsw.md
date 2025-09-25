# PathGetArgsW function

## Description

Finds the command line arguments within a given path.

## Parameters

### `pszPath` [in]

Type: **PTSTR**

Pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be searched.

## Return value

Type: **PTSTR**

Returns a pointer to a null-terminated string that contains the arguments portion of the path if successful.

If there are no arguments in the path, the function returns a pointer to the end of the input string.

If the function is given a **NULL** argument it returns **NULL**.

## Remarks

This function should not be used on generic command path templates (from users or the registry), but rather should be used only on templates that the application knows to be well formed.

#### Examples

```cpp

#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
    // Path_1 to search for file arguments (2 arguments):
    char buffer_1[ ] = "test.exe temp.txt sample.doc";
    char *lpStr1;
    lpStr1 = buffer_1;

    // Path_2 to search for file arguments (3 arguments):
    char buffer_2[ ] = "test.exe 1 2 3";
    char *lpStr2;
    lpStr2 = buffer_2;

    // Path_3 to search for file arguments (3 arguments):
    char buffer_3[ ] = "test.exe sample All 15";
    char *lpStr3;
    lpStr3 = buffer_3;

    // Path_4 to search for file arguments (no arguments):
    char buffer_4[ ] = "test.exe";
    char *lpStr4;
    lpStr4 = buffer_4;

    cout << "The path passed to the function was : " << lpStr1 <<
            "\nThe arg(s)found in path 1 were      : " << PathGetArgs(lpStr1) << endl;

    cout << "\nThe path passed to the function was : " << lpStr2 <<
            "\nThe arg(s)found in path 2 were      : " << PathGetArgs(lpStr2) << endl;

    cout << "\nThe path passed to the function was : " << lpStr3 <<
            "\nThe arg(s)found in path 3 were      : " << PathGetArgs(lpStr3) << endl;

    cout << "\nThe path passed to the function was : " << lpStr4 <<
            "\nThe arg(s)found in path 4 were      : " << PathGetArgs(lpStr4) << endl;
}

OUTPUT:
===========
The path passed to the function was : test.exe temp.txt sample.doc
The arg(s)found in path 1 were      : temp.txt sample.doc

The path passed to the function was : test.exe 1 2 3
The arg(s)found in path 2 were      : 1 2 3

The path passed to the function was : test.exe sample All 15
The arg(s)found in path 3 were      : sample All 15

The path passed to the function was : test.exe
The arg(s)found in path 4 were      :
===========
```

> [!NOTE]
> The shlwapi.h header defines PathGetArgs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
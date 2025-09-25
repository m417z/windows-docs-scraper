# PathRemoveArgsW function

## Description

Removes any arguments from a given path.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

Pointer to a null-terminated string of length MAX_PATH that contains the path from which to remove arguments.

## Remarks

This function should not be used on generic command path templates (from users or the registry), but rather it should be used only on templates that the application knows to be well formed.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
    // Path with arguments.
    char buffer_1[ ] = "c:\\a\\b\\FileA Arg1 Arg2";
    char *lpStr1;
    lpStr1 = buffer_1;

    // Path before "PathRemoveArgs".
    cout << "Path before calling \"PathRemoveArgs\": " << lpStr1 << endl;

    // Call function "PathRemoveArgs".
    PathRemoveArgs(lpStr1);

    // Path after "PathRemoveArgs".
    cout << "Path after calling \"PathRemoveArgs\": " << lpStr1 << endl;
}

OUTPUT:
==================
Path before calling "PathRemoveArgs": c:\a\b\FileA Arg1 Arg2
Path after calling "PathRemoveArgs": c:\a\b\FileA
```

> [!NOTE]
> The shlwapi.h header defines PathRemoveArgs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
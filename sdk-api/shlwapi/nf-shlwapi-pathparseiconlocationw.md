# PathParseIconLocationW function

## Description

Parses a file location string that contains a file location and icon index, and returns separate values.

## Parameters

### `pszIconFile` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains a file location string. It should be in the form "*path*,*iconindex*". When the function returns, *pszIconFile* will point to the file's path.

## Return value

Type: **int**

Returns the valid icon index value.

## Remarks

This function is useful for taking a DefaultIcon value retrieved from the registry by [SHGetValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shgetvaluea) and separating the icon index from the path.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main(void)
{
// Path to parse for file and icon index.
char buffer_1[ ] = "C:\\TEST\\sample.txt,3";
char *lpStr1;
lpStr1 = buffer_1;

// Return value from "PathParseIconLocation".
int retval;

// Search a path to parse for file and icon index.
retval = PathParseIconLocation(lpStr1);
cout << "The path to parse for file and icon index is   : " << lpStr1 << endl;
cout << "PathParseIconLocation returns the icon index of: " << retval << endl;
}

OUTPUT:
==========
The path to parse for file and icon index is   : C:\TEST\sample.txt
PathParseIconLocation returns the icon index of: 3
```

> [!NOTE]
> The shlwapi.h header defines PathParseIconLocation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
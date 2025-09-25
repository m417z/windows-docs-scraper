# PathIsURLW function

## Description

Tests a given string to determine if it conforms to a valid URL format.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the URL path to validate.

## Return value

Type: **BOOL**

Returns **TRUE** if *pszPath* has a valid URL format, or **FALSE** otherwise.

## Remarks

This function does not verify that the path points to an existing site—only that it has a valid URL format.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
// String path name 1.
char buffer_1[ ] = "http://www.microsoft.com/software/index.html";
char *lpStr1;
lpStr1 = buffer_1;

// String path name 2.
char buffer_2[ ] = "http://www.microsoft.com";
char *lpStr2;
lpStr2 = buffer_2;

// String path name 3.
char buffer_3[ ] = "microsoft.com";
char *lpStr3;
lpStr3 = buffer_3;

// Variable to get the return
// from "PathIsURL".
int retval;

// Test path name 1.
retval = PathIsURL(lpStr1);
cout << "The contents of String 1: " << lpStr1
     << "\nThe return value from the function is " << retval << " = TRUE" << endl;

// Test path name 2.
retval = PathIsURL(lpStr2);
cout << "The contents of String 2: " << lpStr2
     << "\nThe return value from the function is " << retval << " = TRUE" << endl;

// Test path name 3.
retval = PathIsURL(lpStr3);
cout << "The contents of String 3: " << lpStr3
     << "\nThe return value from the function is " << retval << " = FALSE"<< endl;
}

OUTPUT:
=============
The contents of String 1: http://www.microsoft.com/software/index.html
The return value from the function is 1 = TRUE
The contents of String 2: http://www.microsoft.com
The return value from the function is 1 = TRUE
The contents of String 3: microsoft.com
The return value from the function is 0 = FALSE
```

> [!NOTE]
> The shlwapi.h header defines PathIsURL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
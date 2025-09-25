# PathAppendA function

## Description

Appends one path to the end of another.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchAppend](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappend) or [PathCchAppendEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappendex) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string to which the path specified in *pszMore* is appended. You must set the size of this buffer to MAX_PATH to ensure that it is large enough to hold the returned string.

### `pszMore` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be appended.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

This function automatically inserts a backslash between the two strings, if one is not already present.

The path supplied in *pszPath* cannot begin with "..\\" or ".\\" to produce a relative path string. If present, those periods are stripped from the output string. For example, appending "path3" to "..\\path1\\path2" results in an output of "\path1\path2\path3" rather than "..\path1\path2\path3".

#### Examples

```cpp

#include <windows.h>
#include <iostream>
#include "Shlwapi.h"

using namespace std;

int main( void )
{
	// String for path name.
	char buffer_1[MAX_PATH] = "name_1\\name_2";
	char *lpStr1;
	lpStr1 = buffer_1;

	// String of what is being added.
	char buffer_2[ ] = "name_3";
	char *lpStr2;
	lpStr2 = buffer_2;

	cout << "The original path string is    " << lpStr1 << endl;
	cout << "The part to append to end is   " << lpStr2 << endl;
	bool ret = PathAppend(lpStr1,lpStr2);
	cout << "The appended path string is    " << lpStr1 << endl;
}

OUTPUT:
---------
The original path string is    name_1\name_2
The part to append to end is   name_3
The appended path string is    name_1\name_2\name_3
```

> [!NOTE]
> The shlwapi.h header defines PathAppend as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
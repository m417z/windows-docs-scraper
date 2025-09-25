# PathCanonicalizeW function

## Description

Simplifies a path by removing navigation elements such as "." and ".." to produce a direct, well-formed path.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalize) or [PathCchCanonicalizeEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalizeex) function in its place.

## Parameters

### `pszBuf` [out]

Type: **LPTSTR**

A pointer to a string that receives the canonicalized path. You must set the size of this buffer to MAX_PATH to ensure that it is large enough to hold the returned string.

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be canonicalized.

## Return value

Type: **BOOL**

Returns **TRUE** if a result has been computed and the content of the *lpszDst* output buffer is valid. Returns **FALSE** otherwise, and the contents of the buffer pointed to by *lpszDst* are invalid. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function allows the user to specify what to remove from a path by inserting special character sequences into the path. The ".." sequence indicates to remove a path segment from the current position to the previous path segment. The "." sequence indicates to skip over the next path segment to the following path segment. The root segment of the path cannot be removed.

If there are more ".." sequences than there are path segments, the function returns **TRUE** and contents of the buffer pointed to by *lpszDst* contains just the root, "\".

#### Examples

```cpp

#include <windows.h>
#include <iostream>
#include "Shlwapi.h"

using namespace std;

int main( void )
{
// Path_1 destination buffer.
char buffer_1[MAX_PATH] = "JustABufferToHoldTheCanonicalizedPathForAnExample";
char *lpStr1;
lpStr1 = buffer_1;

// Path_2 to be Canonicalized.
char buffer_2[ ] = "A:\\name_1\\.\\name_2\\..\\name_3";
char *lpStr2;
lpStr2 = buffer_2;

// Path_3 to be Canonicalized.
char buffer_3[ ] = "A:\\name_1\\..\\name_2\\.\\name_3";
char *lpStr3;
lpStr3 = buffer_3;

// Path_4 to be Canonicalized.
char buffer_4[ ] = "A:\\name_1\\name_2\\.\\name_3\\..\\name_4";
char *lpStr4;
lpStr4 = buffer_4;

// Path_5 to be Canonicalized.
char buffer_5[ ] = "A:\\name_1\\.\\name_2\\.\\name_3\\..\\name_4\\..";
char *lpStr5;
lpStr5 = buffer_5;

// Path_6 to be Canonicalized.
char buffer_6[ ] = "C:\\..";
char *lpStr6;
lpStr6 = buffer_6;

cout << "The un-canonicalized path 2 is : " << lpStr2
     << "\nThe return value is            : "
     << PathCanonicalize(lpStr1,lpStr2)
     << "\nThe canonicalized path 1 is    : " << lpStr1 << endl;

cout << "\nThe un-canonicalized path 3 is : " << lpStr3
     << "\nThe return value is            : "
     << PathCanonicalize(lpStr1,lpStr3)
     << "\nThe canonicalized path 1 is    : " << lpStr1 << endl;

cout << "\nThe un-canonicalized path 4 is : " << lpStr4
     << "\nThe return value is            : "
     << PathCanonicalize(lpStr1,lpStr4)
     << "\nThe canonicalized path 1 is    : " << lpStr1 << endl;

cout << "\nThe un-canonicalized path 5 is : " << lpStr5
     << "\nThe return value is            : "
     << PathCanonicalize(lpStr1,lpStr5)
     << "\nThe canonicalized path 1 is    : " << lpStr1 << endl;

cout << "\nThe un-canonicalized path 6 is : " << lpStr6
     << "\nThe return value is            : "
     << PathCanonicalize(lpStr1,lpStr6)
     << "\nThe canonicalized path 1 is    : " << lpStr1 << endl;
}
OUTPUT:
---------
The un-canonicalized path 2 is : A:\name_1\.\name_2\..\name_3
The return value is            : 1
The canonicalized path 1 is    : A:\name_1\name_3

The un-canonicalized path 3 is : A:\name_1\..\name_2\.\name_3
The return value is            : 1
The canonicalized path 1 is    : A:\name_2\name_3

The un-canonicalized path 4 is : A:\name_1\name_2\.\name_3\..\name_4
The return value is            : 1
The canonicalized path 1 is    : A:\name_1\name_2\name_4

The un-canonicalized path 5 is : A:\name_1\.\name_2\.\name_3\..\name_4\..
The return value is            : 1
The canonicalized path 1 is    : A:\name_1\name_2

The un-canonicalized path 6 is : C:\..
The return value is            : 1
The canonicalized path 1 is    : C:\
```

> [!NOTE]
> The shlwapi.h header defines PathCanonicalize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
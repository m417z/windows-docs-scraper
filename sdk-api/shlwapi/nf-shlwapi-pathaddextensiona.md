# PathAddExtensionA function

## Description

Adds a file name extension to a path string.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchAddExtension](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddextension) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a buffer with the null-terminated string to which the file name extension will be appended. You must set the size of this buffer to MAX_PATH to ensure that it is large enough to hold the returned string.

### `pszExt` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the file name extension. This value can be **NULL**.

## Return value

Type: **BOOL**

Returns **TRUE** if an extension was added, or **FALSE** otherwise.

## Remarks

If there is already a file name extension present, no extension will be added. If the *pszPath* points to a **NULL** string, the result will be the file name extension only. If *pszExtension* points to a **NULL** string, an ".exe" extension will be added.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
     // String for path name without file name extension.
     char buffer_1[MAX_PATH] = "file";
     char *lpStr1;
     lpStr1 = buffer_1;

     // String for path name with file name extension.
     char buffer_2[ ] = "file.doc";
     char *lpStr2;
     lpStr2 = buffer_2;

     // String for extension name.
     char F_Ext[MAX_PATH] = ".txt";
     char *lpStr3;
     lpStr3 = F_Ext;

     // Null string as path.
     char N_String[MAX_PATH] = "\0";
     char *lpStr4;
     lpStr4 = N_String;

     // Path 1 without the file name extension.
     cout << "The original path string 1 is  " << lpStr1 << endl;

     int ret_1 = PathAddExtension(lpStr1,lpStr3);
     cout << "The modified path string 1 is  " << lpStr1 << endl;

    // Path 2 with the file name extension already there.
    cout << "The original path string 2 is  " << lpStr2 << endl;
    int ret_2 = PathAddExtension(lpStr2,lpStr3);
    cout << "The modified path string 2 is  " << lpStr2<< endl;

    // Path 3 null string as a path.
    int ret_3 = PathAddExtension(lpStr4,lpStr3);
    cout << "The return value is " << ret_3<< endl;
    cout << "The modified path on a null string is " << lpStr4<< endl;

}

OUTPUT:
-----------------------
The original path string 1 is  file
The modified path string 1 is  file.txt
The original path string 2 is  file.doc
The modified path string 2 is  file.doc
The return value is 1
The modified path on a null string is .txt
The return value is 1
```

> [!NOTE]
> The shlwapi.h header defines PathAddExtension as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
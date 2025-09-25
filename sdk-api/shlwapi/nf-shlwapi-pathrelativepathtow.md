# PathRelativePathToW function

## Description

Creates a relative path from one file or folder to another.

## Parameters

### `pszPath` [out]

Type: **LPTSTR**

A pointer to a string that receives the relative path. This buffer must be at least MAX_PATH characters in size.

### `pszFrom` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path that defines the start of the relative path.

### `dwAttrFrom` [in]

Type: **DWORD**

The file attributes of *pszFrom*. If this value contains FILE_ATTRIBUTE_DIRECTORY, *pszFrom* is assumed to be a directory; otherwise, *pszFrom* is assumed to be a file.

### `pszTo` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path that defines the endpoint of the relative path.

### `dwAttrTo` [in]

Type: **DWORD**

The file attributes of *pszTo*. If this value contains FILE_ATTRIBUTE_DIRECTORY, *pszTo* is assumed to be directory; otherwise, *pszTo* is assumed to be a file.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

This function takes a pair of paths and generates a relative path from one to the other. The paths do not have to be fully qualified, but they must have a common prefix, or the function will fail and return **FALSE**.

For example, let the starting point, *pszFrom*, be "c:\FolderA\FolderB\FolderC", and the ending point, *pszTo*, be "c:\FolderA\FolderD\FolderE". **PathRelativePathTo** will return the relative path from *pszFrom* to *pszTo* as: "..\..\FolderD\FolderE". You will get the same result if you set *pszFrom* to "\FolderA\FolderB\FolderC" and *pszTo* to "\FolderA\FolderD\FolderE". On the other hand, "c:\FolderA\FolderB" and "a:\FolderA\FolderD do not share a common prefix, and the function will fail. Note that "\\" is not considered a prefix and is ignored. If you set *pszFrom* to "\\FolderA\FolderB", and *pszTo* to "\\FolderC\FolderD", the function will fail.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main(void)
{
    char szOut[MAX_PATH] = "";
    char szFrom[ ] = "c:\\a\\b\\path";
    char szTo[ ] = "c:\\a\\x\\y\\file";

    cout  <<  "The relative path is relative from: ";
    cout  <<  szFrom;
    cout  <<  "\n";

    cout  <<  "The relative path is relative to: ";
    cout  <<  szTo;
    cout  <<  "\n";

    PathRelativePathTo(szOut,
                       szFrom,
                       FILE_ATTRIBUTE_DIRECTORY,
                       szTo,
                       FILE_ATTRIBUTE_NORMAL);

    cout  <<  "The relative path is: ";
    cout  <<  szOut;
    cout  <<  "\n";
}

OUTPUT:
==================
The relative path is relative from: c:\a\b\path
The relative path is relative to: c:\a\x\y\file
The relative path is: ..\..\x\y\file
```

> [!NOTE]
> The shlwapi.h header defines PathRelativePathTo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
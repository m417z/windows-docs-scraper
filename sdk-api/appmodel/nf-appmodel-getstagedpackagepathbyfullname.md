# GetStagedPackagePathByFullName function

## Description

Gets the path of the specified staged package.

## Parameters

### `packageFullName` [in]

Type: **PCWSTR**

The full name of the staged package.

### `pathLength` [in, out]

Type: **UINT32***

A pointer to a variable that holds the number of characters (**WCHAR**s) in the package path string, which includes the null-terminator.

First you pass **NULL** to *path* to get the number of characters. You use this number to allocate memory space for *path*. Then you pass the address of this memory space to fill *path*.

### `path` [out, optional]

Type: **PWSTR**

A pointer to memory space that receives the package path string, which includes the null-terminator.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer specified by *path* is not large enough to hold the data. The required size is specified by *pathLength*. |

## Remarks

This function succeeds if the package is staged, regardless of the user context or if the package is registered for the current user.

## Examples

```cpp
#define _UNICODE 1
#define UNICODE 1

#include <Windows.h>
#include <appmodel.h>
#include <stdlib.h>
#include <stdio.h>

int ShowUsage();

int ShowUsage()
{
    wprintf(L"Usage: GetStagedPackagePathByFullName <fullname> [<fullname>...]\n");
    return 1;
}

int __cdecl wmain(__in int argc, __in_ecount(argc) WCHAR * argv[])
{
    if (argc <= 1)
        return ShowUsage();

    for (int i=1; i<argc; ++i)
    {
        PCWSTR fullName = argv[i];
        UINT32 length = 0;
        LONG rc = GetStagedPackagePathByFullName(fullName, &length, NULL);
        if (rc != ERROR_INSUFFICIENT_BUFFER)
        {
            wprintf(L"Error %d in GetStagedPackagePathByFullName\n", rc);
            return 2;
        }

        PWSTR path = (PWSTR) malloc(length * sizeof(WCHAR));
        if (path == NULL)
        {
            wprintf(L"Error allocating memory\n");
            return 3;
        }

        rc = GetStagedPackagePathByFullName(fullName, &length, path);
        if (rc != ERROR_SUCCESS)
            wprintf(L"Error %d retrieving Package's path\n", rc);
        else
            wprintf(L"Path = %s\n", path);

        free(path);
    }

    return 0;
}

```

## See also

[GetStagedPackagePathByFullName2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getstagedpackagepathbyfullname2)